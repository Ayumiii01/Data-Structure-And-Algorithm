#include <iostream>
#include "student.hpp"
#include <cstdlib>
#include <cmath>
using namespace std;

class Course {
	string topic;
	Student** students;
	int size;
	int capacity = 5;
	
	public:
		//constructor
		Course(string topic) {
			this -> topic = topic;
			students = new Student*[capacity];
			size = 0;
		}
		
		//adding Student
		void addStudent(Student* s) {
			if(size == capacity) {
				capacity = (int) ceil(capacity * 1.5);
				Student** newArray = new Student*[capacity];
				for(int i = 0; i < size;i++) {
					newArray[i] = students[i];
				}
				
				delete[] students;
				students = newArray;
			}
			students[size++] = s;
		}
		
		void print() {
			cout << "\nTitle: " << topic << endl;
			cout << "Student size: " << size << " / " << capacity << endl;
			for(int i = 0; i < capacity; i++) {
				if(i >= size) {
					cout << i + 1 << ". (none)" << endl;
				} else {
					Student* s = students[i];
					cout << i + 1 << ". " << s -> name << " (" << s -> program << " " << s -> year << ")" << endl;
				}
			}
			cout << endl;
		}
};