#include<bits/stdc++.h>

using namespace std;


bool isvalid(vector<int>&arr,int mid,int k){
    int cnt=1;
    int last=arr[0];
    int n=arr.size();

    for(int i=0;i<n;i++){
        

        if(arr[i]-last>=mid){
             cnt++;
            last=arr[i];
        }
        if(cnt==k)return true;
    }
    return false;
}


int cows(vector<int>&arr,int n,int k){
    sort(arr.begin(),arr.end());
    int s=1,e=arr[n-1]-arr[0];
int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;

        if(isvalid(arr,mid,k)){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    return ans;

}


int main(){
    vector<int>arr={0, 3, 4, 7, 10, 9};
    int k=4;
    int n=arr.size();
    int ans=cows(arr,n,k);
    cout<<ans;
}