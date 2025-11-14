#include<bits/stdc++.h>
using namespace std;

void selection(vector<int>&arr,int n){

    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
    
    if(mini!=i){
        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

    
}


int main(){

    int n;
    cout<<"enter the number of elemnts:";
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        arr[i]=cin.get();
        
    }
    selection(arr,n);
    return 0;
 

}