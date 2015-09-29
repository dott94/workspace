/*precondition: takes an unsigned int
 *postconditino: checks return value of malloc
 */

#include "my.h"

void* xmalloc(unsigned int n) {
    void* p = NULL;
    if (!(p = malloc(n))) {
        my_str("virtual memory exhausted");
        exit(1);
    }
    return p;
}

