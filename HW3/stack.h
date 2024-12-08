#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack 
{
    private:
        Node<double>* _top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();
        bool empty();
        size_t size();
        void push(double);
        double pop();
        double top();
};

Stack::Stack() 
{
    _top = nullptr;
    stackSize = 0;
}

Stack::~Stack() 
{
    while(!empty()) {
        pop();
    }
}

bool Stack::empty() 
{
    return _top == nullptr;
}

size_t Stack::size() 
{
    return stackSize;
}

void Stack::push(double data) 
{
    Node<double>* newNode = new Node<double>();
    newNode->setData(data);
    newNode->setNext(_top);
    _top = newNode;
    stackSize++;
}

double Stack::top() 
{
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return nan("");
    }
    return _top->getData();
}

double Stack::pop() 
{
    if (empty()) {
        cerr << "Error: Stack is empty.\n";
        return nan("");
    }
    double data = _top->getData();
    Node<double>* temp = _top;
    _top = _top->getNext();
    delete temp;
    stackSize--;
    return data;
}