//precondition: n and p are nodes or NULL
//postcondition: returns a node with data e, next node n and previous node p 

#include "mylist.h"

t_node *new_node(void *e, t_node *n, t_node *p){
    t_node* node = (t_node*)xmalloc(sizeof(t_node));//creating node
    node->elem = e;//setting pointers
    node->next = n;
    node->prev = p;
    return node;
}
