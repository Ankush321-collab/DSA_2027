#include<bits/stdc++.h>
using namespace std;


void helper(vector<vector<int>>&mat,int i,int j,string path,vector<string>&ans,vector<vector<bool>>&vis){
    int n=mat.size();
    int m=mat[0].size();
    
    

    if(n==0 ||m==0 ||i<0 ||j<0 ||i>n-1 ||j>m-1 ||mat[i][j]==0 ||vis[i][j]==true){
        return;
    }
    if(i==n-1 &&j==m-1){
        ans.push_back({path});
    }
    vis[i][j]=true;
  //down
    helper(mat,i+1,j,path+'D',ans,vis);
    //up
    helper(mat,i-1,j,path+'U',ans,vis);
    //left
    helper(mat,i,j-1,path + 'L',ans,vis);
    helper(mat,i,j+1,path+'R',ans,vis);

    mat[i][j]=false;//mark as visited
    
}

vector<string>findpath(vector<vector<int>>&mat){
 vector<string>ans;
 int n=mat.size();
 string path="";
 vector<vector<bool>>vis(n,vector<bool>(n,false));
 helper(mat,0,0,path,ans,vis);
 return ans;
    
}


int main(){
    vector<vector<int>>mat={{1,0,0,0},
                            {1,1,0,1},
                            {1,1,0,0},
                            {0,1,1,1}};
    vector<string>res=findpath(mat);
    
    for(string i:res){
        cout<<i<<" ";
    }

}