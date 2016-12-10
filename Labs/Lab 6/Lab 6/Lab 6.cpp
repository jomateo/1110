/*
LAB 6:
Ask the user to enter a number greater than 0.
If the user enters invalid input, loop until they enter valid input.

Use a while loop to:

Print all of the odd integers that are greater than 0,
and less than the number entered.

Count how many numbers are printed.

After exiting the while loop, print the count.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
     int num = 0, num_entered, count = 0;
     cout << "Enter a number greater than 0: ";
     cin >> num_entered;

     while (num_entered <= 0) {
          cout << "Enter a number greater than 0: ";
          cin >> num_entered;
     }
     while (num < num_entered){
          if (num % 2 == 1) {
               cout << num << endl;
               count ++;
          }
          num ++;
     }
     cout << "There are " << count <<" odd numbers between 0 and " << num_entered << endl;
     return 0;
}
