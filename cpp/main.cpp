#include <iostream>
#include <string>
#include "Song.h"
#include "LinkedList.h"
#include "Stack.h"
#include "SortingAlgorithms.h"

using namespace std;

void displayMenu();
void demonstrateLinkedList();
void demonstrateStack();
void demonstrateSorting();
void demonstrateFullSystem();

int main() {
    cout << "\n";
    cout << "========================================" << endl;
    cout << "   SPOTIFY MUSIC MANAGEMENT SYSTEM" << endl;
    cout << "   Data Structures & Algorithms Demo" << endl;
    cout << "========================================" << endl;
    cout << "\nThis C++ program demonstrates:" << endl;
    cout << "1. Linked List - for song library management" << endl;
    cout << "2. Stack - for recently played songs" << endl;
    cout << "3. Sorting Algorithms - Bubble Sort & Selection Sort" << endl;
    cout << "\n========================================\n" << endl;
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                demonstrateLinkedList();
                break;
            case 2:
                demonstrateStack();
                break;
            case 3:
                demonstrateSorting();
                break;
            case 4:
                demonstrateFullSystem();
                break;
            case 5:
                cout << "\nThank you for using Spotify Music Management System!" << endl;
                cout << "Goodbye!\n" << endl;
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n" << endl;
        }
    }
    
    return 0;
}

void displayMenu() {
    cout << "\n========== MAIN MENU ==========" << endl;
    cout << "1. Demonstrate Linked List" << endl;
    cout << "2. Demonstrate Stack (Recently Played)" << endl;
    cout << "3. Demonstrate Sorting Algorithms" << endl;
    cout << "4. Full System Demonstration" << endl;
    cout << "5. Exit" << endl;
    cout << "===============================" << endl;
}

void demonstrateLinkedList() {
    cout << "\n\n========================================" << endl;
    cout << "   LINKED LIST DEMONSTRATION" << endl;
    cout << "========================================" << endl;
    
    LinkedList songLibrary;
    
    cout << "\n--- Creating Song Library using Linked List ---" << endl;
    cout << "\nInserting songs at the end..." << endl;
    
    songLibrary.insertAtEnd(Song(1, "Blinding Lights", "The Weeknd", "Pop", "/music/blinding_lights.mp3"));
    cout << "Added: Blinding Lights by The Weeknd" << endl;
    
    songLibrary.insertAtEnd(Song(2, "Shape of You", "Ed Sheeran", "Pop", "/music/shape_of_you.mp3"));
    cout << "Added: Shape of You by Ed Sheeran" << endl;
    
    songLibrary.insertAtEnd(Song(3, "Bohemian Rhapsody", "Queen", "Rock", "/music/bohemian_rhapsody.mp3"));
    cout << "Added: Bohemian Rhapsody by Queen" << endl;
    
    cout << "\nInserting song at the beginning..." << endl;
    songLibrary.insertAtBeginning(Song(4, "Hotel California", "Eagles", "Rock", "/music/hotel_california.mp3"));
    cout << "Added: Hotel California by Eagles (at beginning)" << endl;
    
    // Display all songs
    songLibrary.display();
    
    // Search operations
    cout << "\n--- Search Operations ---" << endl;
    Song* found = songLibrary.searchByName("Shape of You");
    if (found != nullptr) {
        cout << "\nFound song by name 'Shape of You':" << endl;
        found->display();
    }
    
    found = songLibrary.searchById(3);
    if (found != nullptr) {
        cout << "Found song by ID 3:" << endl;
        found->display();
    }
    
    // Delete operation
    cout << "\n--- Delete Operation ---" << endl;
    cout << "Deleting song with ID 2..." << endl;
    if (songLibrary.deleteById(2)) {
        cout << "Successfully deleted song with ID 2" << endl;
    }
    
    songLibrary.display();
    
    cout << "\nLinked List demonstration completed!" << endl;
    cout << "========================================\n" << endl;
}

void demonstrateStack() {
    cout << "\n\n========================================" << endl;
    cout << "   STACK DEMONSTRATION" << endl;
    cout << "   (Recently Played Songs)" << endl;
    cout << "========================================" << endl;
    
    Stack recentlyPlayed(5); // Stack with capacity of 5
    
    cout << "\n--- Simulating Song Playback ---" << endl;
    cout << "Playing songs and adding to Recently Played stack...\n" << endl;
    
    Song song1(1, "Starboy", "The Weeknd", "Pop", "/music/starboy.mp3");
    song1.incrementPlayCount();
    recentlyPlayed.push(song1);
    cout << "Played: " << song1.getName() << " by " << song1.getArtist() << endl;
    
    Song song2(2, "Thinking Out Loud", "Ed Sheeran", "Pop", "/music/thinking_out_loud.mp3");
    song2.incrementPlayCount();
    recentlyPlayed.push(song2);
    cout << "Played: " << song2.getName() << " by " << song2.getArtist() << endl;
    
    Song song3(3, "We Will Rock You", "Queen", "Rock", "/music/we_will_rock_you.mp3");
    song3.incrementPlayCount();
    recentlyPlayed.push(song3);
    cout << "Played: " << song3.getName() << " by " << song3.getArtist() << endl;
    
    Song song4(4, "Desperado", "Eagles", "Rock", "/music/desperado.mp3");
    song4.incrementPlayCount();
    recentlyPlayed.push(song4);
    cout << "Played: " << song4.getName() << " by " << song4.getArtist() << endl;
    
    // Display stack
    recentlyPlayed.display();
    
    // Peek operation
    cout << "\n--- Peek Operation (View top without removing) ---" << endl;
    Song topSong = recentlyPlayed.peek();
    cout << "Top song (most recently played):" << endl;
    topSong.display();
    
    // Pop operation
    cout << "\n--- Pop Operation (Remove from stack) ---" << endl;
    Song popped = recentlyPlayed.pop();
    cout << "Removed from recently played:" << endl;
    popped.display();
    
    cout << "\nAfter popping:" << endl;
    recentlyPlayed.display();
    
    // Test overflow
    cout << "\n--- Testing Stack Overflow Handling ---" << endl;
    cout << "Adding more songs (stack capacity is 5)...\n" << endl;
    
    for (int i = 5; i <= 8; i++) {
        Song newSong(i, "Song " + to_string(i), "Artist " + to_string(i), "Genre", "/music/song" + to_string(i) + ".mp3");
        recentlyPlayed.push(newSong);
        cout << "Added: Song " << i << endl;
    }
    
    cout << "\nStack automatically maintains only the last 5 songs:" << endl;
    recentlyPlayed.display();
    
    cout << "\nStack demonstration completed!" << endl;
    cout << "========================================\n" << endl;
}

