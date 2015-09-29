/*
 *precondition: takes two char*'s
 *postcondition: returns an integer based on the sizes of the two char*'s
 *same as strcmp but only first n chars
 *positive is s1 > s2
 *0 if s1<s2, 0 if s1 = s2
 */
#include "my.h"

int my_strncmp(char *s1, char *s2, unsigned int n) {
    int i;
    int len1;
    int len2;
    int minimum;
    int returnval;
    if (s1 == NULL && s2 == NULL) {  //NULL checking
        return 0;
    } else if (s1 == NULL && s2 != NULL) {
        return -1;
    } else if (s1 != NULL && s2 == NULL) {
        return 1;
    }

    len1 = my_strlen(s1);   //len of s1 and s2
    len2 = my_strlen(s2);
    len1 = ((len1 < n)? len1: n);  //making sure len is not > n
    len2 = ((len2 < n)? len2: n);
    minimum = ((len1 < len2) ? len1 : len2);
    returnval = 0;
    for (i = 0; i < minimum; i++) {
        returnval += *(s1 + i) - *(s2 + i);
        if (returnval != 0) {
            return returnval;
        }
    }
    if (len1 < len2) {
        return -1;
    } else if (len2 < len1) {
        return 1;
    } else
        return 0;
}
