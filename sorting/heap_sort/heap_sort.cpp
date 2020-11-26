#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// displays the content of the list
void print(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

// swaps the two elements via their pointers
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Depth first array layout of a tree has children at indices 2n+1 and 2n+2
// if the left and right children exist and are greater than their parent
// then the new root value should be the left or right
// *note: right will always be bigger than left so it can overwrite the left if
// if the new root is not the parent then a swap needs to be done with new root
// this function is then repeated until it decides on a stable swap arrangement
void convertHeap(vector<int> &arr, int length, int parent) {
    int root = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < length && arr[left] > arr[root]) {
        root = left;
    }

    if (right < length && arr[right] > arr[root]) {
        root = right;
    }

    if (root != parent) {
        swap(arr[parent], arr[root]);
        // recursive call to ensure stability of swaps
        convertHeap(arr, length, root);
    }
}


void heapSort(vector<int> &arr, int length) {
    // go over all the possible parent elements/nodes
    // this gets the overall root to the front of the list
    for(int i=(length/2)-1; i >= 0; i--) {
        convertHeap(arr, length, i);
    }

    print(arr);

    // go over all the elements/nodes
    // once the max value lies at the top of the heap move it to the end
    // then iterate over the list less one element and continue to convert to a heap
    for (int i = length-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        convertHeap(arr, i, 0);
    }
}

// Basic Algorithm explanation
// make a max heap of the elements in the array
// find the maximum element and then 
// largest element needs to be placed at the 'root' position
// size of heap is reduced by one
// last element of the heap to replace the value at the root
// new root is 'heapified'
// 'heapification' is done bottom up because a node can only be heaped if the values under it are already heaped
int main () {
    vector<int> arr = {1, 5, 7, 8, 12, 3, 0, 6, 11, 10};
    print(arr);
    heapSort(arr, arr.size());
    print(arr);
    return 0;
}