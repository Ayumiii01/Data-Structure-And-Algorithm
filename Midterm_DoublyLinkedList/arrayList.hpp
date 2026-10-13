#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class ArrayList : public List {
	node *head, *tail;
	int size;
	
	public:
		ArrayList() {
			head = tail = nullptr;
			size = 0;
		}
		
		void add(int num) { // addLast
			node* n = new node(num);
			
			if(size == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				n->prev = tail;
				tail = n;
			}
			
			size++;
		}
		
		void addFirst(int num) {
			if(size == 0) {
				add(num);
				return;
			}
			node* n = new node(num);
			
			n->next = head;
			n->prev = nullptr;
			head->prev = n;
			head = n;
			
			size++;
		}
		
		void addAt(int num, int pos) {
			if(size == 0) {
				add(num);
				return;
			}
			if(pos == 1) {
				addFirst(num);
				return;
			}
			if(pos > size || pos < 1) {
				return;
			}
			
			node* n = new node(num);
			node* temp = nullptr;
			node* curr = head;
			
			for(int i = 1; i < pos; i++) {
				temp = curr;
				curr = curr->next;
			}
			
			curr->prev = n;
			n->prev = temp;
			temp->next = n;
			n->next = curr;
			
			size++;
		}
		
		void remove() { // removeLast
			if(head == nullptr && tail == nullptr) {
				return;
			}
			
			if(size == 1) {
				delete head;
				head = nullptr;
				tail = nullptr;
				size--;
				return;
			}
			
			node* temp = tail;
			temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = nullptr;
			size--;
		}
		
		void removeFirst() {
			if(head == nullptr && tail == nullptr) {
				return;
			}
			
			if(size == 1) {
				delete head;
				head = nullptr;
				tail = nullptr;
				size--;
				return;
			}
			
			node* temp = head;
			temp = temp->next;
			delete head;
			head = temp;
			head->prev = nullptr;
			size--;
		}
		
		void removeAt(int pos) {
			if(pos == size) {
				remove();
				return;
			}
			if(pos == 1) {
				removeFirst();
				return;
			}
			if(pos > size || pos < 1) {
				return;
			}
			if(size == 1) {
				delete head;
				head = tail = nullptr;
				size--;
				return;
			}
			
			node* curr = head;
			node* temp = nullptr;
			
			for(int i = 1; i < pos; i++) {
				temp = curr;
				curr = curr->next;
			}
			
			temp->next = curr->next;
			delete curr;
			curr = temp->next;
			curr->prev = temp;
			size--;
		}
		
		int removeAll(int num) {
		    if (size == 0) {
		        return 0;
		    }
		
		    int ctr = 0;
		    node* curr = head;
		
		    while (curr != nullptr) {
		        node* temp = curr->next;  // save before we potentially delete curr
		
		        if (curr->elem == num) {
		            // fix backward link (or head)
		            if (curr->prev != nullptr) {
		                curr->prev->next = curr->next;
		            } else {
		                head = curr->next;
		            }
		
		            // fix forward link (or tail)
		            if (curr->next != nullptr) {
		                curr->next->prev = curr->prev;
		            } else {
		                tail = curr->prev;
		            }
		
		            delete curr;
		            size--;
		            ctr++;
		        }
		
		        curr = temp;
		        //ctr++;
		    }
		
		    return ctr;
		}
		
		void print() {
			node* curr = head;
			
			cout << "From head: ";
			while(curr) {
				cout << curr->elem << "->";
				if(curr == tail) {
					cout << "NULL";
				}
				curr = curr->next;
			}
			cout << endl;
			
			curr = tail;
			cout << "From tail: NULL";
			while(curr) {
				cout << "<-" << curr->elem;
				curr = curr->prev;
			}
			cout << endl;
		}
};