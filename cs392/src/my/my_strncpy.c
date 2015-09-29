/*
 *precondition: takes two char*'s and an unsigned int
 *postcondition: returns copy of n chars of src to pointer dst
 */
#include "my.h"

char *my_strncpy(char *dst, char *src, unsigned int n) {
    int i;
    int length;
    if (src != NULL && dst != NULL) {
        length = my_strlen(src);

        for (i = 0; i < length; i++) {
            if (i >= n)      //stopping at int n
                break;

            *(dst + i) = *(src + i);  //copying src into dst
        }
        if (i < n) {
            *(dst + i) = '\0';
        }
    }
    return dst;
}
