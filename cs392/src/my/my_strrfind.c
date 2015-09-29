/*
 *precondition: takes a char* and a char
 *postcondition: returns a pointer to the last iteration of char found
 */

#include "my.h"
char *my_strrfind(char* string, char c) {
    int index = my_strrindex(string, c); //finding the index of c
    if (index < 0)
        return NULL;
    return (char*) (index + string);  //returning the pointer

}
