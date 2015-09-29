#include "my.h"

int my_strrindex(char* s, char c) {
    int i = my_strlen(s) - 1;
    if(!s) return -1;
    while (i >= 0) {
        if (*(s + i) == c) {
            return i;
        }
        i--;
    }
    return -1;
}

