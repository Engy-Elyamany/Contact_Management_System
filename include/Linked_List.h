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

node *create_node(void *node_data);
void delete_node_by_key(node ** head, void *desired_data);
node *search_list_by_key(node *head, void *desired_data); //just for testing
void print_content(node *head); //just for testing
                               //dependent on the use case

#endif