/*
 *precondition: takes two char*'s
 *postcondition: returns a string of s2 copied to the end of s1
 */
#include "my.h"

char *my_strcat(char *s1, char *s2){
    int i;
    int len1 = 0;
    int len2 = 0;
    if(s1 != NULL){  //if s1 is not NULL
        len1 = my_strlen(s1);
        if(s2 != NULL){
            len2 = my_strlen(s2);
        }

        for(i = 0; i < len2; i++){
            *(s1 + len1 + i) = *(s2 + i);  //making the new string
        }
    }
    return s1;
}
