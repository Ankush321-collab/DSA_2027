#include<bits/stdc++.h>
using namespace std;


vector<int> soly(vector<int>&arr1,vector<int>&arr2){
    int n=arr2.size();
    unordered_map<int,int>mp;
        stack<int>st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<arr2[i]){
            st.pop();
        }
        if(st.empty() ||st.top()<arr2[i])mp[arr2[i]]=-1;
        else mp[arr2[i]]=st.top();
        st.push(arr2[i]);
    }

    vector<int>solu;
    int m=arr1.size();
    for(int i=0;i<m;i++){
        solu.push_back(mp[arr1[i]]);
    }
    return solu;

}
int main(){
    vector<int>arr1 = {2,4};
    vector<int>arr2 = {1,2,3,4};

    vector<int>ans=soly(arr1,arr2);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}