//precondition: ph is a list of nodes, n is a node
//postcondition: node n is placed at the end of list ph

#include "mylist.h"

void append(t_node* n, t_node** ph) {
    t_node* listptr;
    if (ph != NULL && n != NULL && n->elem != NULL) {
      if( *ph != NULL){
        listptr = *ph;
        while (listptr->next != NULL) {
            listptr = listptr->next;//parsing to the end
        }
        listptr->next = n;
        n->prev = listptr;//setting pointer
      }else
	*ph = n;
    }
}
