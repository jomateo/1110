// pgm29 -- modified employee program with
// ARRAYS and FUNCTIONS
// 11/16/16
/* Goal: write functions for:
 1. reading in data
 2. calculating pay
 3. displaying data
 4. finding maximum
 5. calculate total */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int readinData(int[], double[], double[]);
void displayData(double[], int);
void calculatePay(double[], double[], double[], int);
double findMax(double[], int);
double addPay (double[], int);

const int SIZE=150;

int main()
{
    // define variables
    
    int idnum[SIZE];
    double rate[SIZE], hours[SIZE], pay[SIZE];
    // read in data for any number of employees
    // and keep a count in numemps
    int numemps=0;
    double total;
    
    numemps = readinData(idnum, hours, rate);
    cout << "You entered " << numemps << " employees." << endl;
    cout << "Hours:";
    displayData(hours, numemps);
    cout << "Rate: ";
    displayData(rate, numemps);
    
    calculatePay(hours, rate, pay, numemps);
    cout << "Pay:   ";
    displayData(pay, numemps);
    double maxhr = findMax(hours, numemps);
    cout << "Maximum number of hours worked is: " << maxhr << endl;
    // calculateTotal of pay array: LAB assignment
    // display total in main
    
    total = addPay(pay, numemps);
    
    cout << "The total pay is: " << total << endl;
    
    
    
    return 0;
}

// read data from keyboard
int readinData(int id[], double hours[], double rate[])
{
    int n=0; // number of elts read in
    cout << "Enter id number, -1 to exit: ";
    cin >> id[n]; // reads in loc 0
    
    while (id[n] != -1) {
        // process previous employee
        cout << "Enter employee #" << id[n]
        << " hours worked and rate of pay: ";
        cin >> hours[n] >> rate[n];
        n++;
        // read next employee
        cout << "Enter id number, -1 to exit: ";
        cin >> id[n];
    }
    return n;
}


// this function finds the max number in an array h
double findMax(double h[], int n)
{
    double maxHours=h[0];
    
    for (int i=1; i<n; i++)
        if (maxHours < h[i]) {
            maxHours = h[i];
        }
    return maxHours;
}


// this function accepts an array with n elts.
// It displays the n elts to the screen
void displayData(double arr[], int n)
{
    //cout << "You entered " << n << " elements. " << endl;
    //cout << "Here is the array: " << endl;
    for (int i=0; i<n; i++)
        cout << setw(8) << fixed << setprecision(1) << arr[i];
    cout << endl;
}

// this function fills up the pay array
void calculatePay(double arr1[], double arr2[], double ans[], int n)
{
    for (int i=0; i<n; i++)
        ans[i]=arr1[i]*arr2[i];
}

double addPay (double pay[], int n)
{
    double sum;
    for (int i=0; i<n; i++){
        sum += pay[i];
    }
    
    return sum;
}




