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

int search(vector<int>& inorder, int l, int r, int v) {
    for (int i = l; i <= r; i++) {
        if (inorder[i] == v) {
            return i;
        }
    }
    return -1;
}

Node* pretree(vector<int>& preorder, vector<int>& inorder, int& p, int l, int r) {
    if (l > r) return NULL;

    Node* root = new Node(preorder[p]);
    p++;

    int inindx = search(inorder, l, r, root->data);

    root->left = pretree(preorder, inorder, p, l, inindx - 1);
    root->right = pretree(preorder, inorder, p, inindx + 1, r);

    return root;
}

Node* tree(vector<int>& preorder, vector<int>& inorder) {
    int preindx = 0;
    return pretree(preorder, inorder, preindx, 0, inorder.size() - 1);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = tree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
