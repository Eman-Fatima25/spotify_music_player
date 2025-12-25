// Global variables
let currentAudio = null;
let allSongs = [];

// Initialize app when DOM is loaded
document.addEventListener('DOMContentLoaded', () => {
    console.log('Spotify Music Player initialized');
    loadSongs();
    loadRecentlyPlayed();
});

// API Base URL
const API_URL = '';

// Load all songs from server
async function loadSongs() {
    try {
        const response = await fetch(`${API_URL}/api/songs`);
        const songs = await response.json();
        allSongs = songs;
        displaySongs(songs);
    } catch (error) {
        console.error('Error loading songs:', error);
        showNotification('Failed to load songs', 'error');
    }
}

// Display songs in the UI
function displaySongs(songs) {
    const songsList = document.getElementById('songsList');
    const songCount = document.getElementById('songCount');

    songCount.textContent = `${songs.length} song${songs.length !== 1 ? 's' : ''}`;

    if (songs.length === 0) {
        songsList.innerHTML = '<div class="empty-state"><p>No songs yet. Add your first song!</p></div>';
        return;
    }

    songsList.innerHTML = songs.map(song => `
        <div class="song-item" data-id="${song.id}" data-name="${escapeHtml(song.name)}" data-artist="${escapeHtml(song.artist)}" data-path="${song.file_path}">
            <div class="song-info">
                <div class="song-name">${escapeHtml(song.name)}</div>
                <div class="song-artist">🎤 ${escapeHtml(song.artist)}</div>
                <div class="song-meta">
                    <span class="meta-badge">🎵 ${escapeHtml(song.genre || 'Unknown')}</span>
                    <span class="meta-badge">▶️ ${song.play_count} plays</span>
                </div>
            </div>
            <div class="song-actions">
                <button class="btn-action btn-play" data-action="play">
                    ▶️ Play
                </button>
                <button class="btn-action btn-delete" data-action="delete">
                    🗑️
                </button>
            </div>
        </div>
    `).join('');

    // Add event listeners for play and delete buttons
    songsList.querySelectorAll('.song-item').forEach(item => {
        const songId = parseInt(item.dataset.id);
        const songName = item.dataset.name;
        const artistName = item.dataset.artist;
        const filePath = item.dataset.path;

        item.querySelector('[data-action="play"]').addEventListener('click', () => {
            playSong(songId, songName, artistName, filePath);
        });

        item.querySelector('[data-action="delete"]').addEventListener('click', () => {
            deleteSong(songId);
        });
    });
}

// Add a new song
async function addSong() {
    const nameInput = document.getElementById('songName');
    const artistInput = document.getElementById('artistName');
    const genreInput = document.getElementById('genreName');

    const name = nameInput.value.trim();
    const artist = artistInput.value.trim();
    const genre = genreInput.value.trim() || 'Unknown';

    if (!name) {
        showNotification('Please enter a song name', 'error');
        return;
    }

    if (!artist) {
        showNotification('Please enter an artist name', 'error');
        return;
    }

    try {
        const response = await fetch(`${API_URL}/api/songs`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                name: name,
                artist: artist,
                genre: genre,
                file_path: `/music/${name.replace(/[^a-zA-Z0-9]/g, '')}.mp3`
            })
        });

        if (response.ok) {
            showNotification('Song added successfully!', 'success');
            nameInput.value = '';
            artistInput.value = '';
            genreInput.value = '';
            loadSongs();
        } else {
            showNotification('Failed to add song', 'error');
        }
    } catch (error) {
        console.error('Error adding song:', error);
        showNotification('Failed to add song', 'error');
    }
}

// Delete a song
async function deleteSong(songId) {
    if (!confirm('Are you sure you want to delete this song?')) {
        return;
    }

    try {
        const response = await fetch(`${API_URL}/api/songs/${songId}`, {
            method: 'DELETE'
        });

        if (response.ok) {
            showNotification('Song deleted successfully!', 'success');
            loadSongs();
            loadRecentlyPlayed();
        } else {
            showNotification('Failed to delete song', 'error');
        }
    } catch (error) {
        console.error('Error deleting song:', error);
        showNotification('Failed to delete song', 'error');
    }
}

// Play a song
async function playSong(songId, songName, artistName, filePath) {
    try {
        // Update play count and recently played on server
        const response = await fetch(`${API_URL}/api/songs/${songId}/play`, {
            method: 'POST'
        });

        if (!response.ok) {
            showNotification('Failed to play song', 'error');
            return;
        }

        // Update UI
        const audioPlayer = document.getElementById('audioPlayer');
        const audioElement = document.getElementById('audioElement');
        const nowPlayingSong = document.getElementById('nowPlayingSong');
        const nowPlayingArtist = document.getElementById('nowPlayingArtist');

        nowPlayingSong.textContent = songName;
        nowPlayingArtist.textContent = artistName;

        // Set audio source
        audioElement.src = filePath;
        audioElement.play();

        // Show player
        audioPlayer.style.display = 'flex';

        // Reload data
        loadSongs();
        loadRecentlyPlayed();

        showNotification(`Now playing: ${songName}`, 'success');
    } catch (error) {
        console.error('Error playing song:', error);
        showNotification('Failed to play song', 'error');
    }
}

// Toggle play/pause
function togglePlayPause() {
    const audioElement = document.getElementById('audioElement');

    if (audioElement.paused) {
        audioElement.play();
    } else {
        audioElement.pause();
    }
}

