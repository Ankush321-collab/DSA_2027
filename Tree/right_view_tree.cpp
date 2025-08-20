#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
    }
};





void rightview(Node* root){
    queue<Node*>q;
    if(!root) return ;

    q.push(root);

    while(!q.empty()){
        int n=q.size();

        for(int i=1;i<=n;i++){
            Node* temp=q.front();
            q.pop();

            if(i==n){
                cout<<temp->data;
            }
             if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            
           
        }
        
    }
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    root->left->right->left = new Node(6);

    rightview(root);  // Output: 1 3 4 6
    return 0;
}
