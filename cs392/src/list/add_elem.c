//precondition: ph is a list of nodes
//postcondition: the first node of ph contains the data e 

#include "mylist.h"

void add_elem(void* e, t_node** ph) {
    if (ph != NULL) {
        t_node* node = new_node(e, NULL, NULL);//creating node
        add_node(node, ph);//adding it
    }
}
