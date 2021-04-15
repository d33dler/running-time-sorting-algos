//
// Created by radubereja on 14-04-21.
//

#include "insertionsort.h"

int searchIndex(int length, int arr[], int value) {
    int i = 0;
    while ((i < length) && (arr[i] <= value)) {
        i++;
    }
    return i;
}
void shiftRight(int length, int arr[], int idx) {
    int i;
    for (i = length; i > idx; i--) {
        arr[i] = arr[i-1];
    }
}
void insert(int length, int arr[], int value) {
    int idx = searchIndex(length, arr, value);
    shiftRight(length, arr, idx);
    arr[idx] = value;
}
void insertionSort(int length, int arr[]) {
    int i;
    for (i=1; i < length; i++) {
        insert(i, arr, arr[i]);
    }
}