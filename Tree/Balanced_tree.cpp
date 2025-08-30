#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// function to check balance and return height
int tree(TreeNode* root) {
    if (root == NULL) return 0;

    int lh = tree(root->left);
    if (lh == -1) return -1;

    int rh = tree(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    return tree(root) != -1;
}

int main() {
    // Example Tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    if (isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is Not Balanced\n";

    return 0;
}
