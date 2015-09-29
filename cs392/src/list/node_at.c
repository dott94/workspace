//precondition: n is a list on nodes, num is >= 0
//postcondition: the node at position num is returned 

#include "mylist.h"

t_node *node_at(t_node* n, unsigned int num) {
    int i = 0;
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL && i < num) {//parsing to int
            listptr = listptr->next;
            i++;
        }
    }
    return listptr;//returning the node
}
