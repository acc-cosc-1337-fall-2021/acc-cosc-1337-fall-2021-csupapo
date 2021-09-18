//write include statements
#include "hwexpressions.h"
#include <iostream>

//write namespace using statement for cout
using std::cout; using std::cin;

int main()
{
	// Create variables
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	// Ask user for inputs and use them as parameters for previously created functions in .cpp file
	cout<< "What is your meal amount?";
	cin>> meal_amount;
	
	tax_amount = get_sales_tax_amount(meal_amount);
	
	cout<< "Tip Conversion (Enter .15 for 15%, .2 for 20%, .25 for 25%)"; 
	cout<< "How much is your tip?";
	cin>> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = tip_amount + tax_amount + meal_amount;

	// Display User's Receipt 
	cout<< "Your Receipt \n"; 
	cout<< "Meal Amount: " << meal_amount << "\n"; 
	cout<< "Sales Tax: " << tax_amount << "\n"; 
	cout<< "Tip Amount: " << tip_amount << "\n";
	cout<< "Total: " << total;  
	
	return 0;
}
