#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<int>&arr,int n,int m,int maxi){
    int std=1;
    int pages=0;

    for(int i=0;i<n;i++){

        if(arr[i]>maxi){
            return false;
        }
        if(arr[i]+pages<=maxi){
            pages+=arr[i];
        }
        else{
            std++;
            pages=arr[i];
        }
    }
    return std>m?false:true;
}

int allocate(vector<int>&arr,int n,int m){
    if(m>n){
        return -1;
    }
  int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

    }

    int s=0;
    int e=sum;
    int ans=0;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(isvalid(arr,n,m,mid)){
            ans=mid;
             e=mid-1;
        }
        else{
            s=mid+1;
         
        }
        
    }
  return ans;

}


int main(){
    vector<int>arr={4, 2, 1, 3, 6};
    int n=5; int m=2;


    cout<<allocate(arr,n,m);
}