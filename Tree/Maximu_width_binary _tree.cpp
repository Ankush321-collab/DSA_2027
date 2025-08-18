#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    long long ans = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        long long left = q.front().second;
        long long right = q.back().second;
        ans = max(ans, right - left + 1);
        for (int i = 0; i < size; i++) {
            auto node = q.front(); q.pop();
            long long idx = node.second - left; // prevent overflow
            if (node.first->left) q.push({node.first->left, 2 * idx});
            if (node.first->right) q.push({node.first->right, 2 * idx + 1});
        }
    }
    return (int)ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    cout << "Maximum width of the binary tree: " << widthOfBinaryTree(root);
    return 0;
}
