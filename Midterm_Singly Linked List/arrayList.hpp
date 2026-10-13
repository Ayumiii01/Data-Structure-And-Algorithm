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
		
		~ArrayList() {
			while(head != nullptr) {
				node* temp = head->next;
				delete head;
				head = temp;
			}
			cout << "Destroyed Array Lists." << endl;
		}
		
		
		void add(int num) { //addLast
			node* n = new node(num);
			
			if(size == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				tail = n;
			}
			
			size++;
		}
		
		void addFirst(int num) {
			node* n = new node(num);
			
			if(size == 0) {
				add(num);
			} else {
				n->next = head;
				head = n;	
			}
		}
		
	
		int get(int pos) {
			node* curr = head;
			
			if(pos > size || pos < 1) {
				return -1;
			}
			for(int i = 0; i < pos - 1; i++) {
				curr = curr->next;
			}
			
			return curr->elem;
		}             		// value at pos (1-based), or -1 if invalid
    	
    	void addAt(int num, int pos) {
			if(pos > size || size == 1) {
				add(num);
				return;
			}
			
			node* n = new node(num);
			if(size <= 1) {
				n->next = head;
				head = n;
			} else {
				node* curr = head;
				for(int i = 1; i < pos - 1; i++) {
					curr = curr->next;
				}
				n->next = curr->next;
				curr->next = n;
			}
			
			size++;
		}					// insert so num sits at position pos (1-based)
    	
    	void removeFirst() {
			if(head == nullptr) {
				return;
			}
			
			node* temp = head;
			head = head->next;
			
			delete temp;
		}
		
		void removeLast() {
			if(head == nullptr) {
				return;
			}	
			
			if(head == tail) {
				delete head;
				tail = nullptr;
				head = nullptr;
				return;
			}
			
			node* curr = head;
			while(curr->next != tail) {
				curr = curr->next;
			}
			
			delete tail;
			tail = curr;
			tail->next = nullptr;
		}
    	
		void removeAt(int pos) {
		    if (pos > size || pos < 1) {
		        return;
		    }
		
		    if (pos == 1) {
		        node* temp = head;
		        head = head->next;
		        delete temp;
		        size--;
		        return;
		    }
		
		    node* curr = head;
		    node* prev = nullptr;
		
		    for (int i = 1; i < pos; i++) {   
		        prev = curr;
		        curr = curr->next;
		    }
		
		    prev->next = curr->next;
		    delete curr;
		    size--;
		}         			// remove first match; return 1 if removed, else 0
    	
		int removeAll(int num) {
		    int count = 0;
		
		    node* curr = head;
		    node* prev = nullptr;
		
		    while (curr) {
		        if (curr->elem == num) {
		            node* toDelete = curr;
		
		            if (prev == nullptr) {
		                // removing the head
		                head = curr->next;
		                curr = head;
		            } else {
		                // removing a middle or last node
		                prev->next = curr->next;
		                curr = prev->next;
		            }
		
		            if (toDelete == tail) {
		                tail = prev;   // update tail if we removed the last node
		            }
		
		            delete toDelete;
		            size--;
		            count++;
		        } else {
		            prev = curr;
		            curr = curr->next;
		        }
		    }
		
		    return count;
		}      				 // remove every match; return how many
	
   
		
		void print() {
			if(head == nullptr && tail == nullptr) {
				cout << "Nothing to show..." << endl;
				return;
			}
			node* curr = head;
			while(true) {
				cout << curr -> elem;
				if(curr != tail) {
					cout << "->";
				} else {
					cout << "->NULL" << endl;
					break;
				}
				curr = curr->next;
			}
			cout << endl;
		}
};