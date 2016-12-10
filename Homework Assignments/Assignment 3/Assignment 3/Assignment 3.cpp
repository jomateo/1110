/*
 Assignment 3
 Author: Johanny Mateo
 Date: Wednesday, September 28, 2016
 Description: Hi-Lo Game

 When playing begins, the program will come up with a number between 0 and 100, and the user will try to guess that number. Each time the user guesses, the program will tell the user whether the target number is higher or lower than the guess (but no further information is given). When the user eventually guesses the actual number, the program should let the user know, and also display the number of guesses that the user needed.
 To simulate a random guess, you should generate a random number using rand() from the <cstdlib> library. You should read about how to use rand, and how to seed the random number generator using the current time so that each time the program runs you get different results.
 OPTIONAL:
 Put a loop into the program so that the user can play as many times as he/she wants until the user is ready to quit.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

     //define random number, user's guess, and number of times they try to guess
     int randnum, guess, try_num;
     //play is initialized as 'Y' so 1st loop can initially run (while play is equal to Y || y)
     char play = 'Y';

     cout << "Hello, are you ready to play the hi-lo game? I am thinking of a number, enter a guess, and I will tell you if it is too high, too low, or just right.\n";

     while (play == 'Y' || play == 'y') {
          cout << "\nI am thinking of a number between 0 and 100.\n";

          //initializes guess number to -1, that way the 2nd while loop can initially run (while (randnum != guess)) and there is no chance that the loop starts with a guess that is equal to the random number seeded by the computer (-1 is out of the range from 0-100).
          guess = -1;
          //resets number of tries to 0.
          try_num = 0;

          //seeds a random number based on the time
          srand(time(NULL));

          //rand 0 - 100
          randnum = rand() % 101;

          while (randnum != guess){
               //The user is about to try (again)
               try_num++;

               cout << "Enter a guess: ";
               cin >> guess;

               if (randnum < guess) {
                    cout << "Nope! My number is less than " << guess << "!\n";
               }
               else if (randnum > guess) {
                    cout << "Nope! My number is greater than " << guess << "!\n";
               }
               //use else if try_num == 1, so that it outputs "You won in 1 guess!" instead of "You won in 1 guesses!" (Correct grammar.)
               else if (try_num == 1){
                    cout << "You entered the correct number!\n"
                    << "You won in " << try_num << " guess!\n\n";
               }
               //It will output this if the user won after making 2 or more guesses.
               else {
                    cout << "You entered the correct number!\n"
                    << "You won in " << try_num << " guesses!\n\n";
               }
          }
          cout << "Do you want to play again? (Y/N): ";
          cin >> play;
     }

     return 0;
}

/*
 Memory Trace:
 randnum = is an int from 0 - 100 that is automatically seeded by the computer based on the time everytime the 1st while loop runs

 guess = is initialized as -1 every time the 1st while loop runs, then changes depending on the user's guess

 try_num = starts out as 0 everytime the 1st while loop runs, and goes up by 1 every time the user is about to make a guess

 play = starts out as 'Y' and changes depending on wether or not the user wants to continue playing. The 1st while loop will run as long as play == 'Y' or 'y'

 
 Handcheck:
 play =        'Y'; 'y'; 'Y'; 'n'
 
 guess =       -1; 50; 25; 10; 15; 20; 17; 18; 19
               -1; 50; 25; 15; 5; 10; 8; 9
               -1; 50; 75; 100; 85; 80; 76; 77; 78
 
 try_num =     0; 1; 2; 3; 4; 5; 6; 7; 8
               0; 1; 2; 3; 4; 5; 6; 7
               0; 1; 2; 3; 4; 5; 6; 7; 8
 
 randnum =     19; 9; 78
*/
