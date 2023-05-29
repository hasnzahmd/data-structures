//AVL Tree Data 35,50,40,25,30,60,78,20,28

#include <iostream>
using namespace std;

// AVL tree node
class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};


// AVL tree class
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Perform right rotation
    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* T3 = y->right;

        y->right = z;
        z->left = T3;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Perform left rotation
    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Insert a node into the AVL tree
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Inorder traversal of the AVL tree
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }
};

int main() {
    AVLTree avlTree;

    int numNodes;
    cout << "Enter the number of nodes to insert: ";
    cin >> numNodes;

    cout << "Enter the values to insert: ";
    for (int i = 0; i < numNodes; i++) {
        int value;
        cin >> value;
        avlTree.root = avlTree.insert(avlTree.root, value);
    }

    // Inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree: ";
    avlTree.inorder(avlTree.root);
    cout << endl;

    return 0;
}