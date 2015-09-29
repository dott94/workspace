//precondition: n is a list of nodes, num >= 0
//postcondition: elem in node at position num is returned 

#include "mylist.h"

void *elem_at(t_node* n, unsigned int num) {
    int i = 0;
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL && i < num) {//parsing to position of int
            listptr = listptr->next;
            i++;
        }
    }
    return listptr->elem;//returning elem
}
