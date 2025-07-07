#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<int>&arr,int n,int m,int mid){
    int painter=1;
    int wall=0;

    for(int i=0;i<n;i++){
        if(arr[i]>mid)return false;

        if(arr[i]+wall<=mid){;
            wall+=arr[i];
        }
        else{
            painter++;
            wall=arr[i];
        }
    }
    return painter>m?false:true;
}


int painter(vector<int>&arr,int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int s=0,e=sum;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;

        if(isvalid(arr,n,m,mid)){
            ans=mid;
            //we will get our answer in left side
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int>arr={10,10,10,10};
    int n=4;
    int m=2;

    int ans=painter(arr,n,m);
    cout<<"anser:"<<ans;
}
