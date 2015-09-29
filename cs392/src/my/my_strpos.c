#include "my.h"

/*
 * Precondition: A valid string
 * Postcondition: The first index of c 
 */

int my_strpos(char* str, char c){
    unsigned int i = 0;

    if(str != NULL){
        while(str[i]){
            if(str[i] == c)
                return i;

            i++;
        }
    }

    return -1;
}
