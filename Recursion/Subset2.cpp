#include<bits/stdc++.h>
using namespace std;

void sub(vector<int>&nums, vector<int>&ans, int i, vector<vector<int>>&res){

    if(i==nums.size()){
        // Base case: if we have considered all elements
        res.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    sub(nums,ans,i+1,res);
    
    //vbacktrack
    ans.pop_back();

    
    //to track previos elemts equal we will assign indx=i+1;
    int indx=i+1;
    while(indx<nums.size() && nums[indx]==nums[indx-1]){
        indx++;
    }
    sub(nums,ans,indx,res);
    // Backtrack to explore the next possibility without the current element
}



vector<vector<int>>subsetsum(vector<int>&nums){
    int n=nums.size();
    vector<int>ans;
    vector<vector<int>>res;
    sub(nums,ans,0,res);
    return res;


}

int main(){
    int n;
    cout<<"enter the elemts of n:";
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>>answer= subsetsum(nums);
    cout << "Subsets are: " << endl;
    for(auto i:answer){
        cout<<"{ ";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;

}