#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    void *data;
    struct Node *next;
    struct Node *prev;
} node;

int count_nodes(node *head);
node *create_node(void *node_data);
void delete_node_by_key(node ** head, void *desired_data);
void destroy_list(node ** head);
void add_node(node **head, node *added_node);
void update_node(node *head, node *node_to_be_update, void *new_data);


node *search_list_by_key(node *head, void *desired_data); //just for testing
void test_print_content(node *head); //just for testing 
                               //dependent on the use case
#endif