#include <bits/stdc++.h>
using namespace std;

bool check(int s, int color, vector<vector<int>>& adj, vector<int>& clr) {
    clr[s] = color;
    for (auto i : adj[s]) {
        if (clr[i] == -1) {
            if (!check(i, 1 - color, adj, clr))
                return false;
        } 
        else if (clr[i] == color) {
            return false;
        }
    }
    return true;
}

bool isbipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> clr(n, -1);

    for (int i = 0; i < n; i++) {
        if (clr[i] == -1) {
            if (!check(i, 0, adj, clr))
                return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isbipartite(adj))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;

    return 0;
}
