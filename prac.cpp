#include<iostream>
using namespace std;

int sum(int arr[],int n,int k){
   
  int count=0;
    for(int i=0;i<n;i++){
         int sum=0;
        int j=i;

        while(sum!=k){
            sum+=arr[j];
            j++;

        }
        if(sum==k){
            count++;
        }

    }
    return count;
}


int main(){
    int arr[6]={9,4,20,3,10,5};
    int k=33;

    int res=sum(arr,6,k);
    cout<<res<<endl;
}