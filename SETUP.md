# 🚀 Quick Setup Guide

## Prerequisites Installation

### 1. Install Python (Required)

**Download Python 3.11 or higher:**
- Visit: https://www.python.org/downloads/
- Download the Windows installer
- **IMPORTANT**: Check "Add Python to PATH" during installation
- Verify installation: Open Command Prompt and type `python --version`

### 2. Install C++ Compiler (Optional - for C++ demo)

**Option A: MinGW-w64**
- Visit: https://www.mingw-w64.org/
- Download and install
- Add to PATH

**Option B: Visual Studio**
- Download Visual Studio Community (free)
- Install with "Desktop development with C++" workload

## Installation Steps

### Step 1: Install Python Dependencies

Open Command Prompt in the project folder and run:

```bash
python -m pip install -r requirements.txt
```

Or if you have pip directly:

```bash
pip install -r requirements.txt
```

### Step 2: Run the Application

```bash
python app.py
```

The server will start on: **http://localhost:5000**

### Step 3: Open in Browser

Navigate to: `http://localhost:5000`

## Using the Application

### Web Interface

1. **Add Songs**: Fill in the form and click "Add Song"
2. **Play Songs**: Click the play button on any song
3. **Search**: Type in the search box and click "Search"
4. **Sort**: Use the sort buttons to organize songs
5. **Recently Played**: View your listening history
6. **Delete**: Remove songs you don't want

### C++ Demonstration (Optional)

To see the DSA concepts in action:

1. **Compile the C++ code:**
   ```bash
   cd cpp
   g++ -o music_player main.cpp Song.cpp LinkedList.cpp Stack.cpp SortingAlgorithms.cpp
   ```

2. **Run the program:**
   ```bash
   ./music_player
   ```

3. **Explore the menu:**
   - Linked List operations
   - Stack (Recently Played) demonstration
   - Sorting algorithms with performance metrics
   - Full system integration

## Troubleshooting

### Python not found
- Make sure Python is installed
- Check if Python is in your PATH
- Try `python3` instead of `python`

### Flask not found
- Run: `python -m pip install Flask`

### Port already in use
- Change the port in `app.py` (last line)
- Or stop the process using port 5000

### C++ compilation errors
- Make sure you're in the `cpp` directory
- Check if g++ is installed: `g++ --version`
- Use Visual Studio if g++ is not available

## Project Structure

```
DSA_Project/
├── app.py              ← Main Python server (START HERE)
├── database.py         ← Database operations
├── requirements.txt    ← Python dependencies
├── README.md          ← Full documentation
├── SETUP.md           ← This file
├── cpp/               ← C++ DSA implementations
│   ├── main.cpp       ← C++ demo program
│   └── *.h/cpp        ← DSA classes
├── templates/         ← HTML files
│   └── index.html
├── static/            ← CSS and JavaScript
│   ├── css/style.css
│   └── js/app.js
└── music/             ← Audio files (auto-created)
```

## Quick Start Commands

```bash
# Install dependencies
python -m pip install -r requirements.txt

# Start the server
python app.py

# Open browser to http://localhost:5000
```

## Features Checklist

✅ Add songs with name, artist, genre  
✅ Play songs with audio player  
✅ Search by name or artist  
✅ Sort alphabetically or by play count  
✅ View recently played (Stack)  
✅ Delete songs  
✅ Beautiful, responsive UI  
✅ SQLite database persistence  
✅ C++ DSA demonstrations  

## Need Help?

- Check `README.md` for detailed documentation
- Review the C++ code in the `cpp/` folder
- Test the API endpoints using the browser console

## Next Steps

1. Add some songs using the web interface
2. Play songs to test the audio player
3. Try searching and sorting
4. Run the C++ demo to see DSA concepts
5. Explore the code to understand the implementation

---

**Enjoy your music player! 🎵**
