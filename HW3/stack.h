#pragma once
#include "node.h"
#include <iostream>

using namespace std;

class Stack {
private:
    Node<double>* _top;  // The top of the stack
    size_t stackSize;    // How many items are in the stack

public:
    Stack();            // Make a new empty stack
    ~Stack();           // Delete everything in the stack
    bool empty();       // Check if the stack is empty
    size_t size();      // Get how many items are in the stack
    void push(double);  // Add a number to the stack
    double pop();       // Remove and get the top number
    double top();       // Get the top number without removing it
};

// Make an empty stack
Stack::Stack() : _top(nullptr), stackSize(0) {}

// Delete all items in the stack
Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

// Check if the stack is empty
bool Stack::empty() {
    return _top == nullptr;
}

// Get how many items are in the stack
size_t Stack::size() {
    return stackSize;
}

// Add a number to the stack
void Stack::push(double data) {
    Node<double>* newNode = new Node<double>(data, _top);
    _top = newNode;
    stackSize++;
}

// Get the top number without removing it
double Stack::top() {
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return 0;  // Return 0 if stack is empty
    }
    return _top->getData();
}

// Remove and get the top number
double Stack::pop() {
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return 0;  // Return 0 if stack is empty
    }
    double data = _top->getData();
    Node<double>* temp = _top;
    _top = _top->getNext();
    delete temp;
    stackSize--;
    return data;
}
