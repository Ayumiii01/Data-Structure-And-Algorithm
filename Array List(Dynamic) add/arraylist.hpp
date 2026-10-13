#include <iostream>
#include "list.hpp"
#include <cstdlib>
#include <math.h>
using namespace std;

class ArrayList : public List {
	int* array;
	int size;
	int capacity = 5;
	
	void grow() {
		capacity = (int) ceil(capacity * 1.5);
		array = (int*) realloc(array, capacity * sizeof(int));
	}
	
	public: 
	//constructor
	ArrayList() {
		array = (int*) calloc(capacity, sizeof(int));
		size = 0;
	}
	
	void add(int num) {
		if(size == capacity) {
			grow();
		}
		array[size++] = num;
	}
	
	int remove(int num) {
		return 0;
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
			cout << " ?";
		}
		
		cout << endl;
	}
};