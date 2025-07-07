#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<int>&arr,int n,int m,int mid){
    int std=1;//student will be sure atleat one
    int pages=0;//pages will be start to 0 to sum

    for(int i=0;i<n;i++){
        if(arr[i]>mid)return false;

        if(arr[i]+pages<=mid){
            pages+=arr[i];
        }
        else{
            std++;
            pages=arr[i];
        }
    }
    return std>m?false:true;

}

int book(vector<int>&arr,int n,int m){
    if(m>n)return -1;

    //now we have to find sum to find maximum length of arr 1to sum

    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

    }


    int s=0,e=sum;
    int ans=0;

    while(s<=e){
        int mid=(s+e)/2;
       

        if(isvalid(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        s=mid+1;
    }
    return ans;
}



int main(){
    vector<int>arr={25, 46, 28, 49, 24};
    int n=5;//number of books
    int m=4;//number of students


    int ans=book(arr,n,m);
    cout<<ans;
}
