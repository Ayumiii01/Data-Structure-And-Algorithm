#include <iostream>
#include "sllqueue.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue* queue = new SLLQueue();
	char op;
	int n;
	
	do{
		cout << "Enter op: ";
		cin >> op;
		
		switch(op) {
			case 'e':
				cin >> n;
				queue->enqueue(n);
				break;
			case 'd':
				cout << "Removed: " << queue->dequeue() << endl;
				break;
			case 's':
				cout << "Size: " << queue->size() << endl;
				break;		
			case 'p':
				queue->print();
				break;
			case '?':
				cout << "Empty? " << (queue->isEmpty()? "Yes": "No") << endl;
				break;
			default:
				cout << "Enter valid operator." << endl;
		}
	} while(op != 'x');
	return 0;
}