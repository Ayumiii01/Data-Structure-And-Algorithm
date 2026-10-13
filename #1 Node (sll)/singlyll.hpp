#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class SinglyLL : public List {
	int _size;
	Node *head, *tail;
	
	public:
		SinglyLL() {
			cout << "Init sll" << endl;
			head = tail = nullptr;
			_size = 0;
		}
	
		void add(int num) {
			//Step 1 - Create Node
			Node* n = new Node;
			//Step 2 - Set element to num, next to NULL
			n->element = num;
			n->next = nullptr;
			//Step 3 - Point head to n, tail to n
			if(size() == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				tail = n;
			}
			//Step 4 - Update size
			_size++;
		}

		
		void print() {
			cout << "Size: " << size() << endl;
			cout << "Head: " << head->element << endl;
			cout << "Tail: " << tail->element << endl;
			
			cout << endl;
			
			Node* curr = head;
			
			while(curr) {
				cout << curr->element << "->";
				curr = curr->next;
			}
			cout << "NULL" << endl;
		}
		
		void insertAtHead(int num) {
			Node* n = new Node;
			n->element = num;
			n->next = head;      // new node points to old head
		
			if(size() == 0) {
				head = tail = n;  // list was empty: head and tail both = n
			} else {
				head = n;         // move head to the new node
			}
			_size++;
		}

		void insertAtTail(int num) {
			Node* n = new Node;
			n->element = num;
			n->next = nullptr;
		
			if(size() == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				tail = n;
			}
			_size++;
		}
		
		void removeFirst() {
			if(size() == 0) {
				cout << "List is empty, cannot remove" << endl;
				return;
			}
		
			Node* temp = head;
			head = head->next;      // move head forward
		
			if(head == nullptr) {   // list is now empty
				tail = nullptr;
			}
		
			delete temp;             // free the old head
			_size--;
		}
		
		void removeLast() {
			if(size() == 0) {
				cout << "List is empty, cannot remove" << endl;
				return;
			}
		
			if(size() == 1) {
				delete head;
				head = tail = nullptr;
				_size--;
				return;
			}
		
			// Need to find the SECOND-to-last node,
			// since this is a singly linked list (no "prev" pointer)
			Node* curr = head;
			while(curr->next != tail) {
				curr = curr->next;
			}
		
			delete tail;
			tail = curr;         // second-to-last node becomes new tail
			tail->next = nullptr;
			_size--;
		}


		int size() {
			return _size;
		}
		
};