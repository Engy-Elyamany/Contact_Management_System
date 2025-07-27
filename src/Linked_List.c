#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

node *create_node(void *node_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = node_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


