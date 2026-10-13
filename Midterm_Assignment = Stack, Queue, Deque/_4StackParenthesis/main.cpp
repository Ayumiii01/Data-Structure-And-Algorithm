#include <iostream>
#include <string>
#include "arraystack.hpp"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_balanced_parenthesis(string str) {
	Stack* stack = new ArrayStack();
	
	for(int i = 0; i < str.length(); i++) {
		char c = str[i];
		
		if(c == '(' || c == '{' || c == '[') {
			stack->push(c);
		} else if(c == ')' || c == '}' || c == ']') {
			if(stack->isEmpty()) {
				return 3;
			}
			
			char p = stack->top();
			
			if((c == ')' && p != '(') || (c == '}' && p != '{') || (c == ']' && p != '[')) {
				return 1;
			}
			
			stack->pop();
		}
	}
	
	if(!stack->isEmpty()) {
		return 2;
	}
	
	return 0;
}


int main(int argc, char** argv) {
	string str;
	do{
		cout << "Enter a string with a parenthesis: ";
		cin >> str;
		
		if(str == "DONE") {
			break;
		}
		
		int res = is_balanced_parenthesis(str);
		switch(res) {
			case 0:
				cout << "Balanced" << endl;
				break;
			case 1:
				cout << "Not balanced cuz of mismatch" << endl;
				break;
			case 2:
				cout << "Not balanced due to missing closing parenthesis" << endl;
				break;
			case 3:
				cout << "Not balanced due to missing opening parenthesis" << endl;
				break;
			default:
				cout << "Something went wrong dude." << endl;
		}	
	} while(str != "DONE");
	
	return 0;
}