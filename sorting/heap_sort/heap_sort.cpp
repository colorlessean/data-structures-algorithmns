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

int main () {
    vector<int> arr = {1, 5, 7, 8, 12, 3, 0, 6, 11, 10};
    print(arr);
    heapsort(arr, 0, arr.size()-1);
    print(arr);
    return 0;
}