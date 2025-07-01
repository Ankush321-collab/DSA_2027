#include<bits/stdc++.h>
using namespace std;


bool issafe(vector<string>&b,int r,int col,int n){

    //checking in vertical

    for(int i=0;i<n;i++){
        if(b[i][col]=='Q'){
            return false;
        }
    }

    //checking in horizontal
    for(int j=0;j<n;j++){
        if(b[r][j]=='Q'){
            return false;
        }
    }

    //left diagonal
    for (int i=r,j=col;j>=0 &&i>=0;i--,j--){
        if(b[i][j]=='Q'){
            return false;
        }

    }

    //right diagonal

    for(int i=r,j=col;i>=0 &&j<n;j++,i--){
        if(b[i][j]=='Q'){
            return false;
        }
    }
        return true;
    
    
        /* code */

    

}


void nqueen(vector<string>&b,vector<vector<string>>&ans,int n,int r){
  

    if(r==n){
        ans.push_back({b});
        return;

    }


    for(int i=0;i<n;i++){
        if(issafe(b,r,i,n)){
            b[r][i]='Q';
            nqueen(b,ans,n,r+1);
            //backtracking
            b[r][i]='.';
        }
    }
}


vector<vector<string>> solveNQueens(int n){
  vector<string>b(n,string(n,'.'));
  vector<vector<string>>ans;

  nqueen(b,ans,n,0);
  return ans;

}

int main(){
    int n;
    cout<<"enter the number n:";
    cin>>n;

    vector<vector<string>>ans=solveNQueens(n);

    for(auto i:ans){
        cout<<"["<<"";
        for(auto j:i){
            cout<<j<<','<<'"';

        }
        cout<<"]"<<endl;
    }
    return 0;
}