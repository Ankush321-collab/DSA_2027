#include<bits/stdc++.h>
using namespace std;



bool toposort(vector<vector<int>>&adj,vector<int>&indegree){

    int n=adj.size();
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;

        for(auto i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }

    }
    if(cnt==n)return false;
    return true;
    
    
}


int main(){
    int n;
    int m;
    cout<<"enter the nu,mber of nodes:";
    cin>>n;
    cout<<"enter the number of edges:";
    cin>>m;
    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    cout<<"enter "<<m<<" edges (u v):"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    if(toposort(adj, indegree))
        cout<<"Topological Sort exists"<<endl;
    else
        cout<<"Topological Sort does not exist"<<endl;  
    return 0;

}