#ifndef NODE_HPP
#define NODE_HPP

struct node {
    int elem;
    node* parent;
    node* left;
    node* right;

    node(int e) : elem(e), parent(nullptr), left(nullptr), right(nullptr) { } 
};

#endif