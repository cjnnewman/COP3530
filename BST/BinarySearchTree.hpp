// File: BinarySearchTree.hpp
// Dev: Caleb Newman
// Desc: Header file for the BST class
// -----------------------------------------------------------------------
#ifndef BST_BINARYSEARCHTREE_HPP
#define BST_BINARYSEARCHTREE_HPP

#include <queue>

class BinarySearchTree {
private:
    struct Node{
        int value;
        Node* left;
        Node* right;

        Node() {
            value = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int value, Node* left, Node* right){
            this->value = value;
            this->left = left;
            this->right = right;
        }

    };

    Node* private_insert(int value, Node* root);
    void priv_deleteAllNodes(Node* &currentRoot);
    Node* root;
    int size = 0;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int value);
    Node* getRoot();
    // bool visited = false;

    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    void breadthFirst(Node*);
    void deleteAllNodes();

};


#endif //BST_BINARYSEARCHTREE_HPP
