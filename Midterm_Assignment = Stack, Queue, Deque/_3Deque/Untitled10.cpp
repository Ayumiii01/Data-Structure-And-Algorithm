[MAIN]
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "doublydeque.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	Deque* deque = new DoublyDeque();
	char op;
	int n;
	
	do {
		cout << "Enter op: ";	cin >> op;
		switch(op) {
			case 'a':
				cin >> n;
				deque->addFirst(n);
				break;
			case 'q':
				cin >> n;
				deque->addLast(n);
				break;	
			case 'r':
				cout << "Removed: " << deque->removeFirst() << endl;
				break;
			case 'f':
				cout << "Removed: " << deque->removeLast() << endl;
				break;
			case 'p':
				deque->print();
				break;
			case '?':
				cout << "Empty? " << (deque->isEmpty()? "Yes" : "No") << endl;
				break;
			case 's':
				cout << "Size: " << deque->size() << endl;
				break;
			default:
				cout << "Enter a valid input." << endl;
		}
	} while(op != 'x');
}

[NODE.HPP]
struct node {
	int elem;
	node* next;
	node* prev;
	
	node(int e) : elem(e), next(nullptr), prev(nullptr) { }
};


[DEQUE.HPP]
class Deque {
	public:
		virtual void addFirst(int) = 0;
		virtual void addLast(int) = 0;
		virtual int removeFirst() = 0;
		virtual int removeLast() = 0;
		virtual int size() = 0;
		virtual bool isEmpty() = 0;
		virtual void print() = 0;
};


[DOUBLYDEQUE.HPP]
#include "node.hpp"
#include "deque.hpp"
#include <iostream>
using namespace std;

class DoublyDeque : public Deque {
	int _size;
	node *head, *tail;

public:
	DoublyDeque() {
		_size = 0;
		head = tail = nullptr;
	}

	~DoublyDeque() {
		while (head != nullptr) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void addFirst(int num) {
		node* n = new node(num);
		if (_size == 0) {
			head = tail = n;
		} else {
			n->next = head;
			head->prev = n;
			head = n;
		}
		_size++;
	}

	void addLast(int num) {
		node* n = new node(num);
		if (_size == 0) {
			head = tail = n;
		} else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		_size++;
	}

	int removeFirst() {
		if (head == nullptr) {
			return -1;
		}

		int res = head->elem;
		node* temp = head;
		head = head->next;

		if (head == nullptr) {
			tail = nullptr;
		} else {
			head->prev = nullptr;
		}

		delete temp;
		_size--;
		return res;
	}

	int removeLast() {
		if (tail == nullptr) {
			return -1;
		}

		int res = tail->elem;
		node* temp = tail;
		tail = tail->prev;

		if (tail == nullptr) {
			head = nullptr;
		} else {
			tail->next = nullptr;
		}

		delete temp;
		_size--;
		return res;
	}

	int size() {
		return _size;
	}

	bool isEmpty() {
		return _size == 0;
	}

	void print() {
		if (head == nullptr) {
			cout << "Nothing to show" << endl;
			return;
		}

		cout << "From HEAD: ";
		for (node* curr = head; curr != nullptr; curr = curr->next) {
			cout << curr->elem << " -> ";
		}
		cout << "NULL" << endl;

		cout << "From TAIL: NULL";
		for (node* curr = tail; curr != nullptr; curr = curr->prev) {
			cout << " <- " << curr->elem;
		}
		cout << endl;
	}
};
