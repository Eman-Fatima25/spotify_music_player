import sqlite3
import os
from datetime import datetime

DATABASE_PATH = 'music.db'

def get_connection():
    """Create and return a database connection"""
    conn = sqlite3.connect(DATABASE_PATH)
    conn.row_factory = sqlite3.Row  # Access columns by name
    return conn

def init_db():
    """Initialize the database with required tables"""
    conn = get_connection()
    cursor = conn.cursor()
    
    # Create songs table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS songs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            artist TEXT NOT NULL,
            genre TEXT DEFAULT 'Unknown',
            play_count INTEGER DEFAULT 0,
            file_path TEXT NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    ''')
    
    # Create recently_played table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS recently_played (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            song_id INTEGER,
            played_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (song_id) REFERENCES songs(id) ON DELETE CASCADE
        )
    ''')
    
    conn.commit()
    conn.close()
    print("Database initialized successfully!")

def add_song(name, artist, genre='Unknown', file_path=''):
    """Add a new song to the database"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('''
        INSERT INTO songs (name, artist, genre, file_path)
        VALUES (?, ?, ?, ?)
    ''', (name, artist, genre, file_path))
    
    song_id = cursor.lastrowid
    conn.commit()
    conn.close()
    
    return song_id

def get_all_songs():
    """Get all songs from the database"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('SELECT * FROM songs ORDER BY name')
    songs = cursor.fetchall()
    
    conn.close()
    
    # Convert to list of dictionaries
    return [dict(song) for song in songs]

def get_song_by_id(song_id):
    """Get a specific song by ID"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('SELECT * FROM songs WHERE id = ?', (song_id,))
    song = cursor.fetchone()
    
    conn.close()
    
    return dict(song) if song else None

def update_play_count(song_id):
    """Increment the play count for a song"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('''
        UPDATE songs 
        SET play_count = play_count + 1 
        WHERE id = ?
    ''', (song_id,))
    
    conn.commit()
    conn.close()

def delete_song(song_id):
    """Delete a song from the database"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('DELETE FROM songs WHERE id = ?', (song_id,))
    
    conn.commit()
    conn.close()

def search_songs(query):
    """Search songs by name or artist"""
    conn = get_connection()
    cursor = conn.cursor()
    
    search_pattern = f'%{query}%'
    cursor.execute('''
        SELECT * FROM songs 
        WHERE name LIKE ? OR artist LIKE ?
        ORDER BY name
    ''', (search_pattern, search_pattern))
    
    songs = cursor.fetchall()
    conn.close()
    
    return [dict(song) for song in songs]

def add_to_recently_played(song_id):
    """Add a song to recently played"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('''
        INSERT INTO recently_played (song_id)
        VALUES (?)
    ''', (song_id,))
    
    # Keep only last 10 recently played
    cursor.execute('''
        DELETE FROM recently_played 
        WHERE id NOT IN (
            SELECT id FROM recently_played 
            ORDER BY played_at DESC 
            LIMIT 10
        )
    ''')
    
    conn.commit()
    conn.close()

def get_recently_played(limit=10):
    """Get recently played songs"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('''
        SELECT s.*, rp.played_at
        FROM recently_played rp
        JOIN songs s ON rp.song_id = s.id
        ORDER BY rp.played_at DESC
        LIMIT ?
    ''', (limit,))
    
    songs = cursor.fetchall()
    conn.close()
    
    return [dict(song) for song in songs]

def clear_recently_played():
    """Clear all recently played songs"""
    conn = get_connection()
    cursor = conn.cursor()
    
    cursor.execute('DELETE FROM recently_played')
    
    conn.commit()
    conn.close()

# Initialize database on import
if not os.path.exists(DATABASE_PATH):
    init_db()
