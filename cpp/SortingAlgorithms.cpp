#include "SortingAlgorithms.h"

// Swap two songs
void SortingAlgorithms::swap(Song& a, Song& b) {
    Song temp = a;
    a = b;
    b = temp;
}

// Bubble Sort by Song Name
void SortingAlgorithms::bubbleSort(Song* arr, int size, bool ascending) {
    cout << "\n========== BUBBLE SORT (By Name) ==========" << endl;
    cout << "Starting Bubble Sort..." << endl;
    cout << "Time Complexity: O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    int comparisons = 0;
    int swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            
            bool condition = ascending ? 
                (arr[j].getName() > arr[j + 1].getName()) : 
                (arr[j].getName() < arr[j + 1].getName());
            
            if (condition) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        
        // If no swaps occurred, array is already sorted
        if (!swapped) {
            break;
        }
    }
    
    cout << "Bubble Sort completed!" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;
    cout << "==========================================\n" << endl;
}

// Selection Sort by Song Name
void SortingAlgorithms::selectionSort(Song* arr, int size, bool ascending) {
    cout << "\n========== SELECTION SORT (By Name) ==========" << endl;
    cout << "Starting Selection Sort..." << endl;
    cout << "Time Complexity: O(n^2)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    int comparisons = 0;
    int swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int selectedIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            
            bool condition = ascending ?
                (arr[j].getName() < arr[selectedIndex].getName()) :
                (arr[j].getName() > arr[selectedIndex].getName());
            
            if (condition) {
                selectedIndex = j;
            }
        }
        
        if (selectedIndex != i) {
            swap(arr[i], arr[selectedIndex]);
            swaps++;
        }
    }
    
    cout << "Selection Sort completed!" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;
    cout << "=============================================\n" << endl;
}

// Bubble Sort by Play Count
void SortingAlgorithms::bubbleSortByPlayCount(Song* arr, int size, bool ascending) {
    cout << "\n========== BUBBLE SORT (By Play Count) ==========" << endl;
    cout << "Starting Bubble Sort by Play Count..." << endl;
    
    int comparisons = 0;
    int swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            
            bool condition = ascending ?
                (arr[j].getPlayCount() > arr[j + 1].getPlayCount()) :
                (arr[j].getPlayCount() < arr[j + 1].getPlayCount());
            
            if (condition) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
    
    cout << "Bubble Sort by Play Count completed!" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;
    cout << "================================================\n" << endl;
}

// Selection Sort by Play Count
void SortingAlgorithms::selectionSortByPlayCount(Song* arr, int size, bool ascending) {
    cout << "\n========== SELECTION SORT (By Play Count) ==========" << endl;
    cout << "Starting Selection Sort by Play Count..." << endl;
    
    int comparisons = 0;
    int swaps = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int selectedIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            
            bool condition = ascending ?
                (arr[j].getPlayCount() < arr[selectedIndex].getPlayCount()) :
                (arr[j].getPlayCount() > arr[selectedIndex].getPlayCount());
            
            if (condition) {
                selectedIndex = j;
            }
        }
        
        if (selectedIndex != i) {
            swap(arr[i], arr[selectedIndex]);
            swaps++;
        }
    }
    
    cout << "Selection Sort by Play Count completed!" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;
    cout << "===================================================\n" << endl;
}

// Display array of songs
void SortingAlgorithms::displayArray(Song* arr, int size) {
    cout << "\n========== SORTED SONGS ==========" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". ";
        arr[i].display();
    }
    cout << "==================================\n" << endl;
}
