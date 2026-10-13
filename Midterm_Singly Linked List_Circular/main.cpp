#include <iostream>
#include "singlylist.hpp"
using namespace std;

int main(int argc, char** argv) {
	Singly* singly = new SinglyList();
	char op;
	int n;
	
	do {
		cout << "Enter op: ";
		cin >> op;
		switch(op) {
			case 'a':
				cin >> n;
				singly->addFirst(n);
				break;
			case 'q':
				cin >> n;
				singly->addLast(n);
				break;	
			case 'r':
				cout << "Removed: " << singly->removeFirst() << endl;
				break;
			case 'f':
				cout << "Removed: " << singly->removeLast() << endl;
				break;
			case 't':
				cin >> n;
				singly->rotate(n);
				break;
			case 'p':
				singly->print();
				break;
			case '?':
				cout << "Empty? " << (singly->isEmpty()? "Yes" : "No") << endl;
				break;
			case 's':
				cout << "Size: " << singly->size() << endl;
				break;
			case 'x':
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Enter a valid input." << endl;
		}
	} while(op != 'x');
	
	delete singly;
	return 0;
}