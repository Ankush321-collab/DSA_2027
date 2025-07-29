#include<bits/stdc++.h>
using namespace std;
vector<int>prevsmaller(vector<int>&arr,int n){
    stack<int>st;
    vector<int>ans(n);

    st.push(-1);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}

int main(){
    vector<int>arr={4,5,2,10,8};
    int n=arr.size();

    vector<int>ans=prevsmaller(arr,n);

    for(auto i:ans){
        cout<<i<<" ";       
    }
    cout<<endl;
    return 0;
}