// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
  int solve(int indx, int n, vector<int> &price, vector<vector<int>>&dp) {
      if (indx == 0) {
          return n * price[0];
      }
      if(dp[indx][n]!=-1)return dp[indx][n];

      int nottaken = solve(indx - 1, n, price,dp);
      int take = INT_MIN;

      int rodlength = indx + 1;

      if (rodlength <= n) {
          take = price[indx] + solve(indx, n - rodlength, price,dp);
      }

      return dp[indx][n]=max(take, nottaken);
  }

  int main(){
    vector<int>price={1,5,8,9,10,17,17,20};
    
    int n = price.size();
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
      int ans= solve(n - 1, n, price,dp);

      cout<<ans;
  }


      
