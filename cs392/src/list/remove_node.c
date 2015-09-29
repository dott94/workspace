//precondition: ph is list that containins atleast one node
//postcondition: ph has first node removed 

#include "mylist.h"

void *remove_node(t_node** ph) {
    t_node* head = NULL;//setting node = NULL
    if (ph != NULL) {
        head = *ph;
        *ph = (*ph)->next;
        (*ph)->prev = NULL;//setting pointers to null
    }
    return head->elem;
}
