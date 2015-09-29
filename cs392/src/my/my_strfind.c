/*
 *precondition: takes a char* and a char
 *postcondition: returns a pointer to the first iteration of char found
 */

#include "my.h"
char *my_strfind(char* string, char c){
    int index = my_strindex(string, c);  //index of c
    if(index < 0) return NULL;
    return (char*)(index + string);  //returning the pointer

}
