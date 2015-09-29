/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : David Ott
 * Date        : 9/23/2014
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens honor system
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

void get_ways_recursive(vector<vector<int> > & outPut, vector<int> soFar,
        int remaining) {//implementation of the possible ways to get to the top of the stairs using one two or three
    if (remaining >= 1) {
        vector<int> soFarCopy(soFar);
        soFarCopy.push_back(1);
        get_ways_recursive(outPut, soFarCopy, remaining - 1);//minus one step from the stair case
    }
    if (remaining >= 2) {
        vector<int> soFarCopy(soFar);
        soFarCopy.push_back(2);
        get_ways_recursive(outPut, soFarCopy, remaining - 2);//minus two steps from the stair case
    }
    if (remaining >= 3) {
        vector<int> soFarCopy(soFar);
        soFarCopy.push_back(3);
        get_ways_recursive(outPut, soFarCopy, remaining - 3);//minus three
    }
    if (remaining == 0 && soFar.size() != 0) {
        outPut.push_back(soFar);
    }
}

vector<vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.

    vector<vector<int> > outPut;
    vector<int> soFar;
    get_ways_recursive(outPut, soFar, num_stairs);//calling the previous method
    return outPut;
}
int getIntLength(int m){//returns the length of an integer string
    stringstream ss;
        ss << m;
        string numWaysString = ss.str();//setting the num to a string so we can use the .size method
        return numWaysString.size();
}
void display_ways(const vector<vector<int> > &ways) {//Displays the ways to climb stairs by iterating over the vector of vectors and printing each combination.
    int line = 0;
    int numWays = ways.size();
    int maxintlength = getIntLength(numWays);
    for (vector<vector<int> >::const_iterator it = ways.begin();//iterating through the vector of vectors
            it != ways.end(); ++it) {
        line++;
        int spacesNeeded = maxintlength - getIntLength(line);//finding the spaces needed
        for(int i = 0; i < spacesNeeded; i++){
            cout<< " ";
        }
        cout << line << ". [";

        for (vector<int>::const_iterator it2 = it->begin(); it2 != it->end();
                ++it2) {
            if (it2 != it->begin()) {
                cout << ", " << *it2;
            } else {
                cout << *it2;
            }

        }
        cout << "]" << endl;
    }

}
bool is_number(const string& s) {//boolean value to find out if if string isdigit
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
int main(int argc, char ** const argv) {//final display of the vector of vectors

    if (argc == 2) {
        int numStairs = atoi(argv[1]);
        if (numStairs <= 0 || !is_number(argv[1])) {//testing if input is a positive integer
            cout << "Error: Number of stairs must be a positive integer."
                    << endl;
        } else {

            vector<vector<int> > ways = get_ways(numStairs);
            int numWays = ways.size();
            cout << numWays << " way" << (numWays > 1 ? "s" : "")//easy way to avoid making a second cout for inputs == 1
                    << " to climb " << numStairs << " stair"
                    << (numWays > 1 ? "s." : ".") << endl;
            display_ways(ways);
        }
    } else {
        cout << "Usage: ./stairclimber <number of stairs>" << endl;//error message

    }

}
