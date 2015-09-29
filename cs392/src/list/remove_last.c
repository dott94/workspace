//precondition: ph is a list that contains at least one node
//postcondition: the last node in list ph is removed

#include "mylist.h"

void *remove_last(t_node** ph) {
    t_node* listptr;
    if (ph != NULL) {
        listptr = *ph;
        while (listptr->next != NULL) {//parsing to the end of the list
            listptr = listptr->next;
        }
        listptr->prev->next = NULL;//setting pointers to NULL
        listptr->prev = NULL;
    }
    return listptr->elem;
}
