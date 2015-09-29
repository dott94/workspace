//precondition: ph is a list of nodes, n is a node
//postcondition: n is the first node in list ph

#include "mylist.h"

void add_node(t_node* n, t_node** ph) {
    if (n != NULL && ph != NULL && n->elem != NULL) {
        n->next = *ph;//setting pointer
        if(n->next != NULL) n->next->prev = n;
        *ph = n;//setting pointer to head node
    }
}
