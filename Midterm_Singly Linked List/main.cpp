#include <iostream>
#include "arrayList.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List* l = new ArrayList();
	char ch;
	int num, pos;
	do {
		cout << "Op: ";
		cin >> ch;
		switch(ch) {
			case 'a':
				cout << "Add a number: "; cin >> num;
				l->add(num);;
				break;
			case 'w':
				cout << "Add a number on first position: "; cin >> num;
				l->addFirst(num);
				break;
			case 'g':
				cout << "Enter position: "; cin >> pos;
				cout << "The element getted: " << l->get(pos) << endl;
				break;
			case 'q':
				cout << "Add a number at position: "; cin >> num >> pos;
				l->addAt(num, pos);
				break;
			case 'r':
				cout << "Removing the first element..." << endl;
				l->removeFirst();
				break;
			case 't':
				cout << "Removing the last element..." << endl;
				l->removeLast();
				break;
			case 'y':
				cout << "Removing element at position: "; cin >> pos;
				l->removeAt(pos);
				break; 
			case 'u':
				cout << "Removing this element: "; cin >> num;
				cout << "Total removed: " << l->removeAll(num) << endl;
				break;
			case 'p':
				l->print();
				break;
			case 'x':
				cout << "Exiting..." << endl;
				break;
			default:
				break;
				cout << "Invalid operator!" << endl;
		}
		
	} while(ch != 'x');
	
	
	return 0;
}