#include <iostream>
using namespace std;

/*
 Modify findmaxmin function to accept only 2 parameters. The function should put the larger of the two parameters into the first parameter, and the smaller into the second parameter. Use the idea of swap.
 */

void findmaxmin (int&, int&); //prototype

int main(){
    int num1 = 3, num2 = 34;

    findmaxmin(num1, num2);

    cout << "In main num1 is: " << num1 << " and num2 is: " << num2 << endl;
    return 0;
}

void findmaxmin (int &big, int &small){
    int temp;
    if (big < small){
        temp = big;
        big = small;
        small = temp;
    }
    return;
}