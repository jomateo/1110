/*
 Lab 4
 Read in two numbers.
 Test each number to see if the number is negative or positive (assume 0 is positive).
 Print a messag about each number telling whether it is positive or negative.
 Do this again for 2 more numbers.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//define the int x,y
	int x, y;
	cout << "Enter two intergers and I will tell you if it is positive or negative.";
	cin >> x >> y;
	cout << "You entered: " << x << " and " << y << endl;
	
	//0 is considered positive so -1 and below are negs.
	if (x > -1)
		cout << x << " is a positive interger.\n";
	else
		cout << x << " is a negative interger.\n";
	if (y > -1)
		cout << y << " is a positive interger.\n";
	else
		cout << y << " is a negative interger." << endl;
	
	//do it again for 2 more intergers
	cout << "\nEnter two intergers and I will tell you if it is positive or negative.";
	cin >> x >> y;
	cout << "You entered: " << x << " and " << y << endl;
	
	//0 is considered positive so -1 and below are negs.
	if (x > -1)
		cout << x << " is a positive interger.\n";
	else
		cout << x << " is a negative interger.\n";
	if (y > -1)
		cout << y << " is a positive interger.\n";
	else
		cout << y << " is a negative interger.\n";
	
	return 0;
}