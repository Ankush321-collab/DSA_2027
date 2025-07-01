#include<bits/stdc++.h>
using namespace std;




void fun(vector<int>&nums,vector<vector<int>>&res,int ind){
    int n=nums.size();
    if(ind==n){
        res.push_back(nums);
        return;

    }


        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            fun(nums,res,ind+1);
            swap(nums[i],nums[ind]);
            
        
        
    }
}
vector<vector<int>>permu(vector<int>&nums){

vector<vector<int>>res;
fun(nums,res,0);
return res;
}

int main(){
    int n;
    cout<<"enter the number of n:";
    cin>>n;

    vector<int>nums;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<vector<int>>res;

    vector<vector<int>>ans=permu(nums);
    
    for(auto i:ans){
        cout<<"{"<<" ";
        for(auto j:i){
            cout<<j;

        }
        cout<<"}"<<endl;
    }
    return 0;
}