void demonstrateSorting() {
    cout << "\n\n========================================" << endl;
    cout << "   SORTING ALGORITHMS DEMONSTRATION" << endl;
    cout << "========================================" << endl;
    
    // Create array of songs
    const int SIZE = 5;
    Song songs[SIZE] = {
        Song(1, "Zebra", "Artist A", "Pop", "/music/zebra.mp3"),
        Song(2, "Apple", "Artist B", "Rock", "/music/apple.mp3"),
        Song(3, "Mango", "Artist C", "Jazz", "/music/mango.mp3"),
        Song(4, "Banana", "Artist D", "Pop", "/music/banana.mp3"),
        Song(5, "Cherry", "Artist E", "Rock", "/music/cherry.mp3")
    };
    
    // Set different play counts
    songs[0].setPlayCount(10);
    songs[1].setPlayCount(25);
    songs[2].setPlayCount(5);
    songs[3].setPlayCount(30);
    songs[4].setPlayCount(15);
    
    cout << "\n--- Original Song List ---" << endl;
    SortingAlgorithms::displayArray(songs, SIZE);
    
    // Bubble Sort by Name
    Song bubbleSortArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        bubbleSortArray[i] = songs[i];
    }
    
    SortingAlgorithms::bubbleSort(bubbleSortArray, SIZE, true);
    cout << "\n--- After Bubble Sort (Alphabetically) ---" << endl;
    SortingAlgorithms::displayArray(bubbleSortArray, SIZE);
    
    // Selection Sort by Name
    Song selectionSortArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        selectionSortArray[i] = songs[i];
    }
    
    SortingAlgorithms::selectionSort(selectionSortArray, SIZE, true);
    cout << "\n--- After Selection Sort (Alphabetically) ---" << endl;
    SortingAlgorithms::displayArray(selectionSortArray, SIZE);
    
    // Sort by Play Count
    Song playCountArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        playCountArray[i] = songs[i];
    }
    
    SortingAlgorithms::bubbleSortByPlayCount(playCountArray, SIZE, false);
    cout << "\n--- After Bubble Sort (By Play Count - Descending) ---" << endl;
    SortingAlgorithms::displayArray(playCountArray, SIZE);
    
    cout << "\nSorting demonstration completed!" << endl;
    cout << "========================================\n" << endl;
}

void demonstrateFullSystem() {
    cout << "\n\n========================================" << endl;
    cout << "   FULL SYSTEM DEMONSTRATION" << endl;
    cout << "========================================" << endl;
    
    LinkedList library;
    Stack recentlyPlayed(10);
    
    cout << "\n--- Building Music Library ---" << endl;
    library.insertAtEnd(Song(1, "Blinding Lights", "The Weeknd", "Pop", "/music/blinding_lights.mp3"));
    library.insertAtEnd(Song(2, "Shape of You", "Ed Sheeran", "Pop", "/music/shape_of_you.mp3"));
    library.insertAtEnd(Song(3, "Bohemian Rhapsody", "Queen", "Rock", "/music/bohemian_rhapsody.mp3"));
    library.insertAtEnd(Song(4, "Hotel California", "Eagles", "Rock", "/music/hotel_california.mp3"));
    library.insertAtEnd(Song(5, "Imagine", "John Lennon", "Classic", "/music/imagine.mp3"));
    
    cout << "Added 5 songs to library" << endl;
    library.display();
    
    cout << "\n--- Simulating User Activity ---" << endl;
    cout << "Playing songs...\n" << endl;
    
    // Play some songs
    Song* song = library.searchById(2);
    if (song != nullptr) {
        song->incrementPlayCount();
        recentlyPlayed.push(*song);
        cout << "Played: " << song->getName() << endl;
    }
    
    song = library.searchById(4);
    if (song != nullptr) {
        song->incrementPlayCount();
        recentlyPlayed.push(*song);
        cout << "Played: " << song->getName() << endl;
    }
    
    song = library.searchById(1);
    if (song != nullptr) {
        song->incrementPlayCount();
        song->incrementPlayCount(); // Play twice
        recentlyPlayed.push(*song);
        cout << "Played: " << song->getName() << " (2 times)" << endl;
    }
    
    recentlyPlayed.display();
    
    cout << "\n--- Sorting Library ---" << endl;
    int arraySize;
    Song* songArray = library.toArray(arraySize);
    
    SortingAlgorithms::bubbleSort(songArray, arraySize, true);
    library.fromArray(songArray, arraySize);
    
    cout << "\nLibrary after sorting alphabetically:" << endl;
    library.display();
    
    delete[] songArray;
    
    cout << "\nFull system demonstration completed!" << endl;
    cout << "This demonstrates how all DSA components work together!" << endl;
    cout << "========================================\n" << endl;
}
