/*
 Create a text file with some numbers in it. Write a C++ program that will read all of the numbers in the file, print them to the screen, and add them up, and print the sum to the screen.
 Time permitting: Send all output both to the screen and to an output file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
     ifstream data;
     ofstream output;
     
     data.open("/Users/Johanny/Google\ Drive/C++/Labs/Lab\ 8/Lab\ 8/data.txt");
     output.open("/Users/Johanny/Google\ Drive/C++/Labs/Lab\ 8/Lab\ 8/output.txt");
     
     if (!data){
          cout << "Could not open input file.";
          exit (1);
     }
     
     int num, sum=0;
     
     for (num; num<=10; num++){
          data >> num;
          cout << num << endl;
          output << num << endl;
          sum+=num;
     }
     cout << sum << endl;
     output << sum;
     
     return 0;
}