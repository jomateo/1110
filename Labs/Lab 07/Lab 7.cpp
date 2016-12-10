#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
     cout << "Celcius" << setw(10) << "Faranheit" << endl
          << "___________________" << endl;
     
     for (double celc = 36; celc <= 42; celc++){
          double faran;
          faran = (9.0/5)*celc+32;
          cout << setw(2) << celc << setw(10) << faran << endl;
     }
     return 0;
}
/*
 Modify faranheit an dcelcius program to use a for loop. Print a table of the celcius and farenheit values going from 36 degrees celcius to 42 degrees celicius.
 
#include <iostream>
#include <string>
using namespace std;

int main()
{
     double celc;
     //prompt
     cout << "Please enter a degrees celcius: ";
     cin >> celc;
     double faran;
     faran = (9.0/5)*celc+32;
     cout << celc << " degrees C equals " << faran << " degrees F." << endl;
     
     int num1, num2;
     cout << "Enter two integers: ";
     cin >> num1 >> num2;
     cout << "You entered " << num1 << " and " << num2 << endl;
     return 0;
}
*/