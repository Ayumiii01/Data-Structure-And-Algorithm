
#include "node.hpp"
#include "arrayqueue.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class BinaryTree {
public:
    virtual node* left(node*) = 0;
    virtual node* right(node*) = 0;
    virtual node* addRoot(int e) = 0;
    virtual node* addLeft(node* p, int e) = 0;
    virtual node* addRight(node* p, int e) = 0;
    virtual node* getRoot() = 0;
    virtual void print() = 0;

    // PRE-ORDER: Root -> Left -> Right
    void preorder() {
        preorderHelper(getRoot());
    }

    void preorderHelper(node* n) {
        if (n == nullptr) {
            return;
        }

        cout << n->elem << " ";

        preorderHelper(left(n));
        preorderHelper(right(n));
    }

    // IN-ORDER: Left -> Root -> Right
    void inorder() {
        inorderHelper(getRoot());
    }

    void inorderHelper(node* n) {
        if (n == nullptr) {
            return;
        }

        inorderHelper(left(n));

        cout << n->elem << " ";

        inorderHelper(right(n));
    }

    // POST-ORDER: Left -> Right -> Root
    void postorder() {
        postorderHelper(getRoot());
    }

    void postorderHelper(node* n) {
        if (n == nullptr) {
            return;
        }

        postorderHelper(left(n));
        postorderHelper(right(n));

        cout << n->elem << " ";
    }

    // BREADTH-FIRST: Level by level
    void breadthfirst() {
        if (getRoot() == nullptr) {
            return;
        }

        ArrayQueue q;

        q.enqueue(getRoot());

        while (!q.empty()) {
            node* current = q.front();

            q.dequeue();

            cout << current->elem << " ";

            if (left(current) != nullptr) {
                q.enqueue(left(current));
            }

            if (right(current) != nullptr) {
                q.enqueue(right(current));
            }
        }
    }

    virtual ~BinaryTree() {}
};


// Actual implementation of the BinaryTree
class LinkedBinaryTree : public BinaryTree {
private:
    node* root;

    void destroy(node* n) {
        if (n == nullptr) {
            return;
        }

        destroy(n->left);
        destroy(n->right);

        delete n;
    }

public:
    LinkedBinaryTree() {
        root = nullptr;
    }

    node* left(node* p) override {
        return p->left;
    }

    node* right(node* p) override {
        return p->right;
    }

    node* addRoot(int e) override {
        if (root != nullptr) {
            throw logic_error("Root already exists!");
        }

        root = new node(e);

        return root;
    }

    node* addLeft(node* p, int e) override {
        if (p == nullptr || p->left != nullptr) {
            throw logic_error("Invalid left child!");
        }

        node* n = new node(e);

        n->parent = p;
        p->left = n;

        return n;
    }

    node* addRight(node* p, int e) override {
        if (p == nullptr || p->right != nullptr) {
            throw logic_error("Invalid right child!");
        }

        node* n = new node(e);

        n->parent = p;
        p->right = n;

        return n;
    }

    node* getRoot() override {
        return root;
    }

    void print() override {
        breadthfirst();
    }

    ~LinkedBinaryTree() {
        destroy(root);
    }
};