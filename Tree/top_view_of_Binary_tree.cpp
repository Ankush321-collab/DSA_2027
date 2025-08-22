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

void topview(Node* root){
    if(!root) return;

    map<int,int>mp;
    queue<pair<Node*,int>>q;  //node value and it address
    q.push({root,0});

    while(!q.empty()){
        auto temp=q.front();
        Node* node=temp.first;
        int ad=temp.second;
        q.pop();

        if(mp.find(ad)==mp.end()){
            mp[ad]=node->data;
        }
        if(node->left!=NULL)q.push({node->left,ad-1});
        if(node->right!=NULL)q.push({node->right,ad+1});
    }
    for(auto it:mp){
        cout<<it.second<<" ";
    }
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->right=new Node(5);
    root->right->left=new Node(4);

    topview(root); 
    return 0;
}

