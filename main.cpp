/*
//  main.cpp
//  Finding Patterns
//
//  Created by Tomás González on 2016-10-27.
//  Copyright © 2016 Tomás González. All rights reserved.
//  This program finds the presence of patterns
//  (3 consecutive numbers minimum with the same beahviour)
//  Then print the patterns depending on the anwer true or false
*/


// First we declare all the functions and libraries included in our program
#include <iostream>
//#include <AppKit/AppKit.h> //To allow the kit to play sound in OSX
void announce ();
void instruction ();
bool findPatterns ();
void printPatterns ();
int getValues (int);
int intializeValues (int, int);
const int ARRAY_SIZE = 100;
int values[ARRAY_SIZE];
int numberOfPatterns;
int patternLength;
int patternStart;
int patternEnd;
int size;
using namespace std;


/*
 Here we are going to get the elements inside the array values and also get the current size of it
 
*/
void announce () {
    cout << "Welcome to Pattern Finder program  - CPSC1155 Lab 7" << endl;
}

void instruction () {
    cout << "Enter a group of integer values (minimum 3) to test if there is any pattern on them" << endl;
}

int getValues (int values[]) {
        do {
        cout << "How many values do you want? ";
        cin >> size;
        if ((size < 3) || (size > 100)) { //If the user enters a size under 3 numbers or bigger than 100
            //void NSBeep (void); //This will enable a Beep from default from the API
                cout << "ERROR: " << size << " is out of range! Please enter at least a size of 3 values so we can find a pattern (a pattern must have at least 3 consecutive elements under the same beahviour : ";
        } //While the size of the array is smaller than 3
    } while ((size < 3) || (size > 100));
   // Then we ask to enter the group of elements inside the array
    cout << "Enter up to " << size << " integer values ";
    for (int i = 0; i < size; i++){
        cout << "Enter value " << i << " :";
        cin >> values[i];
    }

       return size;
}


bool findPatterns(const int values[], int size, int patterns[]){
    //numberOfPatterns, patternStart, patternLength are values in patterns
    
    bool isPattern = false;   // at the start we don't know yet if there is a pattern
    numberOfPatterns = 0;     // we will have 0 patterns and if we found one we will add it to this as a counter
    
    for (int i = 0; i < size - 2; i++){ //Scan through all values in values
        int dif1 = values[i + 1] - values[i];
        int dif2 = values[i + 2] - values[i + 1]; //With this +1 and +2 we will still access to those indexes
        
        if (dif1 == dif2) { // if we have the same difference between indexes we find a pattern !
            if (!isPattern) { //we change the previous false statement to true since the pattern exist !
                numberOfPatterns++; // We keep track of the amount of patterns through a counter
                patternStart = i; // We also keep track when the pattern started
            }
            isPattern = true;
            patternEnd = i + 2;  // save possible end of pattern
            patternLength = patternEnd - patternStart + 1; // save pattern
        }
        else
            isPattern = false; // no patterns found at i, i + 1 and i + 2
    }
    int patterns[numberOfPatterns, patternStart, patternLength];
    return patterns;
}

void printPatterns(const int values[], const int patterns[]){



}

int main() {
    // insert code here...
    announce();
    instruction();
    int len = getValues (values);
    values = initializeValues[values, len];
    int patterns[ARRAY_SIZE];
    
    return 0;
}
