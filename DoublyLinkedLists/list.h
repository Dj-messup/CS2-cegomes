#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
private:
    Node<T1>* _head;
    Node<T1>* _tail;
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

    template <class T2>
    friend ostream& operator<<(ostream&, const List<T2>&);
};

// Constructor: Initialize list with nullptr and set listSize to 0
template <class T1>
List<T1>::List() : _head(nullptr), _tail(nullptr), listSize(0) {}

// Destructor: Iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    Node<T1>* current = _head;
    while (current)
    {
        Node<T1>* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    _head = _tail = nullptr;
}

// Return true if the list is empty, false otherwise
template <class T1>
bool List<T1>::empty()
{
    return _head == nullptr && _tail == nullptr;
}

// Return the number of elements in the list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// Add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    newNode->setNext(_head);

    if (_head)
        _head->setPrev(newNode);
    else
        _tail = newNode;  // Update _tail if the list was empty

    _head = newNode;
    ++listSize;
}

// Return the first element in the list
// If the list is empty, print a message and return 0
template <class T1>
T1 List<T1>::front()
{
    if (empty())
    {
        cout << "List is empty!" << endl;
        return T1();  // Return default value for type T1
    }
    return _head->getData();
}

// Remove the first element from the list and return its data
// If the list is empty, print a message and return 0
template <class T1>
T1 List<T1>::pop_front()
{
    if (empty())
    {
        cout << "List is empty!" << endl;
        return T1();  // Return default value
    }

    Node<T1>* temp = _head;
    T1 data = temp->getData();

    _head = _head->getNext();
    if (_head)
        _head->setPrev(nullptr);
    else
        _tail = nullptr;  // Update _tail if the list becomes empty

    delete temp;
    --listSize;
    return data;
}

// Add an element to the end of the list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* newNode = new Node<T1>();
    newNode->setData(data);
    newNode->setPrev(_tail);

    if (_tail)
        _tail->setNext(newNode);
    else
        _head = newNode;  // Update _head if the list was empty

    _tail = newNode;
    ++listSize;
}

// Return the last element in the list
// If the list is empty, print a message and return 0
template <class T1>
T1 List<T1>::back()
{
    if (empty())
    {
        cout << "List is empty!" << endl;
        return T1();  // Return default value
    }
    return _tail->getData();
}

// Remove the last element from the list and return its data
// If the list is empty, print a message and return 0
template <class T1>
T1 List<T1>::pop_back()
{
    if (empty())
    {
        cout << "List is empty!" << endl;
        return T1();  // Return default value
    }

    Node<T1>* temp = _tail;
    T1 data = temp->getData();

    _tail = _tail->getPrev();
    if (_tail)
        _tail->setNext(nullptr);
    else
        _head = nullptr;  // Update _head if the list becomes empty

    delete temp;
    --listSize;
    return data;
}

// Overloading <<: Return a space-separated stream of all the elements
template <class T1>
ostream& operator<<(ostream& os, const List<T1>& list)
{
    Node<T1>* current = list._head;
    while (current)
    {
        os << current->getData();
        if (current->getNext())
            os << " ";
        current = current->getNext();
    }
    return os;
}

// Compare two lists: Should iterate through each list to check that they are the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize)
        return false;

    Node<T1>* left = _head;
    Node<T1>* right = rhs._head;

    while (left && right)
    {
        if (left->getData() != right->getData())
            return false;

        left = left->getNext();
        right = right->getNext();
    }
    return true;
}
