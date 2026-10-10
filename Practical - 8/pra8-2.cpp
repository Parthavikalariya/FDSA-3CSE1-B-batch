#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Print values in ascending order
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, code;

    cout << "Enter number of book codes: ";
    cin >> n;

    cout << "Enter book codes: ";
    for (int i = 0; i < n; i++) {
        cin >> code;
        root = insert(root, code);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    return 0;
}
