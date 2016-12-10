/*
 Lab 3
 Define variables and expressions to do the following:
 
 Given a price, calculate the sales tax on the price, which is 8.875% of the price. Print the base price and the sales tax and print the total price (including tax).
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double tax, price, sales_tax, total;
	tax = .0875;
	price = 11.05;
	sales_tax = tax * price;
	total = price + sales_tax;
	
	cout << "The price is: $" << price << ". The sales tax is: $" << sales_tax << ". The total price is: $" << total << endl;
	return 0;
}
