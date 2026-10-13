#include <iostream>
#include "course.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Course* csit = new Course("CSIT221");
	char op;
	Student* s;
	string res;
	string name;
	while(true) {
		cout << "Op: ";
		cin >> op;
		switch(op) {
			case 'a':
				s = new Student;
				cout << "Name: ";
				cin >> s ->name;
				cout << "Program and year: ";
				cin >> s -> program >> s -> year;
				csit -> addStudent(s);
				break;
			case 'p':
				csit -> print();
				break;
			case 'x':
				cout << "Exiting..." << endl;
				return 0;
				break;
		}
	}
	
	return 0;
}