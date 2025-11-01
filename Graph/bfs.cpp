#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<vector<int>>&adj,int n){

    vector<bool>vis(n,0);

    queue<int>q;
    q.push(s);
    vis[s]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }

    }


}

int main(){
    int n=5;
    vector<vector<int>>adj(n);

    adj[0]={1,2};
    adj[1]={0,2,3};
    adj[2]={0,1,4};
    adj[3]={1,4};
    adj[4]={2,3};
    bfs(0,adj,n);
    return 0;

}