/*
 Write a function that accepts a double which represents a temperature in degree celcius. The function should convert the parameter into degrees faranheit and return that value.
 */

#include <iostream>
using namespace std;

double convert(double celc){
    double faran;
    faran = (9.0/5)*celc+32;
    return faran;
}

int main (){
    double celc_orig, faran;
    
    for (celc_orig = 36; celc_orig <= 42; celc_orig++){
        faran = convert(celc_orig);
        cout << celc_orig << " degrees celcius in faranheit is: " << faran << endl;
    }
    return 0;
}



/*
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
*/

/*
 double celc;
 //prompt
 cout << "Please enter a degrees celcius: ";
 cin >> celc;
 double faran;
 faran = (9.0/5)*celc+32;
 cout << celc << " degrees C equals " << faran << " degrees F." << endl;
 */