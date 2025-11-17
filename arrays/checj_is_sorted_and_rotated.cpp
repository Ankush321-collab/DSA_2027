#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&arr){
    int n=arr.size();
    int count=0;

    for(int i=0;i<n;i++){
        if(arr[i]<arr[(i+1)%n])count++;
    }
    if(count>1)return false;
    return true;

}

int main(){
    vector<int>arr={3,4,5,1,2};
    int n=arr.size();
    bool isSortedAndRotated=check(arr);
    if(isSortedAndRotated){
        cout<<"The array is sorted and rotated"<<endl;
    }else{
        cout<<"The array is not sorted and rotated"<<endl;
    }
    return 0;
}