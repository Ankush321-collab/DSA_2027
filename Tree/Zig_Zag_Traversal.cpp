#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void zigzagTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int n = q.size();
        int arr[1000]; 
        int idx = 0;

        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            arr[idx++] = curr->data;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (level % 2 == 1) {
            reverse(arr, arr + idx);
        }

        for (int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }

        level++;
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagTraversal(root);

    return 0;
}
