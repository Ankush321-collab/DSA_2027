#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isabc(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isabc(p->left, q->right) && isabc(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return isabc(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        cout << "Tree is symmetric" << endl;
    } else {
        cout << "Tree is not symmetric" << endl;
    }

    return 0;
}
