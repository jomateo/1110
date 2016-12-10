/*
 Write a function to test whether a value is divisible by some number that the user inputs.
 in main: user enters 2 numbers, x and y. Check whether x is divisible by y by calling your function. main will print whether x is divisible by y or not.
 */

#include <iostream>
using namespace std;

//function protypes
bool checkDiv (int, int);

int main(){
    int x, y;
    
    cout << "Enter two numbers, and I will check if they are divisible by eacother: ";
    cin >> x >> y;
    
    if (checkDiv (x, y))
        cout << "These 2 numbers are divisible by eachother.\n";
    else
        cout << "These 2 numbers are not divisible by eachother.\n";
   
    return 0;
}

bool checkDiv (int x, int y){
    if (x%y == 0)
        return true;
    else
        return false;
}