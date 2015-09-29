/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : David Ott
 * Date        : 9/10/14
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the stemevs honor system
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit) :
            is_prime_(new bool[limit + 1]), limit_(limit) {
        sieve();
    }

    ~PrimesSieve() {
        delete[] is_prime_;
    }

    inline int num_primes() const {
        return num_primes_;
    }

    void display_primes() {

        //Displays the number of primes within the limit and the list of those primes
        cout << "Number of primes found: " << count_num_primes() << endl;

        cout << "Primes up to " << limit_ << ":" << endl;

        int j = 1;
        int k = max_prime_(limit_);
        for (int i = 0; i <= limit_; i++) {

            if (is_prime_[i] == 1 && count_num_primes() > 20 && i != k) {
                if (num_digits(i) == 1) {
                    cout << "  " << i << " ";
                }
                if (num_digits(i) == 2) {
                    cout << " " << i  << " ";
                }
                if (num_digits(i) == 3) {
                    cout << "" << i  << " ";

                }

                j++;
                if (j > 20) {
                    cout << endl;
                    j = 1;
                }

            } else if (is_prime_[i] == 1 && i != k) {
                cout << i << " ";

            }

        }
        cout << k;

    }

private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_;

    int max_prime_(int Num)
    //displays the max prime in the limit
            {
        int FactorCount = 0;

        for (int i = Num; i >= 2; --i) {

            for (int j = 2; j < sqrt(i) + 1; ++j)  // HERE
                    {
                if (i % j == 0) {
                    ++FactorCount;
                    break;  // HERE
                }
            }

            if (FactorCount == 0) {
                return i;
                break;
            }

            FactorCount = 0;
        }
        return 0;
    }

    int count_num_primes() {
        // counts the number of primes in the limnit
        int count = 0;
        for (int i = 0; i <= limit_; i++) {
            if (is_prime_[i] == 1) {
                count++;
            }
        }
        return count;

    }

    int num_digits(int num) const {
        //returns the number of digits in an integer(used in the display method)
        int digits = 0;
        if (num < 0) {
            digits = 1;
        }
        while (num) {
            num /= 10;
            digits++;
        }
        return digits;
    }

    void sieve() {
        if (limit_ > 0) {
            is_prime_[0] = false;
        }
        if (limit_ > 1) {
            is_prime_[1] = false;
        }
        for (int i = 2; i <= limit_; ++i) {
            is_prime_[i] = true;
            // add the prime to a new array that will print in the display function
        }
        for (int i = 2, i_bound = (int) sqrt(limit_); i <= i_bound; ++i) {
            if (is_prime_[i]) {
                for (int j = i * i; j <= limit_; j += i) {
                    is_prime_[j] = false;
                }

            }

        }
        int count = 0;
        for (int i = 2; i < limit_; i++) {
            if (is_prime_[i]) {
                count++;
            }
        }
    }
};

int main(void) {
    cout << "**************************** " << "Sieve of Eratosthenes"
            << " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    istringstream iss(limit_str);

    // Check for error.
    if (!(iss >> limit)) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }
    //cout<<limit<< endl;

    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve *p1 = new PrimesSieve(limit);
    cout << endl;
    p1->display_primes();
    delete p1;

    return 0;
}

