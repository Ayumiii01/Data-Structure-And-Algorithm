#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class ArrayList : public List {
	node *head, *tail;
	int size = 0;
	int* arr = new int[size];
	
	public:
		ArrayList() {
			head = tail = nullptr;
		}
		
		void add(int num) {
			node* n = new node(num);
			
			if(size == 0) {
				head = tail = n;
			} else {
				tail->next = n;
				tail = n;
			}
			
			arr[size++] = num;
		}
		
		void print() {
			node* curr = head;
			
			while(true) {
				cout << curr->elem;
				if(curr != tail) {
					cout <<  "->";
				} else {
					cout << "->Null" << endl;
					break;
				}
				curr = curr->next;
			}
		}
		
		int _size() {
			return size;
		}
		
		int get(int p) {
			return arr[p-1];
		}
};