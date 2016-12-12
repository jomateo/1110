//Johanny Mateo
//December 5, 2016
//CISC 1110
//Assignment 7

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>      //setw() function is called to organize output
using namespace std;

bool isvaliddna (string);               //is it valid?
void print_occurs (string, string);     //how many times does the motif occur

int main ()
{
    //line holds the current line while reading in
    string dna, motif, filename, line;
    
    ifstream inputFile;
    cout << "Please enter the input filename: ";
    //shortinput.txt	(valid DNA, no N)
    //shortinput2.txt	(valid DNA, has N)
    //shortinput3.txt	(invalid DNA)
    getline (cin, filename);
    inputFile.open(filename.c_str());
    cout << endl;
    
    if (!inputFile)
    {
        cout << "Input file could not be opened.\n\n";
        exit(1);
    }
    
    while (getline(inputFile, line))    //run this loop to get each line,
        dna += line;                    //and concatenate it to the object dna
    
    cout    << "Original DNA Sequence:\n" << dna << endl;
    
    cout    << "\nEnter a motif. A valid motif contains the letters "
            << "A, C, G, T, N. If you enter a valid motif, I will tell you "
            << "How many times it occurs in the DNA sequence, and at which "
            << "positions: ";
    cin     >> motif;
    cout    << endl;
    
    if (isvaliddna(dna) && isvaliddna(motif))
        print_occurs(dna, motif);
    
    else
        cout << "Either the DNA sequence or the motif is invalid.\n";
    
    cout << endl;
    inputFile.close();
    return 0;
}

bool isvaliddna (string test)
{
    //test.length() is the size of the entire string array
    for (int i = 0; i < test.length(); i++)
        if (test[i] != 'A' && test[i] != 'C' && test[i] != 'G' &&
            test[i] != 'T' && test[i] != 'N')
                return false;
    
    return true;
}

void print_occurs (string original, string pattern)
{
    
    int numocc = 0;     //counter for number of occurences
    
    //create an array to hold the position of the pattern. array size has to be
    //the length of DNA.
    unsigned long position[original.length()];
    
    //index is the index for the locations of the postion array
    int index = 0;
    
    size_t pos = original.find(pattern);        //find position of 1st pattern
    
    while (pos != string::npos)     //if atleast 1 pattern is present
    {
        numocc++;                   //increase the number of occurrences
        position[index] = pos;      //add its position to the postition array
        index++;                    //go to the next index in the position array
        pos = original.find(pattern, pos+1);//continue searching
    }
    
    if (numocc != 0)                //if the pattern appears at least once
    {
        cout    << "The number of times this motif occurs "
                << "in the DNA sequence is: " << numocc
                << ". It occurs at positions:" << endl;
        
        /*iterate through the position array, and print its contents
         (the positon in the DNA sequence in which the motif appears
         numocc is the number of elements in the array*/
        for (int i = 0; i < numocc; i++)
            /*there are about 5000-6000 possible positions, there's 4 characters
             in the max possible location, setw to 5 to have at least one space
             in between two intergers and a neat output*/
            cout <<setw(5) << position[i];
        
        cout << endl;
    }
    
    else        //if numocc == 0, the pattern is not in the original sequence
        cout << "This motif does not occur in this DNA sequence.\n";
    
    return;
}
