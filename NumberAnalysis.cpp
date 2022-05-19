/*
Student Name: Arianna Bikombe
Date: April 15, 2021
Course: CSCI175N
Lab Assignment: Lab09-01-NumberAnalysis
Project Name: Number Analysis
File Name: Lab09-01-NumberAnalysis.cpp
Description: Performs operations on numbers from the text file numbers.txt.
Limitations: Doesn't do very much.
Credits: Not Applicable
 */

#include <iostream>
#include <fstream>
using namespace std;

// Global constant for the array size
const int ARRAY_SIZE = 12;

// Function prototypes
void readNumbers(ifstream&, int[], int);
int getLowest(int[], int);
int getHighest(int[], int);
double getSum(int[], int);
double getAverage(int[], int, double);
void myName();

int main(double sum)
{

    myName();

    // Array to hold the numbers
    int numbers[ARRAY_SIZE];
    
    // file read open
    ifstream infile;
    infile.open("numbers.txt");

    // Test for errors.
    if (!infile) {
        cout << "Error opening the file.\n\n";

        system("pause");

        return 0;
    }

    // Read the numbers into the array.
    readNumbers(infile, numbers, ARRAY_SIZE);
    
    infile.close(); // file close
                    
    // Display data about the numbers.
    cout << "The highest value is ";
    cout << getHighest(numbers, ARRAY_SIZE) << endl;

    cout << "The lowest value is ";
    cout << getLowest(numbers, ARRAY_SIZE) << endl;

    cout << "The sum of the numbers is ";
    cout << getSum(numbers, ARRAY_SIZE) << endl;

    cout << "The average of the numbers is ";
    cout << getAverage(numbers, ARRAY_SIZE, sum) << endl << endl;

    system("pause");

    return 0;

}

// ********************************************************
// The getAverage function calculates and returns the     *
// average of the values stored in the array.             *
// ********************************************************

double getAverage(int numbers[], int ARRAY_SIZE, double sum) {

    // Calculate average
    sum = getSum(numbers, ARRAY_SIZE);
    double average = sum / ARRAY_SIZE;

    return average;

}

// ********************************************************
// The getHighest function finds the highest value in the *
// array and returns that value. The size parameter is    *
// the number of elements in the array.                   *
// ********************************************************

int getHighest(int numbers[], int ARRAY_SIZE) {

    // Variables
    int count, highest;
    highest = numbers[0];

    // Find highest
    for (count = 1; count < ARRAY_SIZE; count++) {
        if (numbers[count] > highest)
            highest = numbers[count];
    }

    return highest;

}

// ********************************************************
// The getLowest function finds the lowest value in the   *
// array and returns that value. The size parameter is    *
// the number of elements in the array.                   *
// ********************************************************

int getLowest(int numbers[], int ARRAY_SIZE) {

    // Variables
    int count, lowest;
    lowest = numbers[0];

    // Find lowest
    for (count = 1; count < ARRAY_SIZE; count++) {
        if (numbers[count] < lowest)
            lowest = numbers[count];
    }

    return lowest;

}

// ********************************************************
// The getSum function calculates and returns the sum of  *
// the values stored in the array.                        *
// ********************************************************

double getSum(int numbers[], int ARRAY_SIZE) {

    // Variables
    int count;
    double sum = 0;

    // Loop to calculate sum
    for (count = 0; count < ARRAY_SIZE; count++)
        sum += numbers[count];

    return sum;

}

//*************************************************
// The myName function outputs my name, course, & *
// Program #, and a blank line as typical for all *
// programs.                                      *
//*************************************************

void myName() {

    // Print out your name and course
    cout << "Arianna Bikombe\n";
    cout << "CSCI175N\n";
    cout << "Lab09-01-NumberAnalysis\n" << endl;

}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************

void readNumbers(ifstream& infile, int numbers[], int ARRAY_SIZE) {

    // Loop to read file
    for (int i = 0; i < ARRAY_SIZE; i++) {
        infile >> numbers[i];
    }

}

/*

test 1

Arianna Bikombe
CSCI175N
Lab09-01-NumberAnalysis

The highest value is 89
The lowest value is 8
The sum of the numbers is 520
The average of the numbers is 43.3333

Press any key to continue . . .

*/

/*

test 2

Arianna Bikombe
CSCI175N
Lab09-01-NumberAnalysis

Error opening the file.

Press any key to continue . . .

*/