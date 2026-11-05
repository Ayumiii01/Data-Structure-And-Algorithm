#include <iostream>
#include <string>
#include <stdexcept>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int count;

	// delete every node (post-order)
	void destroy(node* n) {
		if(n == nullptr) return;
		destroy(n->left);
		destroy(n->right);
		delete n;
	}

	// prints one node per line: left subtree first, then right subtree
	void printTree(node* n, int depth, char label) {
		if(n == nullptr) return;

		string prefix = "";
		if(depth > 0) {
			prefix = "|     ";
			for(int i = 1; i < depth; i++) {
				prefix += " |    ";
			}
		}

		cout << prefix << "+--" << label << ": " << n->elem << endl;

		printTree(n->left, depth + 1, 'L');
		printTree(n->right, depth + 1, 'R');
	}

	// 1 if every node respects the BST ordering, 0 otherwise
	bool isValidBST(node* n, long long lo, long long hi) {
		if(n == nullptr) return true;
		if(n->elem <= lo || n->elem >= hi) return false;
		return isValidBST(n->left, lo, n->elem) &&
		       isValidBST(n->right, n->elem, hi);
	}

	public:
		MyBinaryTree() : root(nullptr), count(0) {}

		~MyBinaryTree() {
			destroy(root);
		}

		node* left(node* n) {
			return n->left;
		}

		node* right(node* n) {
			return n->right;
		}

		node* getRoot() {
			return root;
		}

		node* addRoot(int e) {
			if(root != nullptr) {
				throw logic_error("Tree already has a root");
			}
			root = new node(e);
			count++;
			return root;
		}

		node* addLeft(node* p, int e) {
			if(p->left != nullptr) {
				throw logic_error("Left child already exists");
			}
			p->left = new node(e, p);
			count++;
			return p->left;
		}

		node* addRight(node* p, int e) {
			if(p->right != nullptr) {
				throw logic_error("Right child already exists");
			}
			p->right = new node(e, p);
			count++;
			return p->right;
		}

		// Removes a node with at most ONE child (leaf or one child).
		int remove(node* n) {
			if(n->left != nullptr && n->right != nullptr) {
				throw invalid_argument("Cannot remove a node with two children");
			}

			node* child = (n->left != nullptr) ? n->left : n->right;

			if(child != nullptr) {
				child->parent = n->parent;
			}

			if(n->parent == nullptr) {
				root = child;
			} else if(n->parent->left == n) {
				n->parent->left = child;
			} else {
				n->parent->right = child;
			}

			int e = n->elem;
			delete n;
			count--;
			return e;
		}

		void print() {
			cout << "Size: " << count << std::endl;
			printTree(root, 0, 'R');   // the root is labeled R
			cout << "Status: "
			          << (isValidBST(root, -2147483648LL, 2147483648LL) ? 1 : 0)
			          << endl;
		}
};