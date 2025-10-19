#include<bits/stdc++.h>
using namespace std;

int kadaneAlgorithm(vector<int> arr){
   int sum=0;
   int maxi=INT_MIN;

   for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    maxi=max(maxi,sum);

    if(sum<0){
        sum=0;
    }
   }
   return maxi;
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum subarray sum is: "<<kadaneAlgorithm(arr)<<endl;
    return 0;

}