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

    std::cout << "Size of tree is " << BST.getSize() << " nodes.\n";

    std::cout << "Enter value to search for: ";
    std::cin >> userInputValue;
    if (BST.searchBinaryTree(BST.getRoot(), userInputValue)){
        std::cout << "Found value.\n";
    }
    else {
        std::cout << "Value not found.\n";
    }

    std::cout << "Enter a value to delete from the tree: ";
    std::cin >> userInputValue;
    if (BST.deleteNode(userInputValue)){
        std::cout << "Value found and removed, new tree by breadth first search is:\n";
        BST.breadthFirst(BST.getRoot());
        std::cout << "\n";
    }
    else {
        std::cout << "Value not found in tree, try again...\n";
    }
    std::cout << "Size of tree after delete is " << BST.getSize() << " nodes.\n";


    return 0;
}
