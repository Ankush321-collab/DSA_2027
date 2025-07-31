#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int fresh = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 2) {
                    
                    q.push({{i, j}, 0});
                }
                else  {
                    vis[i][j]==0;
                }
            }
        }

        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};

        int tm = 0;
        int cnt = 0;

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < r && ncol < c &&
                   vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                   
                }
            }
        }
       for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1 && vis[i][j]!=2) return-1;
            }
      }
      return tm;
    }
                   
      
    
};


int main(){
  vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int ans=orangesRotting(grid);

    cout<<ans;
    return 0;
}