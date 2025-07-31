#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define MEMORY_ERROR -1
#define EMPTY_LIST -2
#define NOT_FOUND -3
#define INVALID_OPTION -4

typedef struct Node
{
    void *data;
    struct Node *next;
    struct Node *prev;
} node;

int count_nodes(node *head);
node *create_node(void *node_data);
int add_node(node **head, node *added_node);
node *search_list_by_key(node *head, void *desired_data); 
int update_node(node *head, node *node_to_be_update, void *new_data);
int delete_node_by_key(node **head, node * desired_node);
int destroy_list(node ** head);

#endif