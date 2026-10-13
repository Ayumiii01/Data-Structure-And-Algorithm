#include <iostream>
#include "arrayList.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List* l = new ArrayList();
	
	char op;
	int pos, num;
	
	do {
		cout << "Enter an operator: "; cin >> op;
		
		switch(op) {
			case 'a':
				cout << "Enter a number: "; cin >> num; l->add(num);
				break;
			case 'p':
				l->print();
				break;
			case 's':
				cout << "Adding a number at first position: "; cin >> num;
				l->addFirst(num);
				break;
			case 'd':
				cout << "Adding a number at: "; cin >> num >> pos;
				l->addAt(num, pos);
				break;
			case 'r':
				cout << "Removing last number..." << endl;
				l->remove();
				break;;
			case 't':
				cout << "Removing first number..." << endl;
				l->removeFirst();
				break;
			case 'y':
				cout << "Removing number at: "; cin >> pos;
				l->removeAt(pos);
				break;
			case 'u':
				cout << "Removing this kind of number: "; cin >> num;
				cout << l->removeAll(num) << endl;
				break;
			case 'x':
				cout << "Exiting...";
				break;
			default:
				cout << "Enter a valid operator.";
		}
	} while(op != 'x');
	
	return 0;
}