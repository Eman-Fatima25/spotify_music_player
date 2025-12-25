#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Song.h"
#include <iostream>

using namespace std;

// Node structure for Linked List
class Node {
public:
    Song data;
    Node* next;
    
    Node(Song song) {
        data = song;
        next = nullptr;
    }
};

// Linked List class for managing songs
class LinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Basic operations
    void insertAtEnd(Song song);
    void insertAtBeginning(Song song);
    bool deleteById(int id);
    Song* searchById(int id);
    Song* searchByName(string name);
    
    // Utility functions
    void display() const;
    int getSize() const;
    bool isEmpty() const;
    void clear();
    
    // Get all songs as array (for sorting)
    Song* toArray(int& arraySize);
    void fromArray(Song* arr, int arraySize);
    
    // Traversal
    Node* getHead() const;
};

#endif
