#include<iostream>
#include<climits>
using namespace std;

int getmax(int mat[][3],int r,int c){
    
    int maxy=INT_MIN;

    for(int i=0;i<c;i++){
        int sum=0;
        for(int j=0;j<r;j++){
            sum+=mat[j][i];

        }
        maxy=max(maxy,sum);

    }
    return maxy;

}


int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;

    int arr[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<getmax(arr,n,3);
}