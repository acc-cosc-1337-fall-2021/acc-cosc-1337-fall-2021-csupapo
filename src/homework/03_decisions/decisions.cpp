//write include statement for decisions header
#include "decisions.h"
#include<iostream>

using std::string; 
using std::cout; 
using std::cin;

//Write code for function(s) code here
string letter_grade;
int grade;
string menu(int option)
{
        if(option == 1)
        {
            cout << "(If Method)" << "\n";
            cout << "Enter your grade (0-100): ";
            cin >> grade;
            get_letter_grade_using_if(grade);
            return letter_grade; 
        }
        else if (option == 2)
        {
            cout << "(Switch Method)" << "\n";
            cout << "Enter your grade (0-100): ";
            cin >> grade;
            get_letter_grade_using_switch(grade);
            return letter_grade;
        }
        else if (option == 3)
        {
            return "Program Exited. Thank you.";
        }
        else
        {
            return "Invalid Option. Program will close. Thank you.";
        }
}
string get_letter_grade_using_if(int grade)
{

    if(grade >= 90 && grade <=100)
    {
        letter_grade = 'A';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
    }
    else if(grade >= 80 && grade <=89)
    {
        letter_grade = 'B';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
    }
    else if(grade >= 70 && grade <=79)
    {
        letter_grade = 'C';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
    }
    else if(grade >= 60 && grade <=69)
    {
        letter_grade = 'D';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
    }
    else if(grade >= 0 && grade <=59)
    {
        letter_grade = 'F';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
    }
    else
    {
        cout << "That grade is not in the range specified.";
    }
} 
std::string get_letter_grade_using_switch(int grade)
{
    switch (grade)
    {
    case 90 ... 100:
        letter_grade = 'A';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
        break;
    case 80 ... 89:
        letter_grade = 'B';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
        break;
    case 70 ... 79:
        letter_grade = 'C';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
        break;
    case 60 ... 69:
        letter_grade = 'D';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
        break;
    case 0 ... 59:
        letter_grade = 'F';
        cout << "You're letter grade is: " << letter_grade; 
        return letter_grade;
        break;
    default:
        cout << "That grade is not in the range specified.";
        break;
    }

}