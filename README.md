# 🎵 Spotify Music Management System

## 👥 Group Details
- **Member Name:** Marjan Ikram  
- **Registration ID:** B24F1088CS084  

---

## 🎵 Project Title & Description
**Project Title:**Spotify Music Management System  

**Description:**  
A comprehensive music management system demonstrating **Data Structures and Algorithms** concepts using C++, with a Python Flask backend and a modern web interface. The project showcases Linked Lists, Stack, Sorting Algorithms, and database integration with a functional music player.

---

## 📹 Visuals

### Main Application Screenshot
![Spotify Music Player UI](assets/screenshots/spotify_ui.png)


---

## 📝 Supervision Note
"This project was developed for the Data Structures and Algorithms (DSA) course under the supervision of Lab Engineer Obaidullah Miakhil."

---

## 📋 Project Overview
This project implements a fully functional music player that demonstrates:
- **Linked List** - Dynamic song library management
- **Stack** - Recently played songs (LIFO)
- **Sorting Algorithms** - Bubble Sort & Selection Sort
- **Database** - SQLite for persistent storage
- **Web Interface** - Beautiful, responsive UI

## 🛠️ Technology Stack
- **C++** - Core DSA implementations
- **Python 3.x** - Flask web server
- **SQLite** - Database management
- **HTML5/CSS3** - Modern frontend
- **JavaScript** - Client-side logic

## 📁 Project Structure

A comprehensive music management system demonstrating **Data Structures and Algorithms** concepts using C++,Eman with a Python Flask backend and modern web interface.

## 📋 Project Overview

This project implements a fully functional music player that demonstrates:
- **Linked List** - Dynamic song library management
- **Stack** - Recently played songs (LIFO)
- **Sorting Algorithms** - Bubble Sort & Selection Sort
- **Database** - SQLite for persistent storage
- **Web Interface** - Beautiful, responsive UI

## 🛠️ Technology Stack

- **C++** - Core DSA implementations
- **Python 3.x** - Flask web server
- **SQLite** - Database management
- **HTML5/CSS3** - Modern frontend
- **JavaScript** - Client-side logic

## 📁 Project Structure

```
DSA_Project/
├── cpp/                          # C++ DSA Implementation
│   ├── Song.h/cpp               # Song class
│   ├── LinkedList.h/cpp         # Linked List implementation
│   ├── Stack.h/cpp              # Stack for recently played
│   ├── SortingAlgorithms.h/cpp  # Bubble & Selection Sort
│   └── main.cpp                 # Demonstration program
├── static/                       # Frontend assets
│   ├── css/style.css            # Styling
│   └── js/app.js                # JavaScript logic
├── templates/                    # HTML templates
│   └── index.html               # Main page
├── music/                        # Audio files storage
├── app.py                        # Flask server (MAIN FILE)
├── database.py                   # SQLite operations
├── requirements.txt              # Python dependencies
└── README.md                     # This file
```

## 🚀 Getting Started

### Prerequisites

- Python 3.7 or higher
- C++ compiler (g++, MinGW, or MSVC)
- Web browser

### Installation

1. **Install Python Dependencies**
   ```bash
   pip install -r requirements.txt
   ```

2. **Compile C++ Code (Optional - for standalone demo)**
   ```bash
   cd cpp
   g++ -o music_player main.cpp Song.cpp LinkedList.cpp Stack.cpp SortingAlgorithms.cpp
   ```

### Running the Application

1. **Start the Python Server**
   ```bash
   python app.py
   ```

2. **Open your browser**
   Navigate to: `http://localhost:5000`

3. **Run C++ Demonstration (Optional)**
   ```bash
   cd cpp
   ./music_player
   ```

## 📚 Features

### Web Interface
- ✅ Add songs with name, artist, and genre
- ✅ Play songs with HTML5 audio player
- ✅ Search songs by name or artist
- ✅ Sort songs alphabetically or by play count
- ✅ View recently played songs (Stack)
- ✅ Delete songs
- ✅ Beautiful, responsive design

### C++ DSA Demonstrations

#### 1. **Linked List**
- Insert songs at beginning/end
- Delete songs by ID
- Search by name or ID
- Traverse and display all songs

