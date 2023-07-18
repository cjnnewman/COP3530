// File: BinarySearchTree.cpp
// Dev: Caleb Newman
// Desc: cpp file for the BST class
// -----------------------------------------------------------------------

#include "BinarySearchTree.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
    std::cout << "Instantiating Tree Object ...\n";
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    std::cout << "Deleting tree ...\n";
    if (root){
        deleteAllNodes();
    }
}

BinarySearchTree::Node *BinarySearchTree::private_insert(int value, BinarySearchTree::Node *currentRoot) {
    if (!currentRoot){
        Node* temp = new Node{value, nullptr, nullptr};
        return temp;
    }
    else if (value <= currentRoot->value){
        currentRoot->left = private_insert(value, currentRoot->left);
    }
    else{
        currentRoot->right = private_insert(value, currentRoot->right);
    }

    return currentRoot;
}

void BinarySearchTree::insert(int value) {
    root = private_insert(value, root);
    size++;
}

BinarySearchTree::Node *BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::preOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        std::cout << currentRoot->value << " ";
        preOrder(currentRoot->left);
        preOrder(currentRoot->right);
    }

}

void BinarySearchTree::inOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        inOrder(currentRoot->left);
        std::cout << currentRoot->value << " ";
        inOrder(currentRoot->right);
    }
}

void BinarySearchTree::postOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        postOrder(currentRoot->left);
        postOrder(currentRoot->right);
        std::cout <<  currentRoot->value << " ";
    }
}

void BinarySearchTree::breadthFirst(BinarySearchTree::Node * currentRoot) {
    std::queue<Node*> queueList;
    if (root) {
        queueList.push(root);
        while (!queueList.empty()) {
            Node *temp = new Node;
            temp = queueList.front();
            std::cout << temp->value << " ";

            queueList.pop();
            if (temp->left) {
                queueList.push(temp->left);
            }
            if (temp->right) {
                queueList.push(temp->right);
            }
        }
    }

}

void BinarySearchTree::deleteAllNodes() {
    priv_deleteAllNodes(root);

}

void BinarySearchTree::priv_deleteAllNodes(BinarySearchTree::Node *&currentRoot) {
    if (!currentRoot){
        return;
    }

    priv_deleteAllNodes(currentRoot->left);
    priv_deleteAllNodes(currentRoot->right);

    delete currentRoot;
    currentRoot = nullptr;

}


