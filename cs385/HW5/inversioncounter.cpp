/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : David Ott
 * Version     : 1.0
 * Date        : 10/21/2014
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the stevens honor system
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string.h>
using namespace std;

static unsigned long mergesort(int array[], int scratch[], int low, int high);

unsigned long count_inversions_slow(int array[], int length) { //slow way (theta(n^2)) to count if element j is less than i
    unsigned long count = 0;
    for (int i = 0; i < length; i++) { //iterating through i
        for (int j = (i + 1); j < length; j++) { //iterating through j
            if (array[j] < array[i]) {
                count++;
            }
        }
    }
    return count;
}

unsigned long count_inversions_fast(int array[], int length) { //Uses merge sort to count inversions
    int *scratch = (int *) malloc(length * sizeof(int)); //allocating greater bit size
    if (scratch != NULL) {
        unsigned long count = mergesort(array, scratch, 0, length - 1);

        free(scratch); //freeing up scratch's memory
        return count;
    } else {
        return 0;
    }
}

unsigned long merge(int array[], int temp[], int left, int middle, int right) {
    unsigned long invCount = 0;
    int i, j, k;
    //i, j, k represent the different parts of the array
    i = left;
    j = middle;
    k = left;
    while ((i <= middle - 1) && (j <= right)) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];

            invCount = invCount + (middle - i);
        }
    }
    while (i <= middle - 1) //copies any leftover elements from left into temp
        temp[k++] = array[i++];
    while (j <= right) //copies any leftover elements from right into temp
        temp[k++] = array[j++];

    for (i = left; i <= right; i++) //takes merged elements and puts them back into array
        array[i] = temp[i];

    return invCount;
}
static unsigned long mergesort(int array[], int scratch[], int low, int high) {

    int mid = 0;
    unsigned long invCount = 0;
    if (high > low) {//split the array into two parts
        mid = (high + low) / 2;

        invCount = mergesort(array, scratch, low, mid);//sum of the number of inversions(low)
        invCount += mergesort(array, scratch, mid + 1, high);//(high)
        invCount += merge(array, scratch, low, mid + 1, high);//uses merge to combine the two
    }
    return invCount;

}

int main(int argc, char *argv[]) {
    bool slow = false;
    if (argc > 1) {//error checking
        if (argc > 2) {
            cout << "Usage: ./inversioncounter [slow]" << endl;
            exit(0);
        }
        if (std::string(argv[1]) != "slow") {//converting to string
            cout << "Error: Unrecognized option '" << argv[1] << "'." << endl;
            exit(0);
        } else {
            slow = true;
        }

    }
    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                            << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    int* array = &values[0];//points to the values
    int length = values.size();//size of the values
    if (length == 0) {//error check for no values
        cout << "Error: Sequence of integers not received." << endl;
        exit(0);
    }
    unsigned long count = 0;
    if (slow) {//uses bool slow
        count = count_inversions_slow(array, length);
    } else {
        count = count_inversions_fast(array, length);
    }
    cout << "Number of inversions: " << count << endl;

    return 0;
}
