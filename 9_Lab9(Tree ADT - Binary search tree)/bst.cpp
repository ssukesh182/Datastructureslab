// C_BST_Menu.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return val < node->data ? search(node->left, val) : search(node->right, val);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void search(int val) {
        cout << (search(root, val) ? "Found\n" : "Not Found\n");
    }
};

int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
