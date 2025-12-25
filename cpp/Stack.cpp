#include "Stack.h"

// Constructor
Stack::Stack(int size) {
    capacity = size;
    items = new Song[capacity];
    top = -1;
}

// Destructor
Stack::~Stack() {
    delete[] items;
}

// Push song onto stack (Recently Played)
void Stack::push(Song song) {
    if (isFull()) {
        // If stack is full, shift all elements down and add new one at top
        for (int i = 0; i < capacity - 1; i++) {
            items[i] = items[i + 1];
        }
        items[capacity - 1] = song;
        top = capacity - 1;
    } else {
        items[++top] = song;
    }
}

// Pop song from stack
Song Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot pop." << endl;
        return Song();
    }
    return items[top--];
}

// Peek at top song without removing
Song Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty! Cannot peek." << endl;
        return Song();
    }
    return items[top];
}

// Check if stack is empty
bool Stack::isEmpty() const {
    return top == -1;
}

// Check if stack is full
bool Stack::isFull() const {
    return top == capacity - 1;
}

// Get current size of stack
int Stack::getSize() const {
    return top + 1;
}

// Display all songs in stack (Recently Played)
void Stack::display() const {
    if (isEmpty()) {
        cout << "No recently played songs!" << endl;
        return;
    }
    
    cout << "\n===== RECENTLY PLAYED (Stack) =====" << endl;
    cout << "Showing last " << getSize() << " played songs:" << endl;
    
    // Display from top to bottom (most recent first)
    for (int i = top; i >= 0; i--) {
        cout << "\n[" << (top - i + 1) << "] ";
        items[i].display();
    }
    cout << "===================================\n" << endl;
}

// Clear the stack
void Stack::clear() {
    top = -1;
}

// Get all items as array
Song* Stack::getAll(int& count) {
    count = getSize();
    if (count == 0) {
        return nullptr;
    }
    
    Song* result = new Song[count];
    for (int i = 0; i < count; i++) {
        result[i] = items[top - i]; // Reverse order (most recent first)
    }
    return result;
}
