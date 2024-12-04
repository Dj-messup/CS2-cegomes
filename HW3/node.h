#pragma once

template <typename T>
class Node {
private:
    T _data;                // Data stored in the node
    Node<T>* _next;         // Pointer to the next node

public:
    Node(T data, Node<T>* next = nullptr);
    void setData(T data);
    void setNext(Node<T>* next);
    T getData();
    Node<T>* getNext();
};

// Constructor: Initialize a node with data and next pointer
template <typename T>
Node<T>::Node(T data, Node<T>* next) : _data(data), _next(next) {}

// Set the data stored in the node
template <typename T>
void Node<T>::setData(T data) {
    _data = data;
}

// Set the next node pointer
template <typename T>
void Node<T>::setNext(Node<T>* next) {
    _next = next;
}

// Get the data stored in the node
template <typename T>
T Node<T>::getData() {
    return _data;
}

// Get the next node pointer
template <typename T>
Node<T>* Node<T>::getNext() {
    return _next;
}