// Stop music
function stopMusic() {
    const audioElement = document.getElementById('audioElement');
    const audioPlayer = document.getElementById('audioPlayer');

    audioElement.pause();
    audioElement.currentTime = 0;
    audioPlayer.style.display = 'none';
}

// Search songs
async function searchSongs() {
    const searchInput = document.getElementById('searchInput');
    const query = searchInput.value.trim();

    if (!query) {
        displaySongs(allSongs);
        return;
    }

    try {
        const response = await fetch(`${API_URL}/api/songs/search?q=${encodeURIComponent(query)}`);
        const songs = await response.json();
        displaySongs(songs);

        if (songs.length === 0) {
            showNotification('No songs found', 'info');
        }
    } catch (error) {
        console.error('Error searching songs:', error);
        showNotification('Search failed', 'error');
    }
}

// Clear search
function clearSearch() {
    const searchInput = document.getElementById('searchInput');
    searchInput.value = '';
    displaySongs(allSongs);
}

// Sort songs
async function sortSongs(sortBy) {
    try {
        const response = await fetch(`${API_URL}/api/songs/sort`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                algorithm: 'bubble',
                sort_by: sortBy
            })
        });

        const songs = await response.json();
        displaySongs(songs);

        const sortType = sortBy === 'name' ? 'alphabetically' : 'by play count';
        showNotification(`Songs sorted ${sortType}`, 'success');
    } catch (error) {
        console.error('Error sorting songs:', error);
        showNotification('Sort failed', 'error');
    }
}

// Load recently played songs
async function loadRecentlyPlayed() {
    try {
        const response = await fetch(`${API_URL}/api/recent`);
        const songs = await response.json();
        displayRecentlyPlayed(songs);
    } catch (error) {
        console.error('Error loading recently played:', error);
    }
}

// Display recently played songs
function displayRecentlyPlayed(songs) {
    const recentList = document.getElementById('recentList');

    if (songs.length === 0) {
        recentList.innerHTML = '<div class="empty-state"><p>No recently played songs</p></div>';
        return;
    }

    recentList.innerHTML = songs.map((song, index) => `
        <div class="song-item" data-id="${song.id}" data-name="${escapeHtml(song.name)}" data-artist="${escapeHtml(song.artist)}" data-path="${song.file_path}">
            <div class="song-info">
                <div class="song-name">${index + 1}. ${escapeHtml(song.name)}</div>
                <div class="song-artist">🎤 ${escapeHtml(song.artist)}</div>
                <div class="song-meta">
                    <span class="meta-badge">▶️ ${song.play_count} plays</span>
                </div>
            </div>
            <div class="song-actions">
                <button class="btn-action btn-play" data-action="play">
                    ▶️ Play
                </button>
            </div>
        </div>
    `).join('');

    // Add event listeners for play buttons
    recentList.querySelectorAll('.song-item').forEach(item => {
        const songId = parseInt(item.dataset.id);
        const songName = item.dataset.name;
        const artistName = item.dataset.artist;
        const filePath = item.dataset.path;

        item.querySelector('[data-action="play"]').addEventListener('click', () => {
            playSong(songId, songName, artistName, filePath);
        });
    });
}

// Clear recently played
async function clearRecentlyPlayed() {
    if (!confirm('Are you sure you want to clear recently played?')) {
        return;
    }

    try {
        const response = await fetch(`${API_URL}/api/recent`, {
            method: 'DELETE'
        });

        if (response.ok) {
            showNotification('Recently played cleared!', 'success');
            loadRecentlyPlayed();
        } else {
            showNotification('Failed to clear recently played', 'error');
        }
    } catch (error) {
        console.error('Error clearing recently played:', error);
        showNotification('Failed to clear recently played', 'error');
    }
}

// Show notification (simple implementation)
function showNotification(message, type = 'info') {
    console.log(`[${type.toUpperCase()}] ${message}`);

    // Create notification element
    const notification = document.createElement('div');
    notification.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        padding: 15px 25px;
        background: ${type === 'success' ? '#1DB954' : type === 'error' ? '#E22134' : '#FFA500'};
        color: white;
        border-radius: 8px;
        box-shadow: 0 4px 12px rgba(0,0,0,0.3);
        z-index: 10000;
        animation: slideIn 0.3s ease-out;
        font-weight: 500;
    `;
    notification.textContent = message;

    document.body.appendChild(notification);

    setTimeout(() => {
        notification.style.animation = 'slideOut 0.3s ease-out';
        setTimeout(() => notification.remove(), 300);
    }, 3000);
}

// Escape HTML to prevent XSS
function escapeHtml(text) {
    const div = document.createElement('div');
    div.textContent = text;
    return div.innerHTML;
}

// Add CSS animations for notifications
const style = document.createElement('style');
style.textContent = `
    @keyframes slideIn {
        from {
            transform: translateX(400px);
            opacity: 0;
        }
        to {
            transform: translateX(0);
            opacity: 1;
        }
    }
    
    @keyframes slideOut {
        from {
            transform: translateX(0);
            opacity: 1;
        }
        to {
            transform: translateX(400px);
            opacity: 0;
        }
    }
`;
document.head.appendChild(style);

// Allow Enter key to add song
document.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        const activeElement = document.activeElement;
        if (activeElement.id === 'songName' || activeElement.id === 'artistName' || activeElement.id === 'genreName') {
            addSong();
        } else if (activeElement.id === 'searchInput') {
            searchSongs();
        }
    }
});
