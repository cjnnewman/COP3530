// File: main.cpp
// Dev: Caleb Newman
// Desc: Main file for the BST homework
// -----------------------------------------------------------------------
#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
    int userInputValue;
    BinarySearchTree BST;

    // get user input for tree, any 8 values.
    for (int i = 0; i < 7; i++) {
        std::cout << "Enter the value you would like to insert into the tree: ";
        std::cin >> userInputValue;
        BST.insert(userInputValue);
    }

    // print tree using all four traversal methods
    std::cout << "pre-order traversal: ";
    BST.preOrder(BST.getRoot());
    std::cout << "\n";
    std::cout << "in-order traversal: ";
    BST.inOrder(BST.getRoot());
    std::cout << "\n";
    std::cout << "post-order traversal: ";
    BST.postOrder(BST.getRoot());
    std::cout << "\n";
    std::cout << "breadth first traversal: ";
    BST.breadthFirst(BST.getRoot());
    std::cout << "\n";

    std::cout << "Enter value to search for: ";
    std::cin >> userInputValue;
    if (BST.searchBinaryTree(BST.getRoot(), userInputValue)){
        std::cout << "Found value.\n";
    }
    else {
        std::cout << "Value not found.\n";
    }


    return 0;
}
