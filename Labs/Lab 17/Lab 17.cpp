/*
 Write a program to read in strings (loop)
 If the length of the string >10, print "that is long", otherwise, print thank you.
 You decide when to terminate the loop
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    string  word,
            thanks = "Thank you\n",
            nothanks = "That is long\n";
    
    for (int i = 0; i < 5; i++){
        cout << "Enter a string, I will say 'thank you' if the string length is less than or equal to 10, and 'that is long' if the string length is greater than 10. ";
        cin >> word;
        
        if (word.length() <= 10)
            cout << thanks;
        else
            cout << nothanks;
        
    }
    
    return 0;
}