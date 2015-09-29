//precondition: a non empty vector
//postcondition: all of the elements of the vector are free and the vector ptr is free
#include "my.h"

void my_vectfree(char** vect){
    int i = 0;
    if(vect != NULL){
        while(vect[i] != NULL){
            free(vect[i]);
            i++;
        }
        free(vect);
    }


}
