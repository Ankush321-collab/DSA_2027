#include <iostream>
using namespace std;

void rotateLeft(int arr[], int n,int k) {
    int first = arr[0]; // Store the first element
    
    // Shift elements to the left
    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k]; // Shift each element to the left
    }
    
    // Place the first element at the end of the array
    arr[n - 1] = first;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1,7,3,4,2};
    int n = 5;
    
    
    // Print original array
    cout << "Original array: ";
    print(arr, n);
    
    // Rotate the array to the left
    rotateLeft(arr, n,3);
    /*rotateLeft(arr, n);
    rotateLeft(arr, n);*/
    
    // Print rotated array
    cout << "Left-shifted array: ";
    print(arr, n);
    
    return 0;
}
