#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    // Start with empty list
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    // Keep track of current node we're deleting
    Node<T1>* current = _head;
    
    // Delete nodes one by one
    while (current != nullptr) {
        Node<T1>* next = current->getNext();  // Save next before deleting
        delete current;
        current = next;
    }

    // Clean up pointers just to be safe
    _head = nullptr;
    _tail = nullptr;
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    // Need to check both head and tail are nullptr
    // A properly maintained list should have both null or both non-null
    return (_head == nullptr && _tail == nullptr);
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;  // Track size as we add/remove
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    // Make new node to add
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    
    // Connect it to the front
    newNode->setNext(_head);
    
    if (_head != nullptr) {
        // List not empty, fix previous pointer
        _head->setPrev(newNode);
    } else {
        // List was empty, new node is also tail
        _tail = newNode;
    }
    
    _head = newNode;  // New node is now front
    listSize++;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (empty()) {
        cout << "List is empty!" << endl;
        return 0;  // Return 0 for empty list
    }
    return _head->getData();
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::pop_front()
{
    if (empty()) {
        cout << "List is empty!" << endl;
        return 0;  // Return 0 for empty list
    }

    // Save the value to return
    T1 value = _head->getData();
    Node<T1>* oldHead = _head;

    // Move head to next node
    _head = _head->getNext();
    
    if (_head != nullptr) {
        _head->setPrev(nullptr);  // New front has no previous
    } else {
        _tail = nullptr;  // List now empty
    }

    delete oldHead;
    listSize--;
    return value;
}

// add an element to the end of the list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    // Make new node
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    
    // Handle empty list case
    if (_tail == nullptr) {
        _head = newNode;
        _tail = newNode;
    } else {
        // Connect to current tail
        newNode->setPrev(_tail);
        _tail->setNext(newNode);
        _tail = newNode;
    }
    
    listSize++;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (empty()) {
        cout << "List is empty!" << endl;
        return 0;  // Return 0 for empty list
    }
    return _tail->getData();
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::pop_back()
{
    if (empty()) {
        cout << "List is empty!" << endl;
        return 0;  // Return 0 for empty list
    }

    T1 value = _tail->getData();
    Node<T1>* oldTail = _tail;

    // Update tail
    _tail = _tail->getPrev();
    
    if (_tail != nullptr) {
        _tail->setNext(nullptr);
    } else {
        _head = nullptr;  // List now empty
    }

    delete oldTail;
    listSize--;
    return value;
}

// overloading <<, print space separated elements
template <class T1>
ostream& operator<<(ostream& os, const List<T1>& list)
{
    // Start at front and print each element
    Node<T1>* current = list._head;
    while (current != nullptr) {
        os << current->getData();
        if (current->getNext() != nullptr) {
            os << " ";  // Space between elements
        }
        current = current->getNext();
    }
    return os;
}

// Check if two lists are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    // Different sizes means not equal
    if (listSize != rhs.listSize) {
        return false;
    }

    // Check each node
    Node<T1>* current = _head;
    Node<T1>* otherCurrent = rhs._head;
    
    while (current != nullptr) {
        // If any values different, lists not equal
        if (current->getData() != otherCurrent->getData()) {
            return false;
        }
        current = current->getNext();
        otherCurrent = otherCurrent->getNext();
    }
    
    return true;  // Made it through whole list, must be equal
}