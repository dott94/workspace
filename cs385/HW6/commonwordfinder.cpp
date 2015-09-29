/*
 * readin.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: dott1
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "rbtree.h"

using namespace std;
string removePunct(string s) { // Permitting letters a - z, single quotes, and hyphens.
    string out = "";
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        char c = s[i];
        if ((c > 64 && c < 91) || (c > 96 && c < 123) || c == 45 || c == 39) { //removes

            out += tolower(c);
        }
    }
    return out;
}

int numDigits(int number) { //returns the number of digits
    int digits = 0;
    if (number < 0)
        digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}
bool lessthanfun(const Node<string, int> &i, const Node<string, int> &j) {
    if (i.kv_pair_.second == j.kv_pair_.second) {

        if (i.kv_pair_.first.compare(j.kv_pair_.first) < 0) {
            return true;
        } else {
            return false;
        }

    } else {
        return i.kv_pair_.second > j.kv_pair_.second;
    }
}
bool is_number(const string& s) { //boolean value to find out if if string isdigit
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, const char *argv[]) {
// Make sure the right number of command line arguments exist.
    if (!(argc == 3 || argc == 2)) {
        cerr << "Usage: " << argv[0] << " <filename> [limit]" << endl;
        return 1;
    }
// Create an ifstream object.
    ifstream input_file(argv[1]);
// If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[1] << "' for input."
                << endl;
        return 1;
    }

    if (argc == 3 && !is_number(argv[2])) {
        cerr << "Error: Invalid limit '" << argv[2] << "' received." << endl;
        return 1;
    }

    int limit;
    if (argc == 3) {
        limit = atoi(argv[2]);
    } else {
        limit = 10;
    }

    if (limit < 0) {
        cerr << "Error: Invalid limit '" << argv[2] << "' received." << endl;
        return 1;
    }

    RedBlackTree<string, int> *tree;
    tree = new RedBlackTree<string, int>();
// Add read errors to the list of exceptions the ifstream will handle.
    input_file.exceptions(ifstream::badbit);
    string line;
    unsigned int maxwordwidth = 0;

    try {

        // Use getline to read in a line.
        // See http://www.cplusplus.com/reference/string/string/getline/

        while (getline(input_file, line)) {
            string buf; // Have a buffer string
            stringstream ss(line); // Insert the string into a stream

            vector<string> tokens; // Create vector to hold our words

            while (ss >> buf) {
                tokens.push_back(buf);

                string nopunct = removePunct(buf);

                RedBlackTree<string, int>::iterator it = tree->find(nopunct);
                if (it == tree->end()) {
                    if (nopunct != "")
                        tree->insert(nopunct, 1);
                } else {
                    it->second++;
                }
            }

        }

        // Don't forget to close the file.
        input_file.close();

    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
    }

    vector<Node<string, int> > sorted;
    for (RedBlackTree<string, int>::iterator it = tree->begin();
            it != tree->end(); ++it) {
        Node<string, int> n(it->first, it->second);

        sorted.push_back(n);
    }

    sort(sorted.begin(), sorted.end(), lessthanfun); //loop through sorted from 0 to limit to determine the largest word size
    int wordnum = 1;
    for (vector<Node<string, int> >::iterator it = sorted.begin();
            it != sorted.end(); ++it) {

        if ((it->kv_pair_.first).size() > maxwordwidth) {
            maxwordwidth = (it->kv_pair_.first).size();
        }
        if (wordnum >= limit) {

            break;
        }
        wordnum++;
    }

    wordnum = 1;
    cout << "Total unique words: " << tree->size() << endl;
    int numwidth = numDigits(min((int) tree->size(), limit));
    for (vector<Node<string, int> >::iterator it = sorted.begin();
            it != sorted.end(); ++it) {

        string numstring = "";
        int thisnumwidth = numDigits(wordnum);
        for (int i = 0; i < numwidth - thisnumwidth; i++) {
            numstring += " ";
        }

        stringstream convert;
        convert << wordnum;
        numstring += convert.str();
        string wordoutput = it->kv_pair_.first;

        for (size_t i = 0; i < maxwordwidth - (it->kv_pair_.first).size() + 1;
                i++) {

            wordoutput += " ";
        }
        cout << numstring << ". " << wordoutput << it->kv_pair_.second << endl;
        if (wordnum >= limit) {
            break;

        }
        wordnum++;
    }
    return 0;
}

