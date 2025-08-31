#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int d){
        val=d;
        left=right=NULL;
    }
};

bool issame(Node* p,Node* q){
    if(p==nullptr && q==nullptr)return true;
    if(p==nullptr || q==nullptr) return false;

    if(p->val!=q->val);

    issame(p->left,q->left) && issame(p->right,q->right);
}


int main(){
    Node* p=new Node(1);
    p->left=new Node(2);
    p->right=new Node(3);

    Node* q=new Node(1);
    q->left=new Node(2);
    q->right=new Node(3);

    if(issame(p,q)){
        cout<<"Same tree is aboved";
    }
    else{
        cout<<"not same tree";
    }
    return 0;
}