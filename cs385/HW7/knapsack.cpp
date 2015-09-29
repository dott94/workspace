/*******************************************************************************
 * Name        : knapsack.cpp
 * Author      : David Ott
 * Date        : 11/30/2014
 * Description : knapsack program
 * Pledge      : I pledge my honor that I have abided by the Stevens honor system
 ******************************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
struct Item {
    unsigned int item_number, weight, value;
    string description;

    explicit Item(const unsigned int item_number, const unsigned int weight,
                  const unsigned int value, const string &description) :
        item_number(item_number), weight(weight), value(value), description(
            description) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Item &item) {
        os << "Item " << item.item_number << ": " << item.description << " ("
           << item.weight << (item.weight == 1 ? " pound" : " pounds")
           << ", $" << item.value << ")";
        os.flush();
        return os;
    }
};

bool is_number(const string& s) { //boolean value to find out if if string isdigit
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char *argv[]) {
    // Make sure the right number of command line arguments exist.
    if (argc != 3) {
        cerr << "Usage: ./knapsack <capacity> <filename>" << endl;
        return 1;
    }
    if (!is_number(argv[1]) || atoi(argv[1]) < 0) {//checking to make sure the input has proper values
        cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
        return 1;
    }

    unsigned int capacity = atoi(argv[1]);

    // Create an ifstream object.
    ifstream input_file(argv[2]);
    // If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
        return 1;
    }

    vector<Item> items;//creating our vector of items
    string line;
    int lineNum = 0;
    while (getline(input_file, line)) {
        lineNum++;
        stringstream ss(line);
        string name;
        string weight;
        string value;
        getline(ss, name, ',');
        getline(ss, weight, ',');
        getline(ss, value, ',');
        unsigned int weightInt;
        unsigned int valueInt;

        if (weight.empty() || value.empty() || name.empty()) {//proper num of fields
            cerr << "Error: Line number " << lineNum
                 << " does not contain 3 fields." << endl;
            return 1;
        }
        if (!is_number(weight) || atoi(weight.c_str()) < 0) {//checking weight validation
            cerr << "Error: Invalid weight '" << weight << "' on line number "
                 << lineNum << "." << endl;
            return 1;
        }
        if (!is_number(value) || atoi(value.c_str()) < 0) {//checkign value validation
            cerr << "Error: Invalid value '" << value << "' on line number "
                 << lineNum << "." << endl;
            return 1;
        }
        weightInt = atoi(weight.c_str());
        valueInt = atoi(value.c_str());
        Item i(lineNum, weightInt, valueInt, name);
        items.push_back(i);//fillng in the vector

    }
    cout << "Candidate items to place in knapsack:" << endl;//placing objects in the knapsack
    for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
        cout << "   " << *it << endl;
    }
    cout << "Capacity: " << capacity << " pound" << (capacity > 1 ? "s" : "") << endl;

    vector<vector<int> > F(lineNum + 1, vector<int>(capacity + 1));
    vector<vector<vector<Item> > > fItems(lineNum + 1,
                                          vector<vector<Item> >(capacity + 1));
    for (int i = 0; i <= lineNum; i++) {
        F[i][0] = 0;
    }
    for (unsigned int j = 0; j <= capacity; j++) {
        F[0][j] = 0;
    }

    for (int i = 1; i <= lineNum; i++) {//knapsack algorithm
        for (unsigned int j = 1; j <= capacity; j++) {
            int loose_it = F[i - 1][j];
            int use_it = F[i - 1][max(int(j - items[i - 1].weight), 0)]
                         + items[i - 1].value;

            if (j >= items[i - 1].weight) {
                F[i][j] = max(loose_it, use_it);
                if (loose_it < use_it) {
                    fItems[i][j] = fItems[i - 1][max(int(j - items[i - 1].weight),
                                                     0)];
                    fItems[i][j].push_back(items[i - 1]);
                } else {
                    fItems[i][j] = fItems[i - 1][j];
                }
            } else {
                F[i][j] = F[i - 1][j];
                fItems[i][j] = fItems[i - 1][j];
            }
        }
    }

    vector<Item> solution = fItems[lineNum][capacity];
    cout << "Items to place in knapsack:" << endl;
    int totalWeight = 0;
    for (vector<Item>::iterator it = solution.begin(); it != solution.end();
            ++it) {
        totalWeight += it->weight;
        cout << "   " << *it << endl;//printing out items
    }
    cout << "Total weight: " << totalWeight << " pound" << (totalWeight > 1 ? "s" : "") << endl;
    cout << "Total value : $" << F[lineNum][capacity] << endl;

}

