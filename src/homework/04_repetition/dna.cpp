//add include statements
#include<iostream>
#include "dna.h"
#include<string>

using std::cout;
using std::cin;



//add function(s) code here
void menu()
{
    cout<<"[1] Factorial \n";
    cout<<"[2] Greatest Common Factor (GCD) \n";
    cout<<"[3] Exit \n\n";
    cout<<"Please Select an Option\n";
}

int factorial(int num)
{
    int sum = 1;
    while (num > 0)
    {
        sum = sum * num;
        num --; 
    }
    return sum;
}

int gcd(int num1, int num2)
{
    while(num1 == num2)
    {
        if (num1 > num2)
        {
            int store_value = num2;
            num2 = num1;
            num1 = store_value;
        }
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }
        return num1;
    }
}