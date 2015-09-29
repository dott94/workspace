/*
 *precondition: takes two char*'s
 *postcondition: returns a new string containing s1 followed by s2
 *memory allocation: len(1st) + len(2nd) + 1
 */
#include "my.h"

char *my_strconcat(char *s1, char *s2) {
    char* returnval;
    int i;
    int len1 = 0;
    int len2 = 0;
    if (s1 == NULL && s2 == NULL) {  //NULL checking
        return NULL;
    }
    if (s1 != NULL) {
        len1 = my_strlen(s1);
    }
    if (s2 != NULL) {
        len2 = my_strlen(s2);
    }
    returnval = xmalloc(len1 + len2 + 1);  //memory allocation

    for (i = 0; i < len1; i++) {  //making the new string
        *(returnval + i) = *(s1 + i);
    }
    for (; i < len1 + len2; i++) {
        *(returnval + i) = *(s2 + i - len1);
    }
    *(returnval + i) = '\0';
    return returnval;
}
