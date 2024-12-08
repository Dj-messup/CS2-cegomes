#pragma once
#include "node.h"
using namespace std;

template <class T1>
class BST
{
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);
    void inOrderPrint(Node<T1>*);
    Node<T1>* searchData(Node<T1>*, T1);
    Node<T1>* removeData(Node<T1>*, T1);
    Node<T1>* minVal(Node<T1>*);

    public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
    void increment(T1);
    ~BST();
};

// Destructor, should check if root exists and then delete it. Each node will handle deleting its leaf nodes.
template <class T1>
BST<T1>::~BST() {
    if (_root != nullptr) {
        delete _root;
    }
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. 
template <class T1> 
void BST<T1>::insert(T1 data) {
    _root = insertNode(_root, data);
}

// Given some data and a node, recursively walk the tree until you get to a nullptr and store the value there
template <class T1>
Node<T1>* BST<T1>::insertNode(Node<T1>* root, T1 data) {
    if (root == nullptr) {
        Node<T1>* newNode = new Node<T1>();
        newNode->setData(data);
        return newNode;
    }
    
    if (data < root->getData()) {
        root->setLeft(insertNode(root->getLeft(), data));
    } 
    else if (data > root->getData()) {
        root->setRight(insertNode(root->getRight(), data));
    }
    else {
        cout << "Value " << data << " already exists" << endl;
    }
    
    return root;
}

// Wrapper for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data) {
    return searchData(_root, data) != nullptr;
}

// Given data and a node, recursively walk the tree to find that node if it exists
template <class T1>
Node<T1>* BST<T1>::searchData(Node<T1>* root, T1 data) {
    if (root == nullptr || root->getData() == data) {
        return root;
    }
    
    if (data < root->getData()) {
        return searchData(root->getLeft(), data);
    }
    return searchData(root->getRight(), data);
}

// Public method that takes in some data and passes that into the removeData method
template <class T1>
void BST<T1>::remove(T1 data) {
    _root = removeData(_root, data);
}

// Private method to recursively walk the tree until the data is found
template <class T1>
Node<T1>* BST<T1>::removeData(Node<T1>* root, T1 data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->getData()) {
        root->setLeft(removeData(root->getLeft(), data));
    }
    else if (data > root->getData()) {
        root->setRight(removeData(root->getRight(), data));
    }
    else {
        if (root->getLeft() == nullptr) {
            Node<T1>* temp = root->getRight();
            delete root;
            return temp;
        }
        else if (root->getRight() == nullptr) {
            Node<T1>* temp = root->getLeft();
            delete root;
            return temp;
        }

        Node<T1>* temp = minVal(root->getRight());
        root->setData(temp->getData());
        root->setRight(removeData(root->getRight(), temp->getData()));
    }
    return root;
}

// Given a node, find the smallest value in that subtree
template <class T1>
Node<T1>* BST<T1>::minVal(Node<T1>* root) {
    Node<T1>* current = root;
    while (current && current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current;
}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder() {
    inOrderPrint(_root);
}

// Given a node, recursively walk the tree to print out the inOrder format
template <class T1>
void BST<T1>::inOrderPrint(Node<T1>* root) {
    if (root != nullptr) {
        inOrderPrint(root->getLeft());
        cout << root->getData() << " ";
        inOrderPrint(root->getRight());
    }
}

// Search for the word by calling searchData passing in _root and data
template <class T1>
void BST<T1>::increment(T1 data) {
    Node<T1>* node = searchData(_root, data);
    if (node != nullptr) {
        T1 temp = node->getData();
        temp++;
        node->setData(temp);
    }
}