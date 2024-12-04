#pragma once
#include "node.h"
#include <iostream>

using namespace std;

class Stack {
private:
    Node<double>* _top;  // Points to the top of the stack
    size_t stackSize;

public:
    Stack();
    ~Stack();
    bool empty();
    size_t size();
    void push(double data);
    double pop();
    double top();
};

// Constructor: Initialize an empty stack
Stack::Stack() : _top(nullptr), stackSize(0) {}

// Destructor: Clean up all stack elements
Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

// Check if the stack is empty
bool Stack::empty() {
    return _top == nullptr;
}

// Get the size of the stack
size_t Stack::size() {
    return stackSize;
}

// Push a new element onto the stack
void Stack::push(double data) {
    Node<double>* newNode = new Node<double>(data, _top);
    _top = newNode;
    stackSize++;
}

// Get the top element without removing it
double Stack::top() {
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return 0;  // Return 0 for simplicity
    }
    return _top->getData();
}

// Remove and return the top element
double Stack::pop() {
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return 0;  // Return 0 for simplicity
    }
    double data = _top->getData();
    Node<double>* temp = _top;
    _top = _top->getNext();
    delete temp;
    stackSize--;
    return data;
}
