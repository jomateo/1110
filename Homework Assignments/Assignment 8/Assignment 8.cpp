//Johanny Mateo
//Assignment 8
//December 21,2016

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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

const int SIZE = 10;

//reads in phone data from file. Accepts array and nubmer of elements filled
void readdata (Phone [], int);
//displays phone data. Accepts array and number of elements filled
//sorts by productnum in descending order (selection)
void printdb (Phone [], int);
//finds phone name
int findphonename (Phone [], int, string);
//prints phone info
void printPhone (Phone [], int);
//search for price range and sort in ascending order (bubble)
void searchPrice (Phone [], int);

int main ()
{
    Phone phoneInfo [SIZE];
    int elts = 10,  //offering a choice of 10 different phones
        pos;        //position of item found
    string search;
    
    inputFile.open("Assignment 8 Input File.txt");
    
    if (!inputFile)
    {
        cout << "Input file could not be opened.\n";
        exit (1);
    }
    
    readdata(phoneInfo, elts);
    printdb(phoneInfo, elts);
    cout << endl;
    
    cout << "Which phone do you want to search for? ";
    cin >> search;
    pos = findphonename(phoneInfo, elts, search);
    while (pos == -1)
    {
        cout << "Phone name not found. Try again: ";
        cin >> search;
        pos = findphonename(phoneInfo, elts, search);
    }
    printPhone(phoneInfo, pos);
    
    cout << endl;
    searchPrice (phoneInfo, elts);
    
    inputFile.close();
    return 0;
}

void readdata (Phone arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        inputFile   >> arr[i].productnumber >> arr[i].price >> arr[i].quantity
                    >> arr[i].name.companyName >> arr[i].name.phoneName;
    }
    return;
}

 void printdb (Phone arr[], int n)
{
    int temp;
    
    //sort phone info by product number in descending order (selection sort)
    for (int i = 0; i<n-1; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            if (arr[i].productnumber < arr[j].productnumber)
            {
                temp = arr[j].productnumber;
                arr[j].productnumber = arr[i].productnumber;
                arr[i].productnumber = temp;
            }
        }
    }
    
    //print out phone info
    for (int i = 0; i<n; i++)
    {
        cout    << fixed << setprecision(2) << setw(5) << arr[i].productnumber
                << setw(8) << arr[i].price << setw(6) << arr[i].quantity
                << setw(8) << arr[i].name.companyName << setw(8)
                << arr[i].name.phoneName << endl;
    }
    return;
}

int findphonename (Phone arr[], int n, string find)
{
    for (int i = 0; i < n; i++)
        if (find == arr[i].name.phoneName)
        {
            cout << "Phone found at location " << i << ":\n";
            return i;
        }
    return -1;
}

void printPhone (Phone arr[], int loc)
{
    cout    << fixed << setprecision(2) << setw(5) << arr[loc].productnumber
            << setw(8) << arr[loc].price << setw(6) << arr[loc].quantity
            << setw(8) << arr[loc].name.companyName << setw(8)
            << arr[loc].name.phoneName << endl;
    return;
}

void searchPrice (Phone arr[], int n)
{
    double min, max, temp;
    bool swapped;
    int passes=0;
    
    //sort phones by price in ascending order (bubble sort)
    do
    {
        passes++;
        swapped = false;
        for (int i = 0; i<n-passes; i++)
        {
            if (arr[i].price > arr[i+1].price)
            {
                temp = arr[i].price;
                arr[i].price = arr[i+1].price;
                arr[i+1].price = temp;
                swapped = true;
            }
        }
    } while (swapped);
    
    cout << "Enter minimum price to search for: ";
    cin >> min;
    cout << "Enter maximum price to search for: ";
    cin >> max;
    //print out phones that are in between those two prices, inclusive
    for (int i = 0; i<n; i++)
    {
        if (arr[i].price >= min && arr[i].price <= max)
        {
            cout    << fixed << setprecision(2) << setw(5)
                    << arr[i].productnumber << setw(8) << arr[i].price
                    << setw(6) << arr[i].quantity << setw(8)
                    << arr[i].name.companyName << setw(8)
                    << arr[i].name.phoneName << endl;
        }
    }
    return;
}
