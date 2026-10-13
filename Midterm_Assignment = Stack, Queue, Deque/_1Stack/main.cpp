#include <iostream>
#include "arraystack.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stack* stack = new ArrayStack();
	char input;
	char op;
	
	do {
		cout << "Enter op: ";
		cin >> op;
		switch(op) {
			case 'a':
				cin >> input;
				stack->push(input);
				break;
			case 'r':
				cout << "Removed: " << stack->pop() << endl;
				break;
			case '?':	
				cout << "Empty? " << (stack->isEmpty()? "Yes": "No") << endl;
				break;
			case 'p':
				stack->print();
				break;
			case 's':
				cout << "Size: " << stack->size() << endl;
				break;
			case 't':
				cout << "Top: " << stack->top() << endl;
				break;
			case 'x':
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Enter valid operator." << endl;
		}
	} while(op != 'x');
	
	return 0;
}