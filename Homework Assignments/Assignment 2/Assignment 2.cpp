/*
 Assignment 2
 Author: Johanny Mateo
 Date: Wednesday, September 14, 2016
 Description: Property Tax Calculation
 */

/*
 CISC 1110 Fall 2016 Assignment #2 -- Property Tax Calculation
 A county collects property tax on the assessed value of a property. Let's assume that the "assessed value" is 57% of the property's actual value. For example, if a property's value is $100,000, the assessed value is $57,000. Property tax is then 64 cents for each $100 of the assessed value. The property tax for the above example would be $364.80.
 Write a complete C++ program, including at least one good comment at the top to calculate the property tax for a property.
 Specifically, the program should:
 1. Print a sentence saying what the program does.
 2. Declare variables for value, assessedValue, taxAmount.
 3. Assign a property's value to value variable (you can make it up).
 4. Evaluate the formulas to calculate the assessed value and taxAmount.
 5. Print all of the calculations to the screen, neatly labeled.
 6. Do the same thing again for another property with a different value.
 */

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	//What does this program do?
	string purpose = "Given its value, this program calculates the property tax of a property.";

	float     value = 128000.00,
			assesssedValue,
			taxAmount;

	//Multiply the value by 57% to find the assessed value
	assesssedValue = value * .57;

	//To find the tax amount, divide the assessedValue by 100 (each $100 is taxed by 64 cents) and multiply the answer by 64 cents.
	taxAmount = (assesssedValue/100.00)*.64;

	cout	<< purpose << endl << endl
          << "The property's value is " << value << ".\n"
          << "Its assessed value is " << assesssedValue << ".\n"
          << "The tax amount is " << taxAmount << ".\n\n";

     //New value for property.
	value = 256000.00,
	assesssedValue = value * .57;
	taxAmount = (assesssedValue/100.00)*.64;

	cout	<< "The new property's value is " << value << ".\n"
          << "Its new assessed value is " << assesssedValue << ".\n"
          << "The new tax amount is " << taxAmount << ".\n\n";

	return 0;
} //end main

/*
 Memory Trace:

	value
	128000
	256000

	assessedValue
	72960
	145920

	taxAmount
	466.944
	933.888


 Handcheck:

	value = 128,000

	assessedValue	= 128,000*.57
                    = 72,960

	taxAmount	= (72,960/100)*.64
               = 729.60*.64
               = 466.944

	New Value:

	value = 256,000

	assessedValue	= 256,000*.57
                    = 145,920

	taxAmount	= (145,920/100)*.64
               = 1,459.20*.64
               = 933.88

*/
