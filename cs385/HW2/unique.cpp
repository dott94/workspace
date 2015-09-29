/******************************************************************************
 * Name        : unique.cpp
 * Author      : David Ott
 * Date        : 9/15/2014
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I Pledge my honor that I have abided by the stevens honor system
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.

    //Checks to see if all elements in a string are lower case
    char a;
    unsigned int j;
    for (j = 0; j < s.length(); j++) {
        //looping through the string
        a = s.at(j);
        if (a > 122 || a < 97) {
            // checking the ASCII value
            return false;
        }
    }return true; // returns true if not in the ASCII range given in the if statement
}



bool all_unique_letters(string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.

    //returns true if there are no duplicates in the string
    int lowerCase = 0;
    while (s != "") {
        //loops through if the string is not empty
        if ((lowerCase & (1 << ((int) s.at(0) - 97))) != 0) {
            //using bitwise and lowercase to check uniqueness
            return false;
        } else {
            lowerCase = lowerCase ^ (1 << ((int) s.at(0) - 97));
        }
        s = s.substr(1, s.length() - 1);
    }return true;
}



int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <string>";
        return 1;
    }
    string user = argv[1];
    //converts the users input into a readable string
    if (!all_unique_letters(user)) {
        cout << "Duplicate letters found.";
        //error because user input duplicates
    } else if (!is_all_lowercase(user)) {
        cerr << "Error: String must contain only lowercase letters.";
        //error message because user input string with uppercase
    } else {
        cout << "All letters are unique.";
        //the user input a proper string
    }return 1;
}
