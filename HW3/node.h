#pragma once

template <typename T>
class Node {
private:
    T _data;                // The data in this node
    Node<T>* _next;         // Pointer to the next node

public:
    Node(T data, Node<T>* next = nullptr); // Make a node
    void setData(T data);                  // Change the data
    void setNext(Node<T>* next);           // Change the next node
    T getData();                           // Get the data
    Node<T>* getNext();                    // Get the next node
};

// Make a node with some data
template <typename T>
Node<T>::Node(T data, Node<T>* next) : _data(data), _next(next) {}

// Change the data in the node
template <typename T>
void Node<T>::setData(T data) {
    _data = data;
}

// Change the next pointer
template <typename T>
void Node<T>::setNext(Node<T>* next) {
    _next = next;
}

// Get the data from the node
template <typename T>
T Node<T>::getData() {
    return _data;
}

// Get the next node
template <typename T>
Node<T>* Node<T>::getNext() {
    return _next;
}
