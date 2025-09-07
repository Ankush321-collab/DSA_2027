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

Node* buildTreeHelper(vector<int>& postorder, int ps, int pe,
                      vector<int>& inorder, int is, int ie,
                      map<int,int>& mpp) {
    if (ps > pe || is > ie) return NULL;

    Node* root = new Node(postorder[pe]);
    int indx = mpp[root->data];
    int leftSize = indx - is;

    root->left = buildTreeHelper(postorder, ps, ps + leftSize - 1, inorder, is, indx - 1, mpp);
    root->right = buildTreeHelper(postorder, ps + leftSize, pe - 1, inorder, indx + 1, ie, mpp);

    return root;
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder) {
    if (postorder.size() != inorder.size()) return NULL;

    map<int,int> mpp;
    for (int i = 0; i < inorder.size(); i++) {
        mpp[inorder[i]] = i;
    }

    return buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(postorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
