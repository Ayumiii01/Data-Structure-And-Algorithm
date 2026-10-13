#include <iostream>
#include "arrayList.hpp"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	List *l = new ArrayList(); 
	
	//adding numbers to array with size of 5
	l->add(2);
	l->add(5);
	l->add(1);
	l->add(3);
	//printing the elements of the array
	l->print();	
	//checking the size of the array
	cout << "The size of the array is: " << l->size() << endl;
	//adding number on the leftest side and shifting the other elements to the right
	cout << "\nAdding number (4) at position 1" << endl;
	l->addFirst(4);
	l->print();
	cout << "The size of the array is: " << l->size() << endl;
	//removing the last number and reducing the size of the array at the same time
	cout << "\nRemove last element" << endl;
	l->removeLast();
	l->print();
	cout << "The size of the array is: " << l->size() << endl;
	//removing the first number and shifting all numbers by 1 to the left side
	cout << "\nRemoving first position" << endl;
	l->removeFirst();
	l->print();
	cout << "The size of the array is: " << l->size() << endl;
	//adding element on a specific position
	cout << "\nAdding number (7) at position 3" << endl;
	l->addPosition(3, 7);
	l->print();
	cout << "The size of the array is: " << l->size() << endl;
	//removing an element from a specific position
	cout << "\nRemoving element at position 2" << endl;
	l->removePosition(2);
	l->print();
	cout << "The size of the array is: " << l->size() << endl;
	//sorting numbers from largest to lowest where position 1 is the largest
	cout << "\nSorted Numbers [Added numbers: 0, 10]: " << endl;
	l->add(0);
	l->add(10);
	l->sortedNumbers();
	l->print();
	return 0;
}
