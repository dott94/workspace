//precondition: ph is a list on size n > 0, num is greater than 0
//postcondition: the node at position num is removed from ph, if num is >= n, last node is removed

#include "mylist.h"

void *remove_node_at(t_node** ph, unsigned int num) {
    t_node* listptr;
    int i = 0;
    if (ph != NULL) {
        listptr = *ph;
        while (listptr->next != NULL && i < num) {//parsing to num
            listptr = listptr->next;
            i++;
        }

        if (listptr->prev != NULL)
            listptr->prev->next = listptr->next;
        else
            *ph = listptr->next;
        if (listptr->next != NULL)
            listptr->next->prev = listptr->prev;
        listptr->prev = NULL;//setting pointers to NULL
        listptr->next = NULL;

    }
    return listptr->elem;
}

