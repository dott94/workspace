/*precondition: A non empty string
 postcondition: A vector containing the items of the string
 */

#include "my.h"

char** my_str2vect(char* usrstr) {
    char** vector;
    char* tempstr;
    int words;
    int i;
    int inst = 0;

    if (usrstr != NULL) {
        tempstr = my_strdup(usrstr);
        for (i = 0; tempstr[i]; i++) {
            if ((tempstr[i] == ' ' || tempstr[i] == '\t') && i > 0 //replacing all empty spaces with null char
                    && tempstr[i - 1] != ' ' && tempstr[i - 1] != '\t'
                    && tempstr[i - 1] != '\0') {
                tempstr[i] = '\0';
                inst++;
            }
        }
        i--;
        if (tempstr[i] != '\t' && tempstr[i] != ' ' && tempstr[i] != '\0') {
            inst++;
        }
        vector = (char**) xmalloc((inst + 1) * sizeof(char*)); //allocating vector space of size str
        words = inst - 1;
        inst = 0;
        for (i = 0; inst <= words;) {
            while (tempstr[i] == ' ' || tempstr[i] == '\t')
                i++;
            vector[inst++] = my_strdup(tempstr + i);//
            i += (my_strlen(tempstr + i) + 1);
        }
        vector[inst] = NULL;
        free(tempstr);
    } else
        vector = NULL;
    return vector;
}

