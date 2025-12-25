"""
Migration script to import songs from old songs.json to new SQLite database
"""
import json
import sys
sys.path.append('.')
from database import add_song

# Read old songs.json
with open('songs.json', 'r') as f:
    data = json.load(f)

# Migrate songs to SQLite
print("Migrating songs from songs.json to music.db...")
print(f"Found {len(data.get('songs', []))} songs to migrate\n")

for song in data.get('songs', []):
    name = song.get('name', 'Unknown')
    artist = song.get('artist', 'Unknown')
    genre = 'Unknown'  # Old format didn't have genre
    file_path = song.get('filePath', f'/music/{name}.mp3')
    
    song_id = add_song(name, artist, genre, file_path)
    print(f"[OK] Migrated: {name} by {artist} (ID: {song_id})")

print(f"\n[SUCCESS] Migration complete! {len(data.get('songs', []))} songs added to database.")
print("You can now refresh your browser to see the songs!")
