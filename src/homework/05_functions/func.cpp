//Include statements
#include<iostream>
#include "func.h"

using std::cout; 
using std::cin; 
using std::string;

// Global Variables
string dna;

// GC Content Function
double get_gc_content(const string& dna)
{
    int c_count = 0; 
    int g_count = 0;
    double sum_count;
    double gc_content;

    for (int i = 0; dna[i] != '\0'; i++)
    {
        if (dna[i] == 'c' || dna[i] == 'C')
        {
            c_count = c_count + 1;
        }
        
        else if (dna[i] == 'g' || dna[i] == 'G')
        {
            g_count = g_count + 1;
        }

    }
    sum_count = c_count + g_count;
    gc_content = sum_count / dna.length();

    return gc_content;
}

// Reverse String Function
string get_reverse_string(string dna)
{
    int copy = dna.length();
    string new_dna;

    for(int i = copy-1; i >= 0; i--)
      new_dna.push_back(dna[i]);

    return new_dna;
}

// DNA Complement Function
string get_dna_complement(string dna)
{
    char ch1 = 'A';
    char ch2 = 'T';
    char ch3 = 'C';
    char ch4 = 'G';

    string dna_copy = dna;

    for (int i = 0; dna_copy[i]; ++i) 
    {
        if (dna_copy[i] == ch1)
        {
            dna_copy[i] = ch2;
        } 

        else if (dna_copy[i] == ch2)
        {
            dna_copy[i] = ch1;
        }

        else if (dna_copy[i] == ch3)
        {
            dna_copy[i] = ch4;
        }

        else if (dna_copy[i] == ch4)
        {
            dna_copy[i] = ch3;
        }
    }

    string output = get_reverse_string(dna_copy);

    return output;
}
int menu(int num)
    {
        auto exit_confirmation = 'y';

    do
    {
        auto user_input = 3;
        cout<<"\nMAIN MENU\n"
        "\nType 1 for GC Content.\n"<<
        "Type 2 for DNA Compliment\n"<<
        "Type 3 to exit.\n"
        "\nChoose a selection from above: ";
        cin>>user_input;

        switch(user_input)
        {
        // GC-Content Option
        case 1:
            cout<<"\n"<<"(GC Content Option)";
            cout<<"\nEnter DNA Strand: "; 
            cin>>dna;
            cout<<"\nThe GC Content in the DNA Strand is: "<<get_gc_content(dna)<<"\n";
            cout<<"\n ------ Returning to Main Menu ------\n\n";
            break;
        
        // DNA Complement Option
        case 2: 
            cout<<"\n"<<"(DNA Complement Option)";
            cout<<"\nEnter DNA Strand: "; 
            cin>>dna;
            cout<<"\nThe Reverse Complement in the DNA Strand is: "<<get_dna_complement(dna)<<"\n\n";
            cout<<"\n ------ Returning to Main Menu ------\n\n";
            break;

        // Exit Option
        case 3:
            cout<<"Please confirm that you want to exit application.\n"<<
            "Type answer here (y/n): ";
            cin>>exit_confirmation;
        
        // Menu Repeats until user confirms exit.
        if (exit_confirmation == 'y' || exit_confirmation == 'Y')
        {
                exit_confirmation = '\0';
        }

        else
        {
            exit_confirmation = 'y';
        }
            break;
        default:
            cout<<"\nInvalid entry\n";
        }

    } while (exit_confirmation == 'y');
    }
