//AVL Tree value 35,50,40,25,30,60,78,20,28

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

    // Preorder traversal of the AVL tree
    void preorder(Node* root) {
        if (root) {
            cout << root->value << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Inorder traversal of the AVL tree
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
        }
    }

    // Postorder traversal of the AVL tree
    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->value << " ";
        }
    }

    //******************************************************************//

    void printUtil(Node *root, int space, int count)
    { // using reverse inorder
        if (!root)
            return;

        // Increase distance between levels
        space += count;

        printUtil(root->right, space, count);

        cout << endl;
        for (int i = count; i < space; i++)
            cout << " ";
        cout << root->value << "\n";

        printUtil(root->left, space, count);
    }

    void print(Node *root)
    {
        if(!root){
            cout << "Tree is empty!\n";
            return;
        }
        printUtil(root, 0, 10);
    }

//******************************************************************//
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

    cout << "\nPreorder traversal of the AVL tree: ";
    avlTree.preorder(avlTree.root);
    cout << endl;
    
    cout << "Inorder traversal of the AVL tree: ";
    avlTree.inorder(avlTree.root);
    cout << endl;

    cout << "Postorder traversal of the AVL tree: ";
    avlTree.postorder(avlTree.root);
    cout << endl<<endl;

    avlTree.print(avlTree.root);

    return 0;
}