#include "stack.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class ArrayStack : public Stack {
	char* chr;
	int cap;
	int _size;

	void grow() {
		int newCap = cap + (int)ceil(cap * 0.5);
		char* newArr = new char[newCap];
		for (int i = 0; i < _size; i++) {
			newArr[i] = chr[i];
		}

		delete[] chr;   // fix: free the old array
		chr = newArr;
		cap = newCap;
	}

	void shrink() {
		if (cap <= 5) {
			return;
		}

		int newCap = (int)(cap * 8.0 / 10.0);

		if (newCap < 5) {
			newCap = 5;
		}

		if (newCap >= cap) {
			return;
		}

		char* newArr = new char[newCap];
		for (int i = 0; i < _size; i++) {
			newArr[i] = chr[i];
		}

		delete[] chr;
		chr = newArr;
		cap = newCap;
	}

public:
	ArrayStack() {
		_size = 0;      // fix: assign to members, don't redeclare
		cap = 5;
		chr = new char[cap];
	}

	~ArrayStack() {     // fix: free memory on destruction
		delete[] chr;
	}

	void push(char c) {
		if (_size == cap) {
			grow();
		}
		chr[_size++] = c;
	}

	char pop() {
		if (_size <= 0) {
			return ' ';
		}
		_size--;
		char c = chr[_size];
		if (_size * 10 <= cap * 6) {
			shrink();
		}

		return c;
	}

	char top() {
		if (_size == 0) {
			return ' ';
		}

		return chr[_size - 1];
	}

	int size() {
		return _size;
	}

	bool isEmpty() {
		return size() <= 0;
	}
};