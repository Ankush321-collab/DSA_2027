#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int v){
        data=v;
        left=right=NULL;
    }
};

int ans(Node* root,int key){
    int floor=-1;

    while(root){

        if(root->data==key){
            floor=root->data;
            return floor;

        }
        if(root->data<key){
          
            root=root->right;
        }
        else{
              floor=root->data;
            root=root->left;
        }
    }
    return floor;
}

int main(){
    Node* root=new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left =new  Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key=7;

    int res=ans(root,key);

    cout<<"answer is:"<<res;
    return 0;
}