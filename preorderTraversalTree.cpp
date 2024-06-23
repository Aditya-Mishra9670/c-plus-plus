#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a Node and initialize it
void preorder(struct Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node* createNode(int value) {
    struct Node* n = new Node;
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

int main() {
    struct Node* p = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(0);
    struct Node* p3 = createNode(5);
    struct Node* p4 = createNode(2);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    preorder(p);
    return 0;
}
