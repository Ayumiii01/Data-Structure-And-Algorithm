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
		
		int remove(int num) {
			int pos = -1;
			for(int i = 0; i < size; i++) {
				if(array[i] == num) {
					pos = i;
					break;
				}
			}
			
			if(pos == -1) {
				return -1;
			}
			
			for(int i = size - 1; i > pos - 1; i--) {
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
			
			return pos + 1;
		}
		
		int get(int pos) {
			return array[pos + 1];	
		}
		
		int removeAll(int num) {
			int count = 0;
			for(int i = 0; i < size; i++) {
				if(array[i] == num) {
					count++;
					for(int j = i; j < size - 1; j++) {
						array[j] = array[j + 1];
					}
					size--;
					i--;
				}
			}
			
			if(capacity > 0) {
				dynamic_deduce();
			}
			
			return count;	
		}
		
		void dynamic_deduce(){
			int temp = (int)(capacity * (3.0/4.0));
			
			if(size <= temp) {
				int tempCap = capacity - (int)(capacity * 0.2);
				if(tempCap < 5) {
					tempCap = 5;
				}
				array = (int*) realloc(array, tempCap * sizeof(int));
				capacity = tempCap;
			}
		}
		
		void print() {
			cout << "Size " << size << " / " << capacity << endl;
			int i;
			for(i = 0; i < size; i++) {
				cout << array[i] << " ";
			}
			for(; i < capacity; i++){
				cout << " ? ";
			}
			cout << endl;
			cout << (int) 10.9 << endl;
		}
};