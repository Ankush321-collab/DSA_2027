#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void one(Node* root) {
    stack<pair<Node*, int>> s;
    vector<int> pre, in, post;

    s.push({root, 1});

    while (!s.empty()) {
        auto it = s.top();
        s.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);

            if (it.first->left != NULL) {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);

            if (it.first->right != NULL) {
                s.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }

    // Print results
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << "\n";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(6);
    root->right->right = new Node(7);

    one(root);

    return 0;
}
