#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) {
        val = _val;
        left = right = next = NULL;
    }
};

Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();
            if(i == n - 1) curr->next = NULL;
            else curr->next = q.front();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return root;
}

int main() {
    // Create example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Connect next pointers
    connect(root);

    // Print levels using next pointers
    Node* level = root;
    while(level){
        Node* curr = level;
        while(curr){
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
        level = level->left; // go to next level
    }

    return 0;
}

