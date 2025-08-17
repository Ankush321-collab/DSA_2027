#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void morrisPreorder(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Visit (print) current node
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // Find inorder predecessor
            Node* pre = curr->left;
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                // First time visiting: print before creating thread
                cout << curr->data << " ";
                pre->right = curr;      // create thread
                curr = curr->left;
            } else {
                // Thread already exists: remove it
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Preorder Traversal: ";
    morrisPreorder(root);

    return 0;
}