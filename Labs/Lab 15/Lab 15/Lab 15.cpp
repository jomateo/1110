#include <iostream>
using namespace std;

/*
 Lab 15: Write a function that checks for duplicates of a sorted array. Return index of first spot of a duplicate.
 */

int duplicates(int [], int);    //prototypes

const int SIZE = 10;

int main () {
    
    int index, elts = 10, numbers[] = {12, 43, 56, 56, 15,
                                        54, 65, 90, 87, 67};
    
    index = duplicates(numbers, elts);
    
    cout << "The index of the duplicate is: " << index << ". -1 means there were no duplicates.\n";
    
    return 0;
    
}

int duplicates (int arr[], int n) {
    int index = -1;
    for (int i = 0; i < n-1; i++){
        if (arr[i] == arr[i+1]){
            index = i;
            return index;
        }
    }
    return index;
}