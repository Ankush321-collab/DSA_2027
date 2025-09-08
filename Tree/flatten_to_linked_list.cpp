#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* nrt = NULL;

void flatten(TreeNode* root) {
    if (root == NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->left = NULL;
    root->right = nrt;
    nrt = root;
}

// Helper to print flattened list
void printList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Example tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    cout << "Flattened Tree (Linked List): ";
    printList(root);

    return 0;
}
