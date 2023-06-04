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
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// AVL tree class
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    // Get the height of a node
    int getHeight(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    //update height of each node
    int updateHeight(Node *root)
    {
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    // Perform right rotation
    Node* rightRotate(Node* root) {
        Node* new_root = root->left;
        Node* temp = new_root->right;

        new_root->right = root;
        root->left = temp;

        root->height = updateHeight(root);
        new_root->height = updateHeight(new_root);

        return new_root;
    }

    // Perform left rotation
    Node* leftRotate(Node* root) {
        Node* new_root = root->right;
        Node* temp = new_root->left;

        new_root->left = root;
        root->right = temp;

        root->height = updateHeight(root);
        new_root->height = updateHeight(new_root);
        return new_root;
    }

    // Insert a node into the AVL tree
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return new Node(value);

        if (value < root->value)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        root->height = updateHeight(root);

        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && value < root->left->value)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && value > root->right->value)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && value > root->left->value) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && value < root->right->value) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Inorder traversal of the AVL tree
    void inorder(Node* root) {
        if (root+) {
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
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