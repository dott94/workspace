//precondition: n is a list of nodes
//postcondition: the length of list n is returned 

#include "mylist.h"

unsigned int count_nodes(t_node* n) {
    unsigned int count = 0;//creating count
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {//parsing list
            listptr = listptr->next;
            count ++;
        }
    }
    return count + 1;//returning count
}
