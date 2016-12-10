/*
 Define an array of int or double.
 Read in values to fill up the array.
 Iterate through the array and count how many numbers are positive and how many are negative.
 
 Print the counts.
 Use at least 2 for loops.
 */

#include <iostream>
using namespace std;

int const SIZE = 5;

int main (){
    int num[SIZE],      //array
        positive = 0,   //positive counter
        negative = 0;   //negative counter
    
    cout << "Enter 5 numbers, and I will tell you how many are positive and how many are negative: ";
    
    for (int i = 0; i < SIZE; i++){
        cin >> num[i];
    }
    
    for (int i = 0; i < SIZE; i ++){
        if (num[i] < 0)
            negative++;
        else
            positive++;
    }
    
    cout << "You entered " << positive << " positve numbers, and " << negative << " negative numbers."
         << endl;
    return 0;
}