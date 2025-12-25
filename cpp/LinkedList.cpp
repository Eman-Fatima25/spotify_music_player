#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

// Destructor - Free all memory
LinkedList::~LinkedList() {
    clear();
}

// Insert song at the end of the list
void LinkedList::insertAtEnd(Song song) {
    Node* newNode = new Node(song);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

// Insert song at the beginning of the list
void LinkedList::insertAtBeginning(Song song) {
    Node* newNode = new Node(song);
    newNode->next = head;
    head = newNode;
    size++;
}

// Delete song by ID
bool LinkedList::deleteById(int id) {
    if (head == nullptr) {
        return false;
    }
    
    // If head node contains the song
    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }
    
    // Search for the song in the rest of the list
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data.getId() == id) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }
    
    return false;
}

// Search song by ID
Song* LinkedList::searchById(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getId() == id) {
            return &(temp->data);
        }
        temp = temp->next;
    }
    return nullptr;
}

// Search song by name
Song* LinkedList::searchByName(string name) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.getName() == name) {
            return &(temp->data);
        }
        temp = temp->next;
    }
    return nullptr;
}

// Display all songs in the list
void LinkedList::display() const {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    int count = 1;
    cout << "\n========== SONG LIBRARY ==========" << endl;
    while (temp != nullptr) {
        cout << "\nSong #" << count++ << ":" << endl;
        temp->data.display();
        temp = temp->next;
    }
    cout << "Total Songs: " << size << endl;
    cout << "==================================\n" << endl;
}

// Get size of the list
int LinkedList::getSize() const {
    return size;
}

// Check if list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Clear the entire list
void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

// Convert linked list to array (for sorting)
Song* LinkedList::toArray(int& arraySize) {
    arraySize = size;
    if (size == 0) {
        return nullptr;
    }
    
    Song* arr = new Song[size];
    Node* temp = head;
    int i = 0;
    
    while (temp != nullptr) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    
    return arr;
}

// Rebuild linked list from array (after sorting)
void LinkedList::fromArray(Song* arr, int arraySize) {
    clear();
    for (int i = 0; i < arraySize; i++) {
        insertAtEnd(arr[i]);
    }
}

// Get head pointer
Node* LinkedList::getHead() const {
    return head;
}
