#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n){
    if(n <= 1) return;

    insertion(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while(j >= 0 && arr[j] > last){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}


int main(){
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    int n=sizeof(arr)/sizeof(arr[0]);

    insertion(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}