//node.hpp
#include <cstdlib>

struct node {
	node **children;
	node *parent;
	int num_child;
	int elem;

    node(int e) : elem(e), num_child(0), parent(nullptr) {
        children = new node*[5]; 
    }
    
    node(int e, node* p) : elem(e), num_child(0), parent(p) {
        children = new node*[5];
    }
    
    node* addChild(int e) {
        node* n = new node(e, this);
        this->children[num_child++] = n;
        return n;
    }
    
    int depth() {
		// TODO implementation [+10 pts]
	    if(!parent) {
	        return 0;
	    }
	    
        return 1 + parent->depth();
	}


    int height() {
		// TODO implementation [+15 pts]
		if(num_child == 0) {
		    return 0;
		}
		
		int max = 0;
		
		for(int i = 0; i < num_child; i++) {
		    int res = children[i]->height();
		    if(max < res) {
		        max = res;
		    }
		}
		
		return 1 + max;
    }
};