/*
 Searching for an element in an array.
 Step 1: Define an array and read in values.
 Step 2: Ask the user for a single value.
 Step 3: Tell the user wether or not the number appears in the array.
 Step 4: Tell the user the index of that number.
 */

#include <iostream>
using namespace std;

const int SIZE = 100;

int main (){

    int numbers[SIZE], entry, index = 0;
    
    cout << "Enter a value, enter -1 to stop: ";
    cin >> numbers[index];
    
    while (numbers[index] != -1) {
        index++;
        cout << "Enter a value, enter -1 to stop: ";
        cin >> numbers[index];
    }
    
    cout << "Enter a number and I will tell you if it was entered: ";
    cin >> entry;
    
    for (int i = 0; i < index; i++) {
        
        if (numbers[i] == entry) {
            cout << "This number is in the array. Its index is " << i << endl;
            return true;
        }
    }
    
    return 0;
}