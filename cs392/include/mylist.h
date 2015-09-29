/*
 * mylist.h
 *
 *  Created on: Feb 12, 2015
 *      Author: David
 */

#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "my.h"



typedef struct s_node
{

    void *elem;

    struct s_node *next;

    struct s_node *prev;

} t_node;


t_node *new_node(void *e, t_node *n, t_node *p);

void add_node(t_node*, t_node**);

void add_elem(void*, t_node**);

void append(t_node*, t_node**);

void add_node_at(t_node*, t_node**, unsigned int);

void *remove_node(t_node**);

void *remove_node_at(t_node**, unsigned int);

void *remove_last(t_node**);

unsigned int count_nodes(t_node*);

void empty_list(t_node**);

t_node *node_at(t_node*, unsigned int);

void *elem_at(t_node*, unsigned int);

void traverse_int(t_node*);

void traverse_string(t_node*);

void traverse_char(t_node*);

void debug_string(t_node*);

void debug_int(t_node*);

void debug_char(t_node*);

void print_char(t_node*);

void print_string(t_node*);

void print_int(t_node*);


#endif
