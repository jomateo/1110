/*Lab 5:
 Ask the user to enter a number from 1 to 5.
 If the user enters an invalid input, exit from your program with a message.
 If the user enters a number from 1 to 5, print a different message based on the number they entered.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
	int number;
	cout << "Enter an interger from 1 to 5:\n";
	cin >> number;

	if (number > 5 || number < 1){
		cout << "The number you entered is not between 1 and 5.\n";
		exit(1);
	}
	else if (number == 5){
		cout << "Nice try, but try again.\n";
	}
	else if (number == 4){
		cout << "Boo! You lose!\n";
	}
	else if (number == 2){
		cout << "You lost! :(\n";
	}
	else if (number == 1){
		cout << "Not a winner!\n";
	}
	else
		cout << "We have a winner!\n";
	return 0;
}
