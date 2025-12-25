#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {
private:
    int id;
    string name;
    string artist;
    string genre;
    int playCount;
    string filePath;

public:
    // Constructors
    Song();
    Song(int id, string name, string artist, string genre = "Unknown", string filePath = "");
    
    // Getters
    int getId() const;
    string getName() const;
    string getArtist() const;
    string getGenre() const;
    int getPlayCount() const;
    string getFilePath() const;
    
    // Setters
    void setId(int id);
    void setName(string name);
    void setArtist(string artist);
    void setGenre(string genre);
    void setPlayCount(int count);
    void setFilePath(string path);
    
    // Methods
    void incrementPlayCount();
    void display() const;
    
    // Operator overloading for comparison (used in sorting)
    bool operator<(const Song& other) const;
    bool operator>(const Song& other) const;
    bool operator==(const Song& other) const;
};

#endif
