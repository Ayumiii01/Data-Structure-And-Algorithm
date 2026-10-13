#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
	int* array;
	int size;
	int capacity = 5;
	
	public:
		
		//constructor
		ArrayList() {
			array = (int*) calloc(capacity, sizeof(int));
			size = 0;
		}
		
		void add(int num) {
			if(size == capacity) {
				capacity = (int) ceil(capacity * 1.5);
				array = (int*) realloc(array, capacity * sizeof(int));
			}
			array[size++] = num;
		}
		
		void addAt(int pos, int num) {
			if(size == capacity) {
				capacity = (int) ceil(capacity * 1.5);
				array = (int*) realloc(array, capacity * sizeof(int));
			}
			
			//shift
			for(int i = size; i > pos - 1; i--) {
				array[i] = array[i - 1];
			}
			
			array[pos - 1] = num;
			size++;

		}
		
		void remove(int num) {
			int pos = -1;
			for(int i = 0; i < size; i++) {
				if(array[i] == num) {
					pos = i;
					break;
				}
			}
			
			if(pos == -1) {
				return;
			}
			
			for(int i = pos; i > size - 1; i++) {
				array[i] = array[i + 1];
			}
			size--;
			
			if(size <= (2.0/3.0) * capacity && capacity > 5) {
				int newCap = (int)(capacity * 0.25);
				if(newCap < 5) {
					newCap = 5;
				}
				
				array = (int*) realloc(array, newCap * sizeof(int));
				capacity = newCap;
			}
		}
		
		int removeAt(int pos) {
			int removed = array[pos - 1];
			
			for(int i = pos - 1; i < size - 1;i ++) {
				array[i] = array[i + 1];
			}
			
			if(size <= (2.0/3.0) * capacity && capacity > 5) {
				int newCap = (int)(capacity * 0.25);
				if(newCap < 5) {
					newCap = 5;
				}
				
				array = (int*) realloc(array, newCap * sizeof(int));
				capacity = newCap;
			}
			size--;
			return removed;
		}
		
		int get(int pos) {
			return array[pos - 1];
		}
		
		void print() {
			cout << "Size: " << size << " / " << capacity << endl;
			int i;
			for(i = 0; i < size; i++) {
				cout << array[i] << " ";
			}	
			for(; i < capacity; i++) {
				cout << " ? ";
			}
			cout << endl;
		}
};