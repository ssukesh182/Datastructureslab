#ifndef STACK_SLL_H
#define STACK_SLL_H

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
        if (!top) return '\0';
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        return top ? top->data : '\0';
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top) pop();
    }
};

#endif
