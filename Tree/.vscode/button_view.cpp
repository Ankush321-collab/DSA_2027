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

void bottomview(Node* root){
    if(!root) return;

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto temp=q.front();
        Node* curr=temp.first;
        int ad=temp.second;

        q.pop();

        mp[ad]=curr->data;

        if(curr->left!=NULL)q.push({curr->left,ad-1});
        if(curr->right!=NULL)q.push({curr->right,ad+1});
    }

    for(auto i:mp){
        cout<<i.second<<" ";
    }
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
     root->left->right=new Node(60);
      root->left->left=new Node(40);

      bottomview(root);
      return 0;

}