#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int>& arr, int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}


int main(){

    int n;
    cout<<"enter the number of elemnts:";
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        arr[i]=cin.get();
        
    }
    bubble(arr,n);
    return 0;
 

}
