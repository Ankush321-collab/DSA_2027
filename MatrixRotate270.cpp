#include<iostream>
using namespace std;


void rotate270(int matrix[][100],int n){
    //transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          swap(matrix[i][j].matrix[j][i]);
        }
    }

    for(int i=0)



}
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
        cout<<arr[n-1-j][i];//rotate 2703
        
       }
       cout<<endl;
}   

return 0;
}