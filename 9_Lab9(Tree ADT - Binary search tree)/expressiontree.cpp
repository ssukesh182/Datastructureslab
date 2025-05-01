// D_ExpressionTree.cpp
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
    TreeNode* root;

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '=';
    }

    void inorder(TreeNode* node) {
        if (node) {
            if (isOperator(node->data)) cout << "(";
            inorder(node->left);
            cout << node->data;
            inorder(node->right);
            if (isOperator(node->data)) cout << ")";
        }
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    ExpressionTree() : root(nullptr) {}

    void constructTree(string postfix) {
        stack<TreeNode*> st;
        for (char c : postfix) {
            if (!isOperator(c)) {
                st.push(new TreeNode(c));
            } else {
                TreeNode* right = st.top(); st.pop();
                TreeNode* left = st.top(); st.pop();
                TreeNode* node = new TreeNode(c);
                node->left = left;
                node->right = right;
                st.push(node);
            }
        }
        root = st.top();
    }

    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    ExpressionTree et;
    string postfix;
    int choice;

    while (true) {
        cout << "\n1.Postfix Expression\n2.Construct Expression Tree\n3.Preorder\n4.Inorder\n5.Postorder\n6.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                et.constructTree(postfix);
                cout << "Expression tree constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                et.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                et.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                et.postorder();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
