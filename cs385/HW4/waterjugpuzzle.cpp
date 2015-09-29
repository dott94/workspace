/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : David Ott
 * Date        : 9/23/2014
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens honor system
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int capacityA;//variables representing my jug capacities and the intended capacity
int capacityB;
int capacityC;
int goalA;
int goalB;
int goalC;
queue<vector<vector<int> > > stack;// queue used to store jugs

vector<vector<int> > copyPath(vector<vector<int> > path) { //vector of vector of ints to store the path of water moved
    vector<vector<int> > newPath(path.begin(), path.end());
    return newPath;
}

void complete(vector<vector<int> > path) { //method used to show if process is complete

    vector<int> initialState = path.front();
    cout << "Initial state. (" << initialState[0] << ", " << initialState[1]
            << ", " << initialState[2] << ")" << endl;
    for (vector<vector<int> >::iterator it = ++path.begin(); it != path.end();//iterating through path
            ++it) {

        cout << "Pour " << (*it)[3] << " gallon" << ((*it)[3] > 1 ? "s" : "")
                << " from " << (char) (*it)[4] << " to " << (char) (*it)[5]
                << ". (" << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2]
                << ")" << endl;
    }
    exit(0);
}
void print(vector<vector<int> > path) {//method used to print the path by iterating through the vector of path vactors

    vector<int> initialState = path.front();
    cout << "Initial state. (" << initialState[0] << ", " << initialState[1]
            << ", " << initialState[2] << ")" << endl;
    for (vector<vector<int> >::iterator it = ++path.begin(); it != path.end();
            ++it) {

        cout << "Pour " << (*it)[3] << " gallon" << ((*it)[3] > 1 ? "s" : "")
                << " from " << (char) (*it)[4] << " to " << (char) (*it)[5]
                << ". (" << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2]
                << ")" << endl;
    }

}
bool isStateRepeat(vector<vector<int> > path, vector<int> state) {//boolean used to show if state is repeated in path

    for (vector<vector<int> >::iterator it = path.begin(); it != path.end();
            ++it) {
        if (state[0] == (*it)[0] && state[1] == (*it)[1]
                && state[2] == (*it)[2]) {
            return true;
        }

    }
    return false;

}

void process() {//method used to exchange water values betweek jugs
    if (stack.empty()) {
        cout << "No solution." << endl;// no solution test case
        exit(0);
    }
    vector<vector<int> > currentPath = stack.front();

    stack.pop();
    vector<int> lastMove = currentPath.back();
    int currentA = lastMove[0];
    int currentB = lastMove[1];
    int currentC = lastMove[2];

    if (currentA == goalA && currentB == goalB && currentC == goalC) {
        complete(currentPath);
    }

    if (currentC != 0 && capacityA > currentA) {// water from C to A
        int water2move = min(currentC, capacityA - currentA);
        int newA = currentA + water2move;
        int newC = currentC - water2move;
        vector<int> newState;
        newState.push_back(newA);//pushing values on the queue
        newState.push_back(currentB);
        newState.push_back(newC);
        newState.push_back(water2move);
        newState.push_back('C');
        newState.push_back('A');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }

    }
    if (currentB != 0 && capacityA > currentA) {// Water from B to A

        int water2move = min(currentB, capacityA - currentA);
        int newA = currentA + water2move;
        int newB = currentB - water2move;
        vector<int> newState;
        newState.push_back(newA);
        newState.push_back(newB);
        newState.push_back(currentC);
        newState.push_back(water2move);
        newState.push_back('B');
        newState.push_back('A');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }

    }
    if (currentC != 0 && capacityB > currentB) {// water from C to B
        int water2move = min(currentC, capacityB - currentB);
        int newB = currentB + water2move;
        int newC = currentC - water2move;
        vector<int> newState;
        newState.push_back(currentA);
        newState.push_back(newB);
        newState.push_back(newC);
        newState.push_back(water2move);
        newState.push_back('C');
        newState.push_back('B');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }
    }
    if (currentA != 0 && capacityB > currentB) {// water from A to B
        int water2move = min(currentA, capacityB - currentB);
        int newA = currentA - water2move;
        int newB = currentB + water2move;
        vector<int> newState;
        newState.push_back(newA);
        newState.push_back(newB);
        newState.push_back(currentC);
        newState.push_back(water2move);
        newState.push_back('A');
        newState.push_back('B');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }
    }
    if (currentB != 0 && capacityC > currentC) {// Water from B to C
        int water2move = min(currentB, capacityC - currentC);
        int newB = currentB - water2move;
        int newC = currentC + water2move;
        vector<int> newState;
        newState.push_back(currentA);
        newState.push_back(newB);
        newState.push_back(newC);
        newState.push_back(water2move);
        newState.push_back('B');
        newState.push_back('C');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }
    }
    if (currentA != 0 && capacityC > currentC) {// A to C
        int water2move = min(currentA, capacityC - currentC);
        int newA = currentA - water2move;
        int newC = currentC + water2move;
        vector<int> newState;
        newState.push_back(newA);
        newState.push_back(currentB);
        newState.push_back(newC);
        newState.push_back(water2move);
        newState.push_back('A');
        newState.push_back('C');
        if (!isStateRepeat(currentPath, newState)) {
            vector<vector<int> > newPath = copyPath(currentPath);
            newPath.push_back(newState);
            stack.push(newPath);
        }
    }
    process();
}

int main(int argc, char ** const argv) { //displays various errors of user inputs and runs process method

    if (argc == 7) {
        char * end;
        capacityA = strtol(argv[1], &end, 10);//strtol used to avoid getting ascii value in output
        if (*end || capacityA < 0) {
            cout << "Error: Invalid capacity '" << argv[1] << "' for jug A."
                    << endl;
            return 0;
        }

        capacityB = strtol(argv[2], &end, 10);
        if (*end || capacityB < 0) {
            cout << "Error: Invalid capacity '" << argv[2] << "' for jug B."
                    << endl;
            return 0;
        }

        capacityC = strtol(argv[3], &end, 10);
        if (*end || capacityC <= 0) {
            cout << "Error: Invalid capacity '" << argv[3] << "' for jug C."
                    << endl;
            return 0;
        }

        goalA = strtol(argv[4], &end, 10);
        if (*end || goalA < 0) {
            cout << "Error: Invalid goal '" << argv[4] << "' for jug A."
                    << endl;
            return 0;
        }

        goalB = strtol(argv[5], &end, 10);
        if (*end || goalB < 0) {
            cout << "Error: Invalid goal '" << argv[5] << "' for jug B."
                    << endl;
            return 0;
        }
        goalC = strtol(argv[6], &end, 10);
        if (*end || goalC < 0) {
            cout << "Error: Invalid goal '" << argv[6] << "' for jug C."
                    << endl;
            return 0;
        }
        if (goalA + goalB + goalC != capacityC) {
            cout
                    << "Error: Total gallons in goal state must be equal to the capacity of jug C."
                    << endl;
            return 0;
        }

        vector<int> initialState;
        vector<vector<int> > initialPath;
        initialState.push_back(0);
        initialState.push_back(0);
        initialState.push_back(capacityC);
        initialPath.push_back(initialState);
        stack.push(initialPath);
        process();

    } else {//final error printout
        cout
                << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
                << endl;
    }


}
