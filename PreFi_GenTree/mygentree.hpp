// Create a class MyGenTree, a subclass of GenTree
#include "gentree.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class MyGenTree : public GenTree {
    int size;
    node* root;
    
    public:
        MyGenTree() {
            size = 0;
            root = nullptr;
        }
        //e
        node* addRoot(int e) {
            if(root) {
                throw logic_error("Already has root");
            }
            
            root = new node(e);
            size++;
            return root;
        }
        //e
	    node* addChild(node* p, int e) {
	        node* n = p->addChild(e);
	        size++;
	        return n;
	    }
	    
	    void remove(node* n) {
	        if(n->num_child == 0) {
	            if(n->parent) {
                    for(int i = 0; i < n->parent->num_child; i++) {
                        if(n == n->parent->children[i]) {
                            for(int j = i; j < n->parent->num_child; j++) {
                                n->parent->children[j] = n->parent->children[j+ 1];
                            }
                            n->parent->num_child--;
                            break;
                        }
                    }           
	            } else {
	                root = nullptr;
	            }
	            size--;
	            free(n);
	        } else {
	            throw logic_error(to_string(n->elem) + " has children");
	        }
	        
	    }
	    
	    int getSize() {
	        return size;
	    }
	    
	    node* getRoot() {
	        return root;
	    }
    
};