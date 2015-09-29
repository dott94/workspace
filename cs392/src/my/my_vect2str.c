/*precondition: vector is a vector of strings
 * postcondition: contents of the vector are concatenated into one string */

#include "my.h"

char* my_vect2str(char** vector) {
    char* string;
    char** temp;
    unsigned int stringlen;

    if (*vector == NULL) {
        return "";
    }
    temp = vector;
    for (stringlen = 0; *vector != NULL; vector++)
        stringlen += (my_strlen(*vector) + 1);
    stringlen--;
    string = (char*) xmalloc(stringlen * sizeof(char));
    for (vector = temp; *vector != NULL; vector++) {
        my_strcat(string, *vector);
        my_strcat(string, " ");
    }
    string[stringlen] = '\0';
    return string;

}
