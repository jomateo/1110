//Johanny Mateo
//Assignment 8
//December 21,2016

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream inputFile;

class PhoneNames
{
public:
    string  companyName;
    string  phoneName;
};

class Phone
{
public:
    int         productnumber;  //stores unique identifying number
    double      price;
    int         quantity;       //number of available phones for sale
    PhoneNames  name;
    
};

const int SIZE = 100;

//reads in phone data from file. Accepts array and nubmer of elements filled.
void readdata (Phone &, int);

//displays phone data. Accepts array and number of elemnts filled
void printdb (Phone, int);

int main ()
{
    Phone phoneInfo [SIZE];
    int elts = 10;  //offering a choice of 10 different phones
    
    readdata (phoneInfo, elts);
    printdb(phoneInfo, elts);
    
    return 0;
}

void readdata (Phone arr, int n)
{
    inputFile.open("Assignment 8 Input File.txt");
    
    for (int i = 0; i < n; i++)
    {
        inputFile   >> arr.productnumber >> arr.price >> arr.quantity
                    >> arr.name.companyName >> arr.name.phoneName;
    }
    return;
}

 void printdb (Phone arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout    << arr.productnumber << ' ' << arr.price << ' ' << arr.quantity
                << ' ' << arr.name.companyName << ' ' << arr.name.phoneName
                << endl;
    }
    return;
}









