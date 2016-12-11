/*
 Assignment 4
 Author: Johanny Mateo
 Date: Thursday, October 6, 2016
 Description: Calculating the balance of a savings account
 
 At the beginning, ask the user for 3 pieces of data: (1) starting balance; (2) monthly interest rate; (3) number of months passed since the account was established.
 Loop for each month, performing the following: (1) Ask the user for the amount deposited into the account during the month, add this to the account balance. (2) Ask the user for the amount withdrawn during the month, subtract this amount for the balance. (3) Multiply the monthly interest by the balance and add this to the balance.
 After the last iteration, your program should display the following: (1) Total amount of deposits; (2) total amount of withdraws; (3) total interest earned.
 Output to the screen and an output file.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    double  bal,
            monthlyInterestRate,
            interest,
            deposit,
            withdraw,
            runningDeposit = 0,
            runningWithdraw = 0,
            runningInterest = 0;
    
    int month = 1,
        acctEst;
    
    ifstream inputFile;
    inputFile.open ("/Users/Johanny/Google\ Drive/C++/Homework\ Assignments/Assignment\ 4/Assignment\ 4/Assignment\ 4\ Input\ File.txt");
    
    if (!inputFile){
        
        cout << "Assignment 4 Input File.txt could not be opened.\n\n";
        exit(1);
    }
    
    inputFile >> bal;
    
    inputFile >> monthlyInterestRate;
    
    inputFile >> acctEst;
    
    for (month; month <= acctEst; month++) {
        
        inputFile >> deposit;
        
        //deposit running sum
        runningDeposit += deposit;
        
        inputFile >> withdraw;
        
        //withdraw running sum
        runningWithdraw += withdraw;
        
        //current balance after deposits and withdraws have been accounted for
        bal += (deposit - withdraw);
        
        //calculate interest for this month
        interest = (monthlyInterestRate*bal);
        
        //running sum of interest
        runningInterest += interest;
        
        //current balance after monthly interest rate is accounted for
        bal += interest;
    }
    
    cout    << "Total amount of deposits: $" << runningDeposit << endl
            << "Total amount of withdraws: $" << runningWithdraw << endl
            << "Total interest earned: $" << runningInterest << endl << endl;
    
    ofstream outputFile;
    outputFile.open ("/Users/Johanny/Google\ Drive/C++/Homework\ Assignments/Assignment\ 4/Assignment\ 4/Assignment\ 4\ Output\ File.txt");
    
    outputFile  << "Total amount of deposits: $" << runningDeposit << endl
                << "Total amount of withdraws: $" << runningWithdraw << endl
                << "Total interest earned: $" << runningInterest << endl;
    
    outputFile.close();
    inputFile.close();
    
    return 0;
}
