#include<iostream>
using namespace std;

int main(){
    int arr[5]={1,5,9,7,8};
    int n=sizeof(arr)/sizeof(int);


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}