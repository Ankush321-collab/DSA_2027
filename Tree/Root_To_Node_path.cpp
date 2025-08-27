#include<bits/stdc++.h>
using namespace std;


struct Node{
   int data;
   Node* left;
   Node* right;
   
   Node(int d){
    data=d;
    left=right=NULL;
   }
};


bool getpath(Node* root,vector<int>& arr,int b){
    if(!root){
        return false;
    }
    arr.push_back(root->data);

    if(root->data==b){
        return true;
    }

    if(getpath(root->left,arr,b) ||getpath(root->right,arr,b)){
        return true;
    }
    arr.pop_back();
    return false;

}

vector<int>solve(Node* a,int b){
    vector<int>arr;
    if(a==NULL){
        return arr;
    }
    getpath(a,arr,b);
    return arr;
}

int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
        root->left->right->right = new Node(7);



    int a=7;

    vector<int>ans=solve(root,a);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;

}