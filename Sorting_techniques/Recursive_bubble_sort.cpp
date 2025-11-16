#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    if(n == 1) return;

    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {10,5,30,15,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
