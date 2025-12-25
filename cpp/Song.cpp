#include "Song.h"

// Default Constructor
Song::Song() {
    this->id = 0;
    this->name = "";
    this->artist = "";
    this->genre = "Unknown";
    this->playCount = 0;
    this->filePath = "";
}

// Parameterized Constructor
Song::Song(int id, string name, string artist, string genre, string filePath) {
    this->id = id;
    this->name = name;
    this->artist = artist;
    this->genre = genre;
    this->playCount = 0;
    this->filePath = filePath;
}

// Getters
int Song::getId() const { return id; }
string Song::getName() const { return name; }
string Song::getArtist() const { return artist; }
string Song::getGenre() const { return genre; }
int Song::getPlayCount() const { return playCount; }
string Song::getFilePath() const { return filePath; }

// Setters
void Song::setId(int id) { this->id = id; }
void Song::setName(string name) { this->name = name; }
void Song::setArtist(string artist) { this->artist = artist; }
void Song::setGenre(string genre) { this->genre = genre; }
void Song::setPlayCount(int count) { this->playCount = count; }
void Song::setFilePath(string path) { this->filePath = path; }

// Increment play count
void Song::incrementPlayCount() {
    playCount++;
}

// Display song information
void Song::display() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Artist: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Play Count: " << playCount << endl;
    cout << "File Path: " << filePath << endl;
    cout << "------------------------" << endl;
}

// Operator overloading for sorting by name
bool Song::operator<(const Song& other) const {
    return this->name < other.name;
}

bool Song::operator>(const Song& other) const {
    return this->name > other.name;
}

bool Song::operator==(const Song& other) const {
    return this->id == other.id;
}
