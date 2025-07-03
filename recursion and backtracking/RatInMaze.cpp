#include <bits/stdc++.h>
using namespace std;

void solver(vector<vector<int>>& mat, vector<string>& ans, string d, vector<vector<bool>> vis, int r, int c) {
    int n = mat.size();
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c]==true) {
        return;
    }

    if (r == n - 1 && c == n - 1) {
        ans.push_back(d);
        return;
    }

    vis[r][c] = true;

    // Up
    solver(mat, ans, d + 'U', vis, r - 1, c);
    // Down
    solver(mat, ans, d + 'D', vis, r + 1, c);
    // Left
    solver(mat, ans, d + 'L', vis, r, c - 1);
    // Right
    solver(mat, ans, d + 'R', vis, r, c + 1);

    vis[r][c] = false;
}

vector<string> path(vector<vector<int>>& mat) {
    vector<string> ans;
    int n = mat.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    if (mat[0][0] == 1) {
        solver(mat, ans, "", vis, 0, 0);
    }
    return ans;
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};

    vector<string> res = path(mat);

    for (auto i : res) {
        cout << i << " ";
    }

    return 0;
}
