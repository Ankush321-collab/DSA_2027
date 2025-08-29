#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* root, int &res) {
    if (root == nullptr) return 0;

    int lh = helper(root->left, res);
    int rh = helper(root->right, res);

    res = max(res, lh + rh);         // update diameter (in edges)
    return max(lh, rh) + 1;          // return height
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    int result = 0;
    helper(root, result);
    return result;
}

int main() {
    // Example tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
