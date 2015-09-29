#include "my.h"

/*
 * Precondition: A valid string
 * Postcondition: The last index of c
 */

int my_strrpos(char* str, char c){

    unsigned int i = 0;
    int loc = -1;

    if(str != NULL){
        while(str[i])   
        {
            if(str[i] == c)
                loc = i;

            i++;
        }
    }

    return loc;
}
