#include<bits/stdc++.h>
using namespace std;

bool issum(vector<int>& arr, int n, int sum, vector<int>& res) {
    if (sum == 0) {
        // Print the current subset
        cout << "Subset: ";
        for (int x : res) cout << x << " ";
        cout << endl;
        return true;
    }
    if (n == 0) return false;
    bool found = false;
    // If last element is greater than sum, ignore it
    if (arr[n - 1] > sum) {
        return issum(arr, n - 1, sum, res);
    }
    // Include the last element
    res.push_back(arr[n - 1]);
    found = issum(arr, n - 1, sum - arr[n - 1], res) || found;
    res.pop_back();
    // Exclude the last element
    found = issum(arr, n - 1, sum, res) || found;
    return found;
}

int main(){
    int n;
    cout<<"enter the number of elemts in the array: ";
    cin>>n;
    vector<int>res;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int sum;
    cin>>sum;
    bool ans=issum(arr,n,sum,res);
    if(ans){
        cout<<"Yes, there is a subset with the given sum."<<endl;
    } else {
        cout<<"No, there is no subset with the given sum."<<endl;   
    }
}