#### 2. **Stack (Recently Played)**
- Push songs when played
- Pop to remove from history
- Peek at most recent
- Automatic overflow handling (max 10 songs)

#### 3. **Sorting Algorithms**
- **Bubble Sort** - O(n²) time complexity
- **Selection Sort** - O(n²) time complexity
- Sort by name (alphabetically)
- Sort by play count (descending)
- Performance metrics (comparisons & swaps)

## 🎯 DSA Concepts Demonstrated

### Linked List
```cpp
// Dynamic memory allocation
// Insert, Delete, Search operations
// Traversal and display
```

### Stack
```cpp
// LIFO (Last In First Out)
// Push, Pop, Peek operations
// Overflow handling
```

### Sorting Algorithms
```cpp
// Bubble Sort - Compares adjacent elements
// Selection Sort - Finds minimum element
// Time complexity analysis
```

## 📊 Database Schema

### Songs Table
```sql
id          INTEGER PRIMARY KEY
name        TEXT NOT NULL
artist      TEXT NOT NULL
genre       TEXT
play_count  INTEGER DEFAULT 0
file_path   TEXT NOT NULL
created_at  TIMESTAMP
```

### Recently Played Table
```sql
id          INTEGER PRIMARY KEY
song_id     INTEGER (Foreign Key)
played_at   TIMESTAMP
```

## 🎨 UI Features

- **Dark Theme** - Spotify-inspired design
- **Gradient Backgrounds** - Modern aesthetics
- **Smooth Animations** - Enhanced user experience
- **Responsive Layout** - Works on all devices
- **Real-time Updates** - Dynamic content loading

## 🧪 Testing the Application

1. **Add Songs**: Use the form to add songs
2. **Play Songs**: Click play button to test audio
3. **Search**: Try searching by song name or artist
4. **Sort**: Test both sorting methods
5. **Recently Played**: Verify stack behavior
6. **Delete**: Remove songs and check updates

## 📖 C++ Program Menu

When running the C++ standalone program:

```
1. Demonstrate Linked List
2. Demonstrate Stack (Recently Played)
3. Demonstrate Sorting Algorithms
4. Full System Demonstration
5. Exit
```

## 🔧 API Endpoints

- `GET /api/songs` - Get all songs
- `POST /api/songs` - Add new song
- `DELETE /api/songs/<id>` - Delete song
- `POST /api/songs/<id>/play` - Play song
- `GET /api/songs/search?q=<query>` - Search songs
- `POST /api/songs/sort` - Sort songs
- `GET /api/recent` - Get recently played
- `DELETE /api/recent` - Clear recently played

## 👨‍💻 Development

### Adding New Features

1. **C++ Side**: Modify classes in `cpp/` directory
2. **Python Side**: Update `app.py` or `database.py`
3. **Frontend**: Edit files in `static/` and `templates/`

### Database Reset

Delete `music.db` file and restart the server to reset the database.

## 📝 Project Requirements Met

✅ Song Class with attributes (name, artist, genre, play count)  
✅ Linked List for song library management  
✅ Stack for recently played songs  
✅ Sorting Algorithms (Bubble Sort & Selection Sort)  
✅ Python backend for database connectivity  
✅ Beautiful HTML/CSS frontend  
✅ Audio playback functionality  
✅ Search and filter capabilities  

## 🎓 Learning Outcomes

This project demonstrates:
- Object-Oriented Programming in C++
- Data Structure implementation
- Algorithm analysis and complexity
- Database design and operations
- Web development (Full Stack)
- API design and integration

## 🤝 Contributing

This is an educational project. Feel free to:
- Add more sorting algorithms (Quick Sort, Merge Sort)
- Implement Queue for playlist management
- Add user authentication
- Implement file upload for actual audio files

## 📄 License

This project is created for educational purposes as a DSA course project.

## 👤 Author

Created as a Data Structures and Algorithms project demonstrating practical applications of DSA concepts.

---

**Note**: This project combines C++ DSA implementations with modern web technologies to create a functional music management system. The C++ code can run standalone for DSA demonstrations, while the Python backend integrates everything into a web application.
