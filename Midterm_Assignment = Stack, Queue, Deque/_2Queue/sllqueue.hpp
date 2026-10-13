
#include "node.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

class SLLQueue : public Queue {
	int _size;
	node *head, *tail;

public:
	SLLQueue() {
		_size = 0;
		head = tail = nullptr;
	}

	~SLLQueue() {   // fix: free all remaining nodes
		while (head != nullptr) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void enqueue(int num) {
		node* n = new node(num);

		if (_size == 0) {
			head = tail = n;
		} else {
			tail->next = n;
			tail = n;
		}

		_size++;
	}

	int dequeue() {
		if (head == nullptr) {
			return 0;
		}

		int res = head->elem;
		node* temp = head;
		head = head->next;

		if (head == nullptr) {   // queue is now empty
			tail = nullptr;
		}

		delete temp;   // fix: delete, not delete[]
		_size--;
		return res;
	}

	int first() {
		if (head == nullptr) {
			return 0;
		}
		return head->elem;
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

		node* curr = head;
		while (curr != nullptr) {
			cout << curr->elem << "->";
			curr = curr->next;
		}
		cout << "NULL" << endl;
	}
};












/*
#include "node.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

class SLLQueue : public Queue {
	int _size;
	node *head, *tail;
	
	public:
		SLLQueue() {
			_size = 0;
			head = tail = nullptr;
		}
		
		void enqueue(int num) {
			node* n = new node(num);
			
			if(_size == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				tail = n;
			}
		
			_size++;
		}
		
		int dequeue() {
			if(head == nullptr || _size == 0) {
				return 0;
			}
			if(head->next == nullptr) {
				int res = head->elem;
				delete[] head;
				head = nullptr;
				tail = nullptr;
				_size--;
				return res;
			}
			
			int res = head->elem;
			node* temp = head->next;
			delete head;
			head = temp;
			
			_size--;
			return res;
		}
		
		int first() {
			if(head == nullptr) {
				return 0;
			}
			node* curr = head;
			return curr->elem;
		}
		
		int size() {
			return _size;
		}
		
		bool isEmpty() {
			return size() <= 0? true : false;
		}
		
		void print() {
			if(_size == 0 || head == nullptr) {
				cout << "Nothing to show" << endl;
				return;
			}
			node* curr = head;
			
			while(curr != nullptr) {
				cout << curr->elem << "->";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
};
*/