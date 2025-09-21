#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int>& in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> in;
    inorder(root, in);
    int l = 0, r = in.size() - 1;
    while (l < r) {
        if (in[l] + in[r] == k) return true;
        if (in[l] + in[r] > k) r--;
        else l++;
    }
    return false;
}

int main() {
    // Build the tree from the picture
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k;
    cout << "Enter target sum: ";
    cin >> k;

    if (findTarget(root, k))
        cout << "Pair found!" << endl;
    else
        cout << "No pair found!" << endl;

    return 0;
}
