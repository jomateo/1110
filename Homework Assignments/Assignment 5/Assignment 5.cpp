/*
 Johanny Mateo
 CISC 1011
 Assignment 5
 October 24, 2016
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//prototypes
void    introduction();
bool    validate(int);
double  average(double, double, double, double, double);

int main()
{
    int set = 0,        //holds the current set number
        setInvalid = 0, //holds the number of invalid sets in total
        numValid,       //holds the number of valid scores in the current set
        setValid = 0;   //holds the number of valid sets in total
    
    //holds the value of the scores 1-5 in each set, and their average
    double score1, score2, score3, score4, score5, avg;
    
    //opens the input file
    ifstream inputFile;
    inputFile.open ("/Users/Johanny/Google\ Drive/C++/Homework\ Assignments/Assignment\ 5/Assignment\ 5/Assignment\ 5\ Input\ File.txt");
    
    //opens the output file
    ofstream outputFile;
    outputFile.open ("/Users/Johanny/Google\ Drive/C++/Homework\ Assignments/Assignment\ 5/Assignment\ 5/Assignment\ 5\ Output\ File.txt");
    
    //print this if the input file cannot be opened, then exit.
    if (!inputFile){
        cout << "Assignment 5 Input File.txt could not be opened.\n\n";
        exit(1);
    }
    
    introduction();	// calls the function introduction which prints what the program does
    
    /*
     The program will read in score1, score2, score3, score4, score5 from the input file. This represents one set of 5 scores.
     Everytime it inputs these 5 scores, it knows its a new set, the number of valid numbers in this set is reset to 0 (numValid), and the set counter increases by 1, and prints that it is processing such set.
     There are 5 if statements, they each call the function validate to check if score1, score2, score3, score4, and score5 are true or false. If a score number is true,the numValid counter increases.
     After all 5 numbers are tested, the program checks if numValid is equal to 5. If it is, this means that all 5 numbers in this set are valid. It then increases the counter of number of valid sets so far. After that, it calls the average function and sends score1, score2, score3, score4, and score5. The average of these scores are calculated, returned and the average is printed and outputted.
     If the numValid is not equal to 5, this means that not all scores in the set were valid, and a message prints stating that this set is invalid and the average will not be determined, and the counter of invalid sets is increased by 1.
     The while loop then starts up again and reads in the next 5 numbers from the input file.
     Once there are no more numbers to read in, the while loop doesn't run and the number of processed, invalid, and valid sets are printed and outputted.
     */
    
    //read in 5 scores at a time (a complete set) and run this while loop while there are still scores to be read in
    while (inputFile >> score1, inputFile >> score2, inputFile >> score3,
           inputFile >> score4, inputFile >> score5) {
        numValid = 0;   //reset the number of valid numbers in the new set to 0
        set++;  //increases the set number
        
        cout        << "Now processing set number " << set << ":\n";
        outputFile  << "Now processing set number " << set << ":\n";
        
        //5 if statements to call the function validate and send score numbers 1 - 5, determine if it is valid or not, and increase the counters
        if (validate(score1))
            numValid++;
        
        if (validate(score2))
            numValid++;
        
        if (validate(score3))
            numValid++;
        
        if (validate(score4))
            numValid++;
        
        if (validate(score5))
            numValid++;
        
        //if numValid == 5, this means that all 5 numbers in the current set are valid. We can calculate the average
        if (numValid == 5){
            setValid++; //increase the number of valid sets so far.
            
            //calls the average function to calculate the average and assigns the average to avg
            avg = average(score1, score2, score3, score4, score5);
            
            cout        << "Set " << set << " is valid. Its average is: "
                        << avg << endl << endl;
            outputFile  << "Set " << set << " is valid. Its average is: "
                        << avg << endl << endl;
            
        }
        
        //if numValid != 5, this means that not all numbers are valid
        else{
            cout        << "Set " << set << " contains an invalid test score "
                        << "and its average will not be computed.\n\n";
            outputFile  << "Set " << set << " contains an invalid test score "
                        << "and its average will not be computed.\n\n";
            
            setInvalid++;   //increase the number of invalid sets so far
        }
    }
    
    cout    << "There were " << set << " sets processed.\n"
            << "There were " << setInvalid << " sets of invalid test scores.\n"
            << "There were " << setValid << " sets of valid test scores.\n\n";
    
    outputFile  << "There were " << set << " sets processed.\n"
                << "There were " << setInvalid << " sets of invalid test scores.\n"
                << "There were " << setValid << " sets of valid test scores.\n\n";
    
    inputFile.close();
    outputFile.close();
    return 0;
}

// this function prints a message saying what the program does
void introduction() {
    cout << "This program reads in 5 test scores each from 23 students. It decides if each student's test scores are valid or not. A valid test score is in the range from 0 - 100. If the test score is invalid, the program will print it and state why. It does this for each of the student's test scores, and then prints out if the set is valid or not. If the set contains all valid scores, it computes the student's average score. It does this for all the students, at the end, a message will print showing how many sets were valid, invalid, and how many sets were processed.\n\n";
    return;
}

//this function accepts a score, then checks if it is between 0 - 100, or less than 0, or greater than 100, then returns if the scores are valid or invalid
bool validate (int score)
{
    if (score >= 0 && score <= 100){
        return true;
    }
    
    else if (score < 0){
        cout << "The test score " << score << " is invalid because it is less than 0.\n";
        return false;
    }
    
    else {
        cout << "The test score " << score << " is invalid because it is greater than 100.\n";
        return false;
    }
}

//this function accepts score1, score2, score3, score4, and score5 as doubles, calculates their avergae, and returns their average back to main
double average (double score1, double score2, double score3, double score4, double score5)
{
    double avg;
    avg = (score1 + score2 + score3 + score4 + score5)/5;
    return avg;
}
