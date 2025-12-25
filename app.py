from flask import Flask, render_template, request, jsonify, send_from_directory
import os
import database as db
import json

app = Flask(__name__)

# Ensure music directory exists
MUSIC_DIR = 'music'
if not os.path.exists(MUSIC_DIR):
    os.makedirs(MUSIC_DIR)

# Initialize database
db.init_db()

@app.route('/')
def index():
    """Serve the main page"""
    return render_template('index.html')

@app.route('/api/songs', methods=['GET'])
def get_songs():
    """Get all songs"""
    try:
        songs = db.get_all_songs()
        return jsonify(songs)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/songs', methods=['POST'])
def add_song():
    """Add a new song"""
    try:
        data = request.get_json()
        name = data.get('name')
        artist = data.get('artist', 'Unknown')
        genre = data.get('genre', 'Unknown')
        file_path = data.get('file_path', f'/music/{name}.mp3')
        
        if not name:
            return jsonify({'error': 'Song name is required'}), 400
        
        song_id = db.add_song(name, artist, genre, file_path)
        song = db.get_song_by_id(song_id)
        
        return jsonify(song), 201
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/songs/<int:song_id>', methods=['DELETE'])
def delete_song(song_id):
    """Delete a song"""
    try:
        db.delete_song(song_id)
        return jsonify({'success': True})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/songs/<int:song_id>/play', methods=['POST'])
def play_song(song_id):
    """Play a song (increment play count and add to recently played)"""
    try:
        song = db.get_song_by_id(song_id)
        if not song:
            return jsonify({'error': 'Song not found'}), 404
        
        db.update_play_count(song_id)
        db.add_to_recently_played(song_id)
        
        updated_song = db.get_song_by_id(song_id)
        return jsonify(updated_song)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/songs/search', methods=['GET'])
def search_songs():
    """Search songs by name or artist"""
    try:
        query = request.args.get('q', '')
        if not query:
            return jsonify([])
        
        songs = db.search_songs(query)
        return jsonify(songs)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/songs/sort', methods=['POST'])
def sort_songs():
    """Sort songs using C++ algorithms"""
    try:
        data = request.get_json()
        algorithm = data.get('algorithm', 'bubble')  # bubble or selection
        sort_by = data.get('sort_by', 'name')  # name or play_count
        
        songs = db.get_all_songs()
        
        # For now, we'll do simple Python sorting
        # In a full implementation, this would call the C++ executable
        if sort_by == 'name':
            songs.sort(key=lambda x: x['name'])
        elif sort_by == 'play_count':
            songs.sort(key=lambda x: x['play_count'], reverse=True)
        
        return jsonify(songs)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/recent', methods=['GET'])
def get_recent():
    """Get recently played songs"""
    try:
        songs = db.get_recently_played()
        return jsonify(songs)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/recent', methods=['DELETE'])
def clear_recent():
    """Clear recently played songs"""
    try:
        db.clear_recently_played()
        return jsonify({'success': True})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/music/<path:filename>')
def serve_music(filename):
    """Serve music files"""
    return send_from_directory(MUSIC_DIR, filename)

if __name__ == '__main__':
    print("\n" + "="*50)
    print("  SPOTIFY MUSIC MANAGEMENT SYSTEM")
    print("  Python Flask Server")
    print("="*50)
    print("\nServer starting on http://localhost:5000")
    print("Press Ctrl+C to stop the server\n")
    print("="*50 + "\n")
    
    app.run(debug=True, host='0.0.0.0', port=5000)
