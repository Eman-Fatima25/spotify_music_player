#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "Song.h"
#include <iostream>

using namespace std;

class SortingAlgorithms {
public:
    // Bubble Sort - O(n^2)
    // Compares adjacent elements and swaps if they're in wrong order
    static void bubbleSort(Song* arr, int size, bool ascending = true);
    
    // Selection Sort - O(n^2)
    // Finds minimum element and places it at beginning
    static void selectionSort(Song* arr, int size, bool ascending = true);
    
    // Sort by play count
    static void bubbleSortByPlayCount(Song* arr, int size, bool ascending = false);
    static void selectionSortByPlayCount(Song* arr, int size, bool ascending = false);
    
    // Utility functions
    static void displayArray(Song* arr, int size);
    static void swap(Song& a, Song& b);
};

#endif
