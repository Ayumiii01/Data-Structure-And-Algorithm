#include <iostream>
#include "arraylist.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List* list = new ArrayList();
	char ch;
	int num, pos;
	do {
		cout << "Op: ";
		cin >> ch;
		
		switch(ch) {
			case 'a':
				cout << "Adding a number: ";
				cin >> num;
				list -> add(num);
				cout << "======================" << endl;
				break;
			case 'p':
				list -> print();
				cout << "======================" << endl;
				break;
			case 'r':
				cout << "Remove: ";
				cin >> num;
				list -> remove(num);
				cout << "======================" << endl;
				break;
			case 'q':
				cout << "Adding a number: ";
				cin >> num;
				cout << "At position: ";
				cin >> pos;
				list -> addAt(num, pos);
				cout << "======================" << endl;
				break;
			case 'g':
				cout << "Getting element at position: ";
				cin >> pos;
				cout << "Element: " << list -> get(pos);
				cout << "======================" << endl;
				break;
			case 'w':
				cout << "Removing an element at position: ";
				cin >> pos;
				cout << "Removed element: " << list -> removeAt(pos) << endl;
				cout << "======================" << endl;
				break;
			default:
				cout << "Invalid operation." << endl;
		}
	} while (ch != 'x');
	return 0;
}