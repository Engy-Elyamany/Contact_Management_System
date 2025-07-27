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
#endif