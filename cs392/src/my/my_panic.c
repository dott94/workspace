/*
 * precondition: takes in a char* and and unsigned int
 * postcondition: print the char* and exit with states n
 */

#include "my.h"
void my_panic(char* c, unsigned int n){
    my_str(c);
    exit(n);
}
