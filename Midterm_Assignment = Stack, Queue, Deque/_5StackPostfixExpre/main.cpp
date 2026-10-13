#include <iostream>
#include <string>
#include "arraystack.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stack* stack = new ArrayStack();
	string input;
	do{
		cout << "Enter: ";
		cin >> input;
		
		if(input == "+") {
			int b = stack->pop();
			int a = stack->pop();
			stack->push(a + b);
		} else if(input == "-") {
			int b = stack->pop();
			int a = stack->pop();
			stack->push(a - b);
		} else if(input == "*") {
			int b = stack->pop();
			int a = stack->pop();
			stack->push(a * b);
		} else if(input == "/") {
			int b = stack->pop();
			int a = stack->pop();
			stack->push(a / b);
		}  else if(input == "x") {
			cout << "Exiting..." << endl;
		} else {
			int n = stoi(input);
			stack->push(n);
		}
	} while(input != "x");
	
	cout << "Answer is " << stack->pop() << endl;

	return 0;
}