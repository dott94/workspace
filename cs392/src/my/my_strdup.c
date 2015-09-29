/*precondition: takes in a char*
 * postcondition:returns a dublicated string
 */

#include "my.h"


char *my_strdup(char* c){
    char* d = NULL;
    if(c != NULL){ //checking NULL
        d = xmalloc(my_strlen(c)); //allocating space of size of str(c)
        my_strcpy(d, c);
    }

    return d;

}
