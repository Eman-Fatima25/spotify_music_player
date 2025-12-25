#ifndef STACK_H
#define STACK_H

#include "Song.h"
#include <iostream>

using namespace std;

#define MAX_STACK_SIZE 10

// Stack class for Recently Played songs
class Stack {
private:
    Song* items;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size = MAX_STACK_SIZE);
    
    // Destructor
    ~Stack();
    
    // Stack operations
    void push(Song song);
    Song pop();
    Song peek() const;
    
    // Utility functions
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void display() const;
    void clear();
    
    // Get all items (for display)
    Song* getAll(int& count);
};

#endif
