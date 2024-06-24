#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to find the minimum value node in a subtree
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteValue(Node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) return root;

    // Recursive case: traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteValue(root->left, key);
    } else if (key > root->data) {
        root->right = deleteValue(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteValue(root->right, temp->data);
    }

    return root;
}

// Helper function to perform inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder traversal of the given tree: ";
    inorder(root);
    cout << endl;

    cout << "\nDelete 20\n";
    root = deleteValue(root, 20);
    cout << "Inorder traversal of the modified tree: ";
    inorder(root);
    cout << endl;

    cout << "\nDelete 30\n";
    root = deleteValue(root, 30);
    cout << "Inorder traversal of the modified tree: ";
    inorder(root);
    cout << endl;

    cout << "\nDelete 50\n";
    root = deleteValue(root, 50);
    cout << "Inorder traversal of the modified tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
