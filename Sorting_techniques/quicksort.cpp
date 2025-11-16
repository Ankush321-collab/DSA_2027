#include<bits/stdc++.h>
using namespace std;

int part(int arr[], int low, int high);

void quicksort(int arr[], int low, int high){
    if(low < high){
        int loc = part(arr, low, high);
        quicksort(arr, low, loc - 1);
        quicksort(arr, loc + 1, high);
    }
}

int part(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--;

        if(i < j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

int main(){
    int arr[] = {10, 5, 30, 15, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
