/*
 Write two functions. The first function should read a person's name, and print hello name, the 2nd should accept 3 double values and print their sum.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void first(string firstname){
    cout << "Hello " << firstname << endl;
    return;
}

void second(double num1, double num2, double num3){
    double sum;
    sum = num1 + num2 + num3;
    cout << "The sum of " << num1 << ", " << num2 << ", and " << num3 << " is: " << sum << endl;
    return;
}

int main (){
    first("Alice");
    second (1, 2, 3);
    return 0;
}