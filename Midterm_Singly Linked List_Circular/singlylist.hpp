#include "node.hpp"
#include "singly.hpp"
#include <iostream>
using namespace std;

class SinglyList : public Singly {
	int _size;
	node *head, *tail;

public:
	SinglyList() {
		_size = 0;
		head = tail = nullptr;
	}

	~SinglyList() {
		// loop _size times, NOT until nullptr (a circular list has no nullptr)
		for (int i = 0; i < _size; i++) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void addFirst(int num) {
		node* n = new node(num);
		if (_size == 0) {
			head = tail = n;
			n->next = n;           // points to itself
		} else {
			n->next = head;
			head = n;
			tail->next = head;     // keep the circle closed
		}
		_size++;
	}

	void addLast(int num) {
		node* n = new node(num);
		if (_size == 0) {
			head = tail = n;
			n->next = n;
		} else {
			n->next = head;        // new tail points back to head
			tail->next = n;
			tail = n;
		}
		_size++;
	}

	int removeFirst() {
		if (head == nullptr) {
			return -1;
		}

		int res = head->elem;

		if (head == tail) {        // only one node
			delete head;
			head = tail = nullptr;
		} else {
			node* temp = head;
			head = head->next;
			tail->next = head;     // keep the circle closed
			delete temp;
		}

		_size--;
		return res;
	}

	int removeLast() {
		if (tail == nullptr) {
			return -1;
		}

		int res = tail->elem;

		if (head == tail) {        // only one node
			delete head;
			head = tail = nullptr;
		} else {
			node* curr = head;     // singly: must walk to the node before tail
			while (curr->next != tail) {
				curr = curr->next;
			}
			curr->next = head;
			delete tail;
			tail = curr;
		}

		_size--;
		return res;
	}

	// k > 0: rotate left  (front goes to the back), k times
	// k < 0: rotate right (back goes to the front), |k| times
	void rotate(int k) {
		if (_size <= 1) {
			return;
		}

		k = k % _size;             // full turns do nothing
		if (k < 0) {
			k += _size;            // rotate right by r == rotate left by size - r
		}

		for (int i = 0; i < k; i++) {
			tail = head;           // old head becomes the new tail
			head = head->next;     // next node becomes the new head
		}                          // tail->next already points to head, so the circle stays closed
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
		node* curr = head;
		do {                       // do-while, because while(curr != head) would never start
			cout << curr->elem << " -> ";
			curr = curr->next;
		} while (curr != head);
		cout << "(back to HEAD)" << endl;
	}
};