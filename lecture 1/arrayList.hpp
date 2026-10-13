#include <iostream>
#include "list.hpp"

using namespace std;

class ArrayList : public List {	
	private:
	int arr[5];
	int _size = 0;
	
	void add(int n) {
		arr[_size++] = n;
	}
	
	void print() {
		for(int i = 0; i < _size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	int size() {
		return _size;
	}
	
	void addFirst(int n) {
		for(int i = _size - 1; i >= 0; i--) {
			arr[i] = arr[i + 1];
		}
		arr[0] = n;
		_size++;
	}
	
	void removeLast() {
		arr[_size--];
	}
	
	void removeFirst() {
		for(int i = 0; i < _size; i++) {
			arr[i] = arr[i + 1];
		}
		_size--;
	}
	
	void addPosition(int pos, int n) {
		for(int i = _size - 1; i >= pos - 1; i--) {
			arr[i + 1] = arr[i];
		}
		arr[pos - 1] = n;
		_size++;
	}
	
	void removePosition(int pos) {
		for(int i = pos - 1; i < _size; i++) {
			arr[i] = arr[i + 1];
		}
		_size--;
	}
	
	void sortedNumbers() {
		int temp;
		for(int i = 0; i < _size - 1; i++) {
			for(int j = i + 1; j < _size; j++) {
				if(arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp; 
				}
			}
		}
	}
};