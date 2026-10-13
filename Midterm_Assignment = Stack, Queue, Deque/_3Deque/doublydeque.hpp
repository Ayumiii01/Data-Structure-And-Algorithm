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



/*
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
		
		void addFirst(int num) {
			node* n = new node(num);
			if(_size == 0) {
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
			if(_size == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				n->prev = tail;
				tail = n;
			}
			
			_size++;
		}
		
		int removeFirst() {
			if(head == nullptr || _size == 0) {
				return -1;
			}
			int res = head->elem;
			
			if(_size == 1) {
				head = tail = nullptr;
				delete head;
				delete tail;
			} else {
				node* temp = head->next;
				head = temp;
				head->prev = nullptr;
			}
			
			_size--;
			return res;
		}
		
		int removeLast() {
			if(tail == nullptr || _size == 0) {
				return -1;
			}
			int res = tail->elem;
			if(_size == 1) {
				head = tail = nullptr;
				delete head;
				delete tail;
			} else {
				node* temp = tail->prev;
				tail = temp;
				tail->next = nullptr;
			}
			
			_size--;
			return res;
		}
		
		int size() {
			return _size;
		}
		
		bool isEmpty() {
			return size() <= 0? true: false;
		}
		
		void print() {
			if(_size <= 0) {
				cout << "Nothing to show" << endl;
				return;
			}
			
			node* curr = head;
			cout << "From HEAD: ";
			while(curr != nullptr) {
				cout << curr->elem;
				if(curr != nullptr) {
					cout << " -> ";
				}
				curr = curr->next;
			}
			cout << "NULL" << endl;
			
			node* curr2 = tail;
			cout << "From TAIL: NULL";
			while(curr2 != nullptr) {
				if(curr2 != nullptr) {
					cout << " <- ";
				}
				cout << curr2->elem;
				curr2 = curr2->prev;
			} 
			cout << endl;
		}
};
*/
