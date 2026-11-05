#ifndef BST_HPP
#define BST_HPP

#include "mybinarytree.hpp" // already implemented, though hidden

class BST {
	BinaryTree* tree;
	
	public:
		BST() {
			tree = new MyBinaryTree();
		}
		
		bool search(int num) {
			bool found = false;
			if(tree->getRoot() == nullptr) {
				return false;
			}
			
			node* curr = tree->getRoot();
			
			while(curr != NULL && !found) {
				if(curr->elem == num) {
					found = true;
					break;
				} else if(curr->elem > num) {
					curr = curr->left;
				} else if(curr->elem < num) {
					curr = curr->right;
				}
			}
			return found;
		}
		
		bool insert(int num) {
			node* n = new node(num);
			
			
			if(tree->getRoot() == nullptr) {
				tree->addRoot(num);
				return true;
			}
			
			node* curr = tree->getRoot();
			node* trailCurr;
			while(curr != nullptr) {
				trailCurr = curr;
				if(curr->elem == num) {
					return false;
				} else if(curr->elem > num) {
					curr = curr->left;
				} else {
					curr = curr->right;
				}
			}
			
			if(trailCurr->elem > num) {
				tree->addLeft(trailCurr, num);
				return true;
			} else {
				tree->addRight(trailCurr, num);
				return true;
			}
			
			return false;
		}

		bool remove(int num) {
			if(tree->getRoot() == nullptr) {
				return false;
			}
			
			node* curr = tree->getRoot();
			
			while(curr != nullptr && curr->elem != num) {
				if(curr->elem > num) {
					curr = curr->left;
				} else {
					curr = curr->right;
				}
			}
			
			if(curr == nullptr) {
				return false;
			}
			
			if(curr->right == nullptr && curr->left == nullptr) {
				tree->remove(curr);
				return true;
			}
			
			if((curr->right == nullptr && curr->left != nullptr) || (curr->right != nullptr && curr->left == nullptr)) {
				tree->remove(curr);
				return true;
			}
			
			if((curr->right != nullptr && curr->left != nullptr)) {
				node* suc = curr->right;
				
				while(suc->left != nullptr) {
					suc = suc->left;
				}
				
				curr->elem = suc->elem;
				
				tree->remove(suc);
				
				return true;      // fixed: was "returnn"
			}                     // fixed: this closing brace was missing
			
			return false;
		}
		
		void print() {
			tree->print();
		}
};

#endif