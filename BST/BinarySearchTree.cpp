// File: BinarySearchTree.cpp
// Dev: Caleb Newman
// Desc: cpp file for the BST class
// -----------------------------------------------------------------------

#include "BinarySearchTree.hpp"
#include <iostream>

// Class constructor for BST class, sets root to a nullptr (empty tree)
BinarySearchTree::BinarySearchTree() {
    std::cout << "Instantiating Tree Object ...\n";
    root = nullptr;
}

// class destructor for BST class, calls the delete all nodes function
BinarySearchTree::~BinarySearchTree() {
    std::cout << "Deleting tree ...\n";
    if (root){
        deleteAllNodes();
    }
}

// private insert function, takes value from the public insert function and finds the correct
// place to insert the value based on root
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

// public facing insert function, simply takes a value and calls the root function, sets root
// equal to the insert function thereby maintaining the tree.
void BinarySearchTree::insert(int value) {
    root = private_insert(value, root);
    size++;
}

// returns root, acts as a getter for public functions
BinarySearchTree::Node *BinarySearchTree::getRoot() {
    return root;
}

// sorts the tree in pre-order, DLR
void BinarySearchTree::preOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        std::cout << currentRoot->value << " ";
        preOrder(currentRoot->left);
        preOrder(currentRoot->right);
    }

}

// sorts the tree in-order, LDR
void BinarySearchTree::inOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        inOrder(currentRoot->left);
        std::cout << currentRoot->value << " ";
        inOrder(currentRoot->right);
    }
}

// sorts the tree post-order, LRD
void BinarySearchTree::postOrder(BinarySearchTree::Node * currentRoot) {
    if (currentRoot){
        postOrder(currentRoot->left);
        postOrder(currentRoot->right);
        std::cout <<  currentRoot->value << " ";
    }
}

// sorts the tree breadth first, displays each "height" or "depth" before moving
// to the next
void BinarySearchTree::breadthFirst(BinarySearchTree::Node * currentRoot) {
    std::queue<Node*> queueList;
    if (currentRoot) {
        queueList.push(currentRoot);
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

// public facing delete all nodes function, calls the private function
void BinarySearchTree::deleteAllNodes() {
    priv_deleteAllNodes(root);

}

// private delete all notes function, walks through the tree in post-order to delete each node
// and set pointers to nullptr
void BinarySearchTree::priv_deleteAllNodes(BinarySearchTree::Node *&currentRoot) {
    if (!currentRoot){
        return;
    }

    priv_deleteAllNodes(currentRoot->left);
    priv_deleteAllNodes(currentRoot->right);

    delete currentRoot;
    currentRoot = nullptr;

}

// searches tree for a given value, returns true if found, false if not found
bool BinarySearchTree::searchBinaryTree(Node* currentRoot, int key) {
    if (!currentRoot){
        return false;
    }
    else if (key < currentRoot->value){
        return searchBinaryTree(currentRoot->left, key);
    }
    else if (key > currentRoot->value){
        return searchBinaryTree(currentRoot->right, key);
    }
    else {
        return true;
    }

}

// public getter to return private size variable
int BinarySearchTree::getSize() {
    return size;
}

// public facing function to delete a specific node based on value/key. calls the private
// delete node function
bool BinarySearchTree::deleteNode(int key) {
    if (priv_deleteNode(root, key)){
        return true;
    }
    else{
        return false;
    }
}

// private delete node function, first completes a search for the value by comparing it to
// root and moving left or right. If found, deletes the value and returns true, else returns
// false. Handles no children, one child, and two children
bool BinarySearchTree::priv_deleteNode(BinarySearchTree::Node* &currentRoot, int key) {
    // if currentRoot is a nullptr, the node does not exist or the tree is empty, returns false
    if (!currentRoot){
        return false;
    }
    // if key value is less than currentRoot's value, calls private delete node function again
    // this time passing the left child as currentRoot.
    else if (key < currentRoot->value){
        return priv_deleteNode(currentRoot->left, key);
    }
    // if key value is greater than currentRoot's value, calls private delete node function again
    // this time passing the right child as currentRoot.
    else if (key > currentRoot->value){
        return priv_deleteNode(currentRoot->right, key);
    }
    // else statement executes if currentRoot is not null, and currentRoot's value is not less than
    // or greater than key's value. Thus, they must be equivalent and we have found the value
    else {
        // set temp node toDelete to the currentRoot, as it is the node we want to delete
        Node* toDelete = currentRoot;
        // if currentRoot's left and right children are nullptr's, it is a leaf node, safe to delete
        if (!(currentRoot->left || currentRoot->right)){
            currentRoot = nullptr;
            delete currentRoot;
            return true;
        }
        // if currentRoot has EXCLUSIVELY a left or a right child, assign currentRoot to that child
        else if ((currentRoot->left != nullptr) ^ (currentRoot->right != nullptr)){
            if (currentRoot->left){
                currentRoot = currentRoot->left;
            }
            else {
                currentRoot = currentRoot->right;
            }
        }
        // if currentRoot has two children, must find the minimum value in the right subtree of currentRoot
        // replace currentRoot's value with that value, then call private delete node again, on the right
        // subtree of currentRoot, and with the found minValue, to delete the duplicate.
        else {
            currentRoot->value = priv_findMinValue(currentRoot->right);
            priv_deleteNode(currentRoot->right, currentRoot->value);
        }
        //decrement size and return true as the value was found and deleted
        size--;
        return true;
    }
}

// finds the minimum value child of a passed root and returns it to the private
// delete function. Used for nodes with 2 children
int BinarySearchTree::priv_findMinValue(BinarySearchTree::Node * currentRoot) {
    int minValue = -1;
    if (currentRoot){
        while (currentRoot->left){
            currentRoot = currentRoot->left;
        }
        minValue = currentRoot->value;
    }
    return minValue;
}


