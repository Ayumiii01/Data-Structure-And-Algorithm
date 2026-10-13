#include <iostream>
#include "arraylist.hpp"
using namespace std;

int main(int argc, char** argv) {
	List* list = new ArrayList();
	char ch;
	int num, pos;
	do {
		cout << "Op: ";
		cin >> ch;
		switch(ch) { 
			case 'a':
				cin >> num;
				list -> add(num);
				break;
			case 'p':
				list -> print();
				break;
			case 'r':
				cin >> num;
				list -> remove(num); //removing first occurence
				break;	
			case 'g':
				cin >> pos;
				list -> get(pos);
				break;
			case 'x':
				cout << "Exiting..." << endl;
			default:
				cout << "Invalid operation" << endl;			
		}
	} while(ch != 'x');
}