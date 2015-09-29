//David Ott
//test main for mylist
//I pledge my honor that I have abided by the stevens honor system -DO

#include "mylist.h"

int main() {

//    char* s1 = "MY";
//    char* s2 = "NAME'S";
//    char* s3 = "DAVID";
//    char* data = "Some test data";
//    char d, e, f;
//    int a, b, c;
//
//    t_node* head = (t_node*) xmalloc(sizeof(t_node));
//    t_node* node = (t_node*) xmalloc(sizeof(t_node));
//    t_node* node2 = new_node("node2test", NULL, NULL);
//    t_node* node3 = new_node("node3test", NULL, NULL);
//
//    //testing new_node()
//    if ((node = new_node(data, NULL, NULL)) != NULL)
//        my_str("new_node NULL test passed\n");
//    else
//        my_str("new_node NULL test FAILED\n");
//
//    if ((node = new_node(NULL, NULL, NULL)) == NULL)
//        my_str("new_node NULL, NULL test passed\n");
//    else
//        my_str("new_node NULL, NULL test FAILED\n");
//
//    if ((node = new_node(NULL, node, NULL)) == NULL)
//        my_str("new_node NULL data test passed\n");
//    else
//        my_str("new_node NULL data test FAILED\n");
//    free(node);
//
//    if ((node = new_node(NULL, NULL, node)) == NULL)
//        my_str("new_node NULL data test passed\n");
//    else
//        my_str("new_node NULL data test FAILED\n");
//    free(node);
//
//    if ((node = new_node(data, node, NULL)) != NULL)
//        my_str("new_node normal test passed\n");
//    else
//        my_str("new_node normal test FAILED\n");
//
//    if ((node = new_node(data, NULL, node)) != NULL)
//        my_str("new_node normal test passed\n");
//    else
//        my_str("new_node normal test FAILED\n");
//
//    //testing add_node()
//    add_node(NULL, &head);
//    if (head != NULL)
//        my_str("add_node NULL node test passed\n");
//    else
//        my_str("add_node NULL node test FAILED\n");
//
//    add_node(node, NULL);
//    if (node->prev == NULL)
//        my_str("add_node NULL head test passed\n");
//    else
//        my_str("add_node NULL head test FAILED\n");
//
//    add_node(NULL, NULL);
//    my_str("add_node NULL NULL passed");
//
//    char* headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    add_node(node, &head);
//    if (head == node && head->next->elem == headdata)
//        my_str("add_node normal test passed\n");
//    else
//        my_str("add_node normal test FAILED\n");
//
//    //testing add_elem()
//    add_elem(data, NULL);
//    my_str("add_elem NULL head test passed\n");
//
//    add_elem(NULL, NULL);
//    my_str("add_elem NULL, NULL test passed\n");
//
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    add_elem(data, &head);
//    if (head->elem == data && head->next->elem == headdata)
//        my_str("add_elem normal test passed\n");
//    else
//        my_str("add_elem normal test FAILED\n");
//
//    //testing append()
//    data = "testing data";
//    free(node);
//    node = (t_node*) xmalloc(sizeof(t_node));
//    node->elem = data;
//    node->next = NULL;
//    node->prev = NULL;
//
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//
//    append(NULL, &head);
//    if (head->next == NULL)
//        my_str("append NULL node test passed\n");
//    else
//        my_str("append NULL node test FAILED\n");
//
//    append(node, NULL);
//    if (node->prev == NULL)
//        my_str("append NULL head test passed\n");
//    else
//        my_str("append NULL head test FAILED\n");
//
//    append(NULL, NULL);
//    my_str("append NULL, NULL test passed\n");
//
//    append(node, &head);
//    if (head->next == node && head->next->prev == head)
//        my_str("append normal test passed\n");
//    else
//        my_str("append normal test FAILED\n");
//
//    //testing remove_node()
//    remove_node(NULL);
//    my_str("remove_node NULL test passed\n");
//
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    remove_node(&head);
//    if (head == NULL)
//        my_str("remove_node of head passed\n");
//    else
//        my_str("remove node of head FAILED\n");
//
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    char* newdata = "newdata";
//    add_elem(newdata, &head);
//
//    remove_node(&head);
//    if (head->elem == newdata)
//        my_str("remove_node of list of size 2 test passed\n");
//    else
//        my_str("remove_node of list of size 2 test FAILED\n");
//
//    //testing add_node_at()
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    newdata = "newdata";
//    add_elem(newdata, &head);
//    char* nodedata = "Test";
//    node = new_node(nodedata, NULL, NULL);
//    add_node_at(node, &head, 0);
//
//    if (head->elem == nodedata)
//        my_str("add_node_at empty list pos 0 test passed\n");
//    else
//        my_str("add_node_at empty list pos 0 test FAILED\n");
//
//    add_node_at(node, &head, 100);
//    if (head->next->next == node)
//        my_str("add_node_at num > length(list) test passed\n");
//    else
//        my_str("add_node_at num > length(list) test FAILED\n");
//
//    add_node_at(node2, &head, 1);
//    if (head->next == node2)
//        my_str("add_node_at 0 < num < length(list) test passed\n");
//    else
//        my_str("add_node_at 0 < num < length(list) test FAILED\n");
//
//    add_node_at(NULL, &head, 0);
//    my_str("add_node_at NULL node test passed\n");
//
//    add_node_at(node3, NULL, 0);
//    my_str("add_node_at NULL head test passed\n");
//
//    //remove_node_at() tests
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    newdata = "newdata";
//    add_elem(newdata, &head);
//
//    remove_node_at(&head, 0);
//    if (head->elem == newdata)
//        my_str("remove_node_at head test passed\n");
//    else
//        my_str("remove_node_at head test FAILED\n");
//
//    newdata = "blah";
//    add_elem(newdata, &head);
//    remove_node_at(&head, 1);
//    if (head->elem == headdata && head->next == NULL)
//        my_str("remove_node_at 0 < pos < length(list) test passed\n");
//    else
//        my_str("remove_node_at 0 < pos < length(list) test FAILED\n");
//
//    remove_node_at(NULL, 100);
//    my_str("remove_node_at NULL test passed\n");
//    remove_node_at(&head, 100);
//    if (head == NULL)
//        my_str("remove_node_at pos > length(list) test passed\n");
//    else
//        my_str("remove_node_at pos > length(list) test FAILED\n");
//
//    //testing remove_last()
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    newdata = "newdata";
//    add_elem(newdata, &head);
//
//    remove_last(&head);
//    if (head->next == NULL)
//        my_str("remove_last normal test passed\n");
//    else
//        my_str("remove_last normal test FAILED\n");
//
//    remove_last(&head);
//    if (head == NULL)
//        my_str("remove_last head test passed\n");
//    else
//        my_str("remove_last head test FAILED\n");
//
//    remove_last(NULL);
//    my_str("remove_last NULL test passed\n");
//
//    //testing node_at()
//    headdata = "Original head";
//    head = new_node(headdata, NULL, NULL);
//    newdata = "newdata";
//    add_elem(newdata, &head);
//
//    if (node_at(NULL, 1) == NULL)
//        my_str("node_at NULL test passed\n");
//    else
//        my_str("node_at NULL test FAILED\n");
//
//    if (node_at(head, 100)->elem == newdata)
//        my_str("node_at num > length(list) test passed\n");
//    else
//        my_str("node_at num > length(list) test FAILED\n");
//
//    if (node_at(head, 0)->elem == headdata)
//        my_str("node_at head test passed\n");
//    else
//        my_str(node_at(head, 0)->elem);
//
//    if (node_at(head, 1)->elem == newdata)
//        my_str("node_at normal test passed\n");
//    else
//        my_str("node_at normal test FAILED\n");
//
//    //testing count_nodes()
//    if (count_nodes(head) == 2)
//        my_str("count_nodes normal test passed\n");
//    else
//        my_str("count_nodes normal test FAILED\n");
//
//    if (count_nodes(NULL) == 0)
//        my_str("count_nodes NULL test passed\n");
//    else
//        my_str("count_nodes NULL test FAILED\n");
//
//    if (count_nodes(head->next) == 1)
//        my_str("count_nodes test passed\n");
//    else
//        my_str("count_nodes test FAILED\n");
//
//    //testing empty_list()
//    empty_list(NULL);
//    my_str("empty_list NULL test passed\n");
//
//    empty_list(&head);
//    if (head == NULL)
//        my_str("empty_list normal test passed\n");
//    else
//        my_str("empty_list normal test FAILED\n");
//
//    empty_list(&head);
//    if (head == NULL)
//        my_str("empty_list empty list test passed\n");
//    else
//        my_str("empty_list empty list test FAILED\n");
//
//    //testing elem_at()
//    if (elem_at(NULL, 1) == NULL)
//        my_str("elem_at NULL test passed\n");
//    else
//        my_str("elem_at NULL test FAILED\n");
//
//    if (elem_at(head, 100) == newdata)
//        my_str("elem_at num > length(list) test passed\n");
//    else
//        my_str("elem_at num > length(list) test FAILED\n");
//
//    if (elem_at(head, 0) == headdata)
//        my_str("elem_at head test passed\n");
//    else
//        my_str("elem_at head test FAILED\n");
//
//    if (elem_at(head, 1) == newdata)
//        my_str("elem_at normal test passed\n");
//    else
//        my_str("elem_at normal test FAILED\n");
//
//    //testing traverse_int()
//    a = 1;
//    b = 2;
//    c = 3;
//    add_elem(&a, &head);
//    add_elem(&b, &head);
//    add_elem(&c, &head);
//    traverse_int(NULL); //Nothing is printed
//    traverse_int(head); //3 2 1 is printed
//
//    //testing traverse_string()
//    empty_list(&head);
//    add_elem(s3, &head);
//    add_elem(s2, &head);
//    add_elem(s1, &head);
//    traverse_string(NULL); //Nothing is printed
//    traverse_string(head); //MY NAME'S DAVID is printed
//
//    //testing traverse_char()
//    d = 'a';
//    e = 'b';
//    f = 'c';
//    empty_list(&head);
//    add_elem(&d, &head);
//    add_elem(&e, &head);
//    add_elem(&f, &head);
//    traverse_char(NULL); //Nothing is printed
//    traverse_char(head); //c b a is printed
//
//    //testing debug_string
//    empty_list(&head);
//    add_elem(s3, &head);
//    add_elem(s2, &head);
//    add_elem(s1, &head);
//    traverse_string(NULL); //Nothing is printed
//    traverse_string(head); //(NULL<-MY->NAME'S) (MY<-NAME's->DAVID) (NAME'S<-DAVID->NULL) is printed
//
//    //testing debug_int
//    a = 3;
//    b = 2;
//    c = 1;
//    add_elem(&a, &head);
//    add_elem(&b, &head);
//    add_elem(&c, &head);
//    debug_int(NULL); //Nothing is printed
//    debug_int(head); //(NULL<-1->2) (1<-2->3) (2<-3->NULL)(6<-3->N) is printed
//
//    //testing debug_char
//    d = 'd';
//    e = 'a';
//    f = 'v';
//    empty_list(&head);
//    add_elem(&d, &head);
//    add_elem(&e, &head);
//    add_elem(&f, &head);
//    debug_char(NULL); //Nothing is printed
//    debug_char(head); //(NULL<-v->a) (v<-a->d) (a<-d->NULL) is printed
//
//    //testing print_char
//    d = 'd';
//    e = 'a';
//    f = 'v';
//    empty_list(&head);
//    add_elem(&d, &head);
//    add_elem(&e, &head);
//    add_elem(&f, &head);
//    print_char(NULL); //Nothing is printed
//    print_char(head); //(NULL<-v->a) is printed
//
//    //testing print_string
//    empty_list(&head);
//    add_elem(s3, &head);
//    add_elem(s2, &head);
//    add_elem(s1, &head);
//    print_string(NULL); //Nothing is printed
//    print_string(head); // (NULL<-MY->NAME's) is printed
//
//    //testing print_int
//    a = 1;
//    b = 2;
//    c = 3;
//    add_elem(&a, &head);
//    add_elem(&b, &head);
//    add_elem(&c, &head);
//    print_int(NULL); //Nothing is printed
//    print_int(head); //(NULL<-3->2) is printed
//
//    empty_list(&head);
//    free(node);
//    free(node2);
//    free(node3);
//    free(head);
//
//    return 0;

    int arr[10] = { 4, 65, 32, 1, 68, 23, 83, 12, 6, 82 };
    char *str = "Hello!";
    char *str2 = "World!";
    t_node *head = NULL;
    unsigned int i;
    t_node *tmp = NULL;
    int n = 5;
    t_node **test = NULL;
    void *ret = NULL;

    for (i = 0; i < 3; i++)
        add_node(new_node(&arr[i], NULL, NULL), &head);
    traverse_int(head);
    debug_int(head);
    my_char('\n');
    for (; i < 7; i++)
        add_elem(&arr[i], &head);
    debug_int(head);
    my_char('\n');
    for (; i < 10; i++)
        append(new_node(&arr[i], NULL, NULL), &head);
    debug_int(head);
    my_char('\n');
    tmp = new_node(&n, NULL, NULL);
    add_node_at(tmp, &head, 5);
    debug_int(head);
    my_char('\n');
    add_node_at(new_node(&n, NULL, NULL), &head, 0);
    debug_int(head);
    my_char('\n');
    add_node_at(new_node(&n, NULL, NULL), &head, 564);
    debug_int(head);
    my_char('\n');
    my_int(count_nodes(head));
    my_char('\n');
    ret = remove_node(&head);
    my_int(*((int*) ret));
    my_char('\n');
    debug_int(head);
    my_char('\n');
    ret = remove_last(&head);
    my_int(*((int*) ret));
    my_char('\n');
    debug_int(head);
    my_char('\n');
    ret = remove_node_at(&head, 0);
    my_int(*((int*) ret));
    my_char('\n');
    debug_int(head);
    my_char('\n');
    ret = remove_node_at(&head, 243);
    my_int(*((int*) ret));
    my_char('\n');
    debug_int(head);
    my_char('\n');
    ret = remove_node_at(&head, 3);
    my_int(*((int*) ret));
    my_char('\n');
    debug_int(head);
    my_char('\n');
    empty_list(&head);
    debug_int(head);
    my_char('\n');
    add_elem(str2, &head);
    my_char('\n');
    add_elem(str, &head);
    my_char('\n');
    debug_string(head);
    my_char('\n');
    traverse_string(head);
    my_char('\n');
    debug_char(head);
    my_char('\n');
    traverse_char(head);
    my_char('\n');
    my_str((char*) elem_at(head, 0)); /* Hello */
    my_char('\n');
    my_str((char*) elem_at(head, 43)); /* World */
    my_char('\n');
    tmp = node_at(head, 0);
    print_string(tmp);
    my_char('\n');
    tmp = node_at(head, 43);
    print_string(tmp);
    my_char('\n');
    empty_list(&head);
    debug_string(head);
    /* this last one is mainly to clear memory */

    return 0;

}
