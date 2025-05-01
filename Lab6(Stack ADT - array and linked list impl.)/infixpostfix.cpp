#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include "stack_sll.h"

using namespace std;

string infix, postfix;

int precedence(char op) {
    switch (op) {
        case '=': return 1;
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 3;
        default: return 0;
    }
}

bool isLeftAssociative(char op) {
    return op != '=';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

void convertInfixToPostfix() {
    Stack stack;
    postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(')
                postfix += stack.pop();
            stack.pop();
        } else if (isOperator(ch)) {
            while (!stack.isEmpty() && isOperator(stack.peek()) &&
                   (precedence(stack.peek()) > precedence(ch) ||
                   (precedence(stack.peek()) == precedence(ch) && isLeftAssociative(ch))))
                postfix += stack.pop();
            stack.push(ch);
        }
    }

    while (!stack.isEmpty())
        postfix += stack.pop();

    cout << "Postfix: " << postfix << endl;
}

int evaluatePostfix() {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch))
            s.push(ch - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '%': s.push(a % b); break;
                case '=': s.push(b); break;
            }
        }
    }
    return s.top();
}

int main() {
    int choice;
    do {
        cout << "\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression (single-digit): ";
                getline(cin, infix);
                break;
            case 2:
                convertInfixToPostfix();
                break;
            case 3:
                cout << "Result: " << evaluatePostfix() << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
