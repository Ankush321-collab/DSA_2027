#include<iostream>
using namespace std;

int main(){
    int n;
cout<<"enter the value of n";
cin>>n;
int arr[n][n];

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
        cout<<arr[n-1-i][n-1-j];//rotate 180
        
       }
       cout<<endl;
}   

return 0;
}