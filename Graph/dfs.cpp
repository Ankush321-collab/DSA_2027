#include <iostream>
#include <vector>
using namespace std;

void dfsSolver(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {
    vis[node] = 1;
    ans.push_back(node);
    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfsSolver(i, adj, vis, ans);
        }
    }
}

int main() {
    int n;
    cin >> n; // number of nodes
    vector<vector<int>> adj(n);

    // adjacency list input
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m; // number of neighbors of node i
        for (int j = 0; j < m; j++) {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
        }
    }

    vector<int> vis(n, 0);
    vector<int> ans;

    dfsSolver(0, adj, vis, ans); // start DFS from node 0

    cout << "DFS Traversal: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
