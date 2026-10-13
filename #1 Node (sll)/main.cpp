#include <iostream>
#include "singlyll.hpp"
using namespace std;


int main(int argc, char** argv) {
	List *l = new SinglyLL;

	l->add(10);
	l->add(5);
	l->add(1);
	l->print();          // 10->5->1->NULL

	l->insertAtHead(99);
	l->print();          // 99->10->5->1->NULL

	l->insertAtTail(42);
	l->print();          // 99->10->5->1->42->NULL

	l->removeFirst();
	l->print();          // 10->5->1->42->NULL

	l->removeLast();
	l->print();          // 10->5->1->NULL

	return 0;
}
