/*precondition: takes two char*'s
 *postcondition: returns copy of entire content of src to pointer dst
 *assumes enough room if dst != NULL
 */
#include"my.h"

char *my_strcpy(char *dst, char *src) {
    int length;
    int i;
    if (src != NULL && dst != NULL) {//checking NULL
        length = my_strlen(src);
        for (i = 0; i < length; i++) {//looping through len of src
            *(dst + i) = *(src + i);//copying src into dst
        }
        *(dst + i) = '\0';
    }
    return dst;
}
