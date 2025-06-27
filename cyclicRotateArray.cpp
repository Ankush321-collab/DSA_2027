#include<iostream>
using namespace std;


void rotate(int arr[],int n){

    int last=arr[n-1];

    //rotating the array except last one
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i-1];
    }

    //rotating last elemts
    arr[0]=last;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n=5;

cout<<"array before rotated:"<<endl;
    print(arr,n);
    rotate(arr,n);
    rotate(arr,n);
    cout<<"array after rotating:"<<endl;
    print(arr,n);
}