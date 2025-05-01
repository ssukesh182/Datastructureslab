#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(char ch) {
        Node* newNode = new Node{ch, top};
        top = newNode;
    }

    char pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    void display() {
        Node* temp = top;
        if (!temp) {
            cout << "Stack is empty\n";
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) pop();
    }
};

int main() {
    Stack s;
    int choice;
    char ch;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> ch;
                s.push(ch);
                break;
            case 2:
                cout << "Popped: " << s.pop() << endl;
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}

