//write include statements
#include "decisions.h"
#include<iostream>

//write namespaces
using std::string; 
using std::cout; 
using std::cin;

//Write Function code
int main() 
{
	//Create variables
	string letter_grade;
	int grade;
	int option;

	cout << "Main Menu" << "\n" << "Select an Option" << "\n";
	cout << "1 - Letter grade using if" << "\n";
	cout << "2 - Letter grade using switch" << "\n";
	cout << "3 - Exit" << "\n";
	cin >> option;
	
	// Call menu function
	letter_grade = menu(option);
}