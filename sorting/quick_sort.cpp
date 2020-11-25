#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

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

// sort the list in such a way that all the elements on the left of the selected pivot are less than it and to the right are all greater than
// returns the index value of the element to partition on
int partition (vector<int> &arr, int low, int high) {
    // pivot on the highest element first
    int pivot = arr[high];
    // index of smaller element
    int i = low;
    for (int j = low; j <= high -1; j++) {
        // if current element is smaller than the pivot swap them
        if (arr[j] < pivot) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quicksort(vector<int> &arr, int low, int high) {
    if (low < high){
        // pivot index is the index of the array to be partitioned on
        int pivot_index = partition(arr, low, high);

        // now recursively partition on this index.
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1 , high);
    }
}

int main () {
    vector<int> arr = {1, 5, 7, 8, 12, 3, 0, 6, 11, 10};
    print(arr);
    quicksort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}