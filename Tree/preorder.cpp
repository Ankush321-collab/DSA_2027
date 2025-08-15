#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    if (root == nullptr) return res;
    s.push(root);

    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        res.push_back(curr->val);

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = preorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
