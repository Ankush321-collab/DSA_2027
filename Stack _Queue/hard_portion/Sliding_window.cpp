#include<bits/stdc++.h>
using namespace std;
vector<int>resu(vector<int>& nums, int k) {
    int n=nums.size();

    vector<int>ans;
    deque<int>dq;

    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()==i-k){//out ot window bound so pop front index
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back(); //pop last index which are less than current element
        }
        dq.push_back(i); //push current index

        if(i>=k-1)ans.push_back(nums[dq.front()]);

       
    }
     return ans;

}

int main() {  
    vector<int>nums={1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
   vector<int>ans=resu(nums,k);

   for(auto i:ans){
    cout<<i<<" ";
   }

}