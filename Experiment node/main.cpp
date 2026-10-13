#include <iostream>
#include "arrayList.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List* l = new ArrayList();
	
	char op;
	int num, pos;
	
	do {
		cout << "Enter op: ";
		cin >> op;
		
		switch(op) {
			case 'a':
				cout << "Add a number: "; cin >> num;
				l->add(num);
				break;
			case 'p':
				l->print();
				break;
			case 'x':
				cout << "Exiting...";
				break;
			case 's':
				cout << "Size: " << l->_size() << endl;
				break;
			case 'g':
				cout << "Enter a position: "; cin >> pos;
				cout << "Element at pos " << pos + 1 << ": " << l->get(pos) << endl;
				break;
			default:
				cout << "Enter a valid operator.";
		} 
	} while(op != 'x');
	
	return 0;
}