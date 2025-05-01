#include <iostream>
#include <string>
#include "stack_sll.h"
#include <stack>
using namespace std;

bool checkBalanceSLL(const string &expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.isEmpty()) return false;
            s.pop();
        }
    }
    return s.isEmpty();
}

bool checkBalanceSTL(const string &expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n1. Check Balance\n2. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter string with parentheses: ";
                cin >> input;

                bool result1 = checkBalanceSLL(input);
                bool result2 = checkBalanceSTL(input);

                cout << "Using SLL Stack: " << (result1 ? "Balanced" : "Not Balanced") << endl;
                cout << "Using STL Stack: " << (result2 ? "Balanced" : "Not Balanced") << endl;
                break;

            case 2: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 2);

    return 0;
}
