//write include statements
#include "data_types.h"
#include<iostream>

//write namespace using statement for cout
using std::cout; using std::cin;


//Call multiply_numbers with 10 and 10 parameter values and display function result

int main()
{
	int num;
	//Asks user for an input and stores the input into variable num
	cout<<"Please enter a number: ";
	cin>> num;

	//Use the user's input as a parameter for the function "multiply_numbers" and displays the calculation
	int result = multiply_numbers(num);
	cout<<"First result is: " << result;

	//Initializes the variable "num1" for the function "multiply_numbers" and displays the calculation
	int num1 = 4;
	result = multiply_numbers(num1);
	cout<<"Second result is: " << result;	
	return 0;
}
