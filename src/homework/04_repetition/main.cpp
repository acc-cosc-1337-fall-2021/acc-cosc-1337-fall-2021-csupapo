//write include statements
#include<iostream>
#include "dna.h"
//write using statements
using std::cout;
using std::cin;
using std::string;

//initialize variables
int option;
int num;
int num1, num2;
int gcd_answer;


int main() 
{
	string run = "no";
	menu();
	cin>>option;
	do
	{
		if (option == 1)
	{
		cout<<"Please Enter a Number\n";
		cin>>num;
		num = factorial(num);
		cout<<"The answer is " << num;
		return num;
	}
	if (option == 2)
	{
		cout<<"Please Enter First Value\n";
		cin>>num1;
		cout<<"Please Enter Second Value\n";
		cin>>num2;
		gcd_answer = gcd(num1, num2);
		cout<<"Your GCD is " << gcd_answer;
		return gcd_answer;
	}
	if (option == 3)
	{
		cout<<"Are you sure you want to exit?";
		cin>>run;
	}
	
	}
	 while (run == "no");
	
}