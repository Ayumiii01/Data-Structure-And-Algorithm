#include "binarytree.hpp"
#include <iostream>
using namespace std;

int main() {

    LinkedBinaryTree* tree = new LinkedBinaryTree();

    node* root = tree->addRoot(1);

    node* n2 = tree->addLeft(root, 2);
    node* n3 = tree->addRight(root, 3);

    tree->addLeft(n2, 4);
    tree->addRight(n2, 5);

    tree->addLeft(n3, 6);
    tree->addRight(n3, 7);

    cout << "PRE-ORDER: ";
    tree->preorder();

    cout << "\nIN-ORDER: ";
    tree->inorder();

    cout << "\nPOST-ORDER: ";
    tree->postorder();

    cout << "\nBREADTH-FIRST: ";
    tree->breadthfirst();

    cout << endl;

    delete tree;

    return 0;
}