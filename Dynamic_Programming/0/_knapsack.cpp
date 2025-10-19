#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&val,vector<int>&wt,int cap){

    int n=val.size();
    

    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][cap];

}


int main(){

    vector<int>val={1,4,5,7};
    vector<int>wt={1,3,4,5};

   int capacity=7;

   int ans=knapsack(val,wt,capacity);
   cout<<ans;

}