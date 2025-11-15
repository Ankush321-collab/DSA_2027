#include <bits/stdc++.h>
using namespace std;

void mergeArr(vector<int>& arr, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    vector<int> temp;

    while(i <= mid && j <= r) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    if(i > mid) {
        while(j <= r) {
            temp.push_back(arr[j]);
            j++;
        }
    } else {
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
    }

    for(int x = 0; x < temp.size(); x++) {
        arr[l + x] = temp[x];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeArr(arr, l, mid, r);
    }
}

int main() {
    vector<int> arr = {10, 5, 30, 15, 7};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
