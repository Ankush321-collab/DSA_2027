#include<iostream>
using namespace std;

void PrintUnion(int arr1[], int arr2[], int m, int n) {
    int i = 0;
    int j = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        }
         else if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        } 
        else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    // Print remaining elements of the larger array
    while (i < m) {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n) {
        cout << arr2[j] << " ";
        j++;
    }
}

int main() {
    int arr1[5] = {1, 3, 4, 5, 7};
    int arr2[4] = {2, 3, 5, 6};

    int n = 5;
    int m = 4;

    PrintUnion(arr1, arr2, m, n);
    return 0;
}
