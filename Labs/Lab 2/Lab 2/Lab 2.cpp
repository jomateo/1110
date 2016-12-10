/*
 Lab Assignment 2
 Author: Johanny Mateo
 Date: Wednesday, September 7, 2016
 Description: Declare variables for course numbers of courses that you
 are taking.
 */

/*
 Declare variables for course numbers of courses that you
 are taking.
 For example:
 int course1;
 Give values to each course.
 Then, print the course list, each course number on its own
 line.
 Sample OUTPUT:
 I am taking the following courses this semester:
 1110
 3220
 1050
 */

#include <iostream>
using namespace std;

int main()

{
    int intro_to_programming = 1110;
    int precalculus = 1011;
    int comp_app = 1050;
    int bus_mang = 3200;
    int self_def = 1105;

    cout << "I am taking the following courses this semester:" << endl;
    cout << intro_to_programming << endl;
    cout << precalculus << endl;
    cout << comp_app << endl;
    cout << bus_mang << endl;
	cout << self_def << endl;

    return 0;
}

/*
 Memory Trace:
 intro_to_programming
 1110

 precalculus
 1011

 comp_app
 1050

 bus_mang
 3200

 self_def
 1105
 */