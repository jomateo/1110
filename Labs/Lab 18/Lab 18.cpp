// pgm36
// This is today's lab. We are going to practice programming
// with strings, including passing strings as parameters
// and returning strings from functions.
// 11/23/2016

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
int countOcc(string, string);
void erasepart(string &);
void replacepart(int, int, string, string &);
int main()
{
	int choice, begin, erase;
	string line, sub;
	ifstream infile
		("/Users/Johanny/Google Drive/C++/Labs/Lab 18/Lab 18/stringdata.txt");
	getline(infile, line);
	cout << "text is: " << endl << line << endl;
	// Write a program that reads in a text,
	// gives the user a menu to modify or search the text
	// as many times as the user wants to.
	// menu
	do {
		cout << "1. Search text for a pattern." << endl;
		cout << "2. Erase a part of the text." << endl;
		cout << "3. Replace a part of the text." << endl;
		cout << "4. Insert a string into the text." << endl;
		cout << "5. Exit" << endl;
		cout << "Enter choice:";
		cin >> choice;
		if (choice==1) {
			cout << "Enter string to search for: ";
			cin >> sub;
			cout << countOcc(line, sub) << " were found." << endl;
		}
		else if (choice==2) {
			erasepart(line);
		}
		else if (choice==3) {
			cout << "Enter the character position to begin replacement: ";
			cin >> begin;
			cout << "Enter how many characters to erase: ";
			cin >> erase;
			cout << "Enter text you want to insert: ";
			cin >> sub;
			replacepart(begin, erase, sub, line);
			
		}// do on your own
		
		else if (choice==4) ; // do on your own
		cout << "Text is currently: " << endl;
		cout << line << endl;
	} while (choice!=5);
	
	return 0;
}


// this function counts how many times a substring occurs
// in a bigger string
// the function accepts substring to search for, bigger string
// the function returns an int which is the count
// count how many times the pattern occurs in the text
int countOcc(string text, string pattern)
{
	size_t pos=text.find(pattern);
	int numocc=0;
	while(pos!=string::npos) {
		numocc++;
		pos=text.find(pattern,pos+1);
	}
	return numocc;
}

// function erasepart allows the user to erase part of
// the string parameter.
void erasepart(string &str)
{
	string sub;
	cout << "What substring do you want to erase? ";
	cin >> sub;
	size_t pos = str.find(sub, 0);
	if (pos!=string::npos) // found it!
		str.erase(pos, sub.length());
	else
		cout << sub << " not found in text." << endl;
	return;
}

//This function replaces part of the string with something else
void replacepart(int start, int remove, string replace, string &line){
	line.replace(start, remove, replace);
	cout << "The new text is: " << endl << line << endl;
	return;
}
