//precondition: ph is a list of nodes, n is a node, num >=0
//postcondition: n is placed in list ph at position num

#include "mylist.h"

void add_node_at(t_node* n, t_node** ph, unsigned int num) {
    t_node* listptr;
    int i = 0;
    if (ph != NULL && n != NULL && n->elem != NULL) {
      if(*ph != NULL){  
      listptr = *ph;
        while (listptr->next != NULL && i < num) { //parsing to num
            listptr = listptr->next;
            i++;
        }
        if (listptr->next != NULL) {
            if(n != NULL)n->next = listptr;
            if(listptr->prev != NULL) listptr->prev->next = n;
            else *ph = n; //setting pointer
            if(n!= NULL)n->prev = listptr->prev;
            listptr->prev = n;
        }
        else{
            listptr->next = n;
            if(n != NULL)n->prev = listptr;
        }
    }else
	*ph = n;
	}
}
