#include <iostream>
#include <stdexcept>
#include "mygentree.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	GenTree* tree = new MyGenTree();
	node* nodes[100];
	char respond;
	int leaf;
	int par, chi;
	
	try {
		nodes[15] = tree->addRoot(15);
		nodes[32] = tree->addChild(nodes[15], 32);
		nodes[64] = tree->addChild(nodes[15], 64);
		nodes[16] = tree->addChild(nodes[32], 16);
		nodes[12] = tree->addChild(nodes[32], 12);
		nodes[13] = tree->addChild(nodes[16], 13);
		nodes[18] = tree->addChild(nodes[64], 18);
		
		tree->print();
		cout << endl;
		
		do {
			cout << "Delete a node?(y/n): ";
			cin >> respond;
			switch(respond) {
				case 'y':
					cout << "R: ";
					cin >> leaf;
					tree->remove(nodes[leaf]);
					break;
				case 'n':
					cout << "Exitting...\n" << endl;	 
					break;
			}
		} while(respond != 'n');
	} catch(exception& e) {
		cout << e.what() << "\n" << endl;
	}
	
	tree->print();
	
	return 0;
}