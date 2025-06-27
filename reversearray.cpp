#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"enter the number of terms";
    cin>>n;

int arr[n];
    cout<<"enter the elemts of an array:"<<" ";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    //revresing an array
    cout<<"reversed array is:"<<endl;
    for(int i=n;i>0;i--){
        cout<<arr[i];
    }
}