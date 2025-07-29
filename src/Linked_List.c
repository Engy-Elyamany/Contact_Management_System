#include "../include/Linked_List.h"
#include "../include/contact_manager.h"
int count_nodes(node *head)
{
    int count = 0;
    node *temp =head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *create_node(void *node_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    { // allocation faild
        return NULL;
    }
    new_node->data = node_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// added_node takes the return of create_node
void add_node(node **head, node *added_node)
{
    if (added_node == NULL)
    { // allocation faild
        printf("Allocation failed inside [add]\n");
        return;
    }

    node *temp = *head;
    if (temp == NULL)
    { // add the very first element
        *head = added_node;
        printf("contact added succesfully\n");
        return;
    }

    // there exist multiple elements in the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    } // temp is right at the last element

    temp->next = added_node;
    added_node->prev = temp;
    added_node->next = NULL;
    printf("contact added succesfully\n");
}

// takes return of search_function in node_to_be_update, the new Data struct that carries new information
void update_node(node *head, node *node_to_be_update, void *new_data)
{
    node *temp = search_list_by_key(head, node_to_be_update->data); // temp is right at the desired node to update
    if (temp == NULL)
    { // node not found
        printf("node not found\n");
        return;
    }
    temp->data = new_data;
    printf("contact updated successfully\n");
}

void delete_node_by_key(node **head, void *desired_data)
{
    if (*head == NULL)
    { // Empty list
        return;
    }

    // get the desired node from search function
    node *temp = search_list_by_key(*head, desired_data); // temp is right at the desired node

    if (temp == NULL)
    { // element not found
        return;
    }

    // handle node cases
    if (temp == *head && temp->next == NULL)
    {                 // there exists only one node in the list
        *head = NULL; // empty list
        free(temp);
        return;
    }

    if (temp == *head)
    { // delete the first node
        *head = temp->next;
        temp->next->prev = NULL; // prev pointer of head now points to null
        free(temp);
        return;
    }

    if (temp->next == NULL)
    { // delete the last node
        node *prev_node = temp->prev;
        free(temp);
        prev_node->next = NULL;
        return;
    }

    // delete any middle node
    node *prev_node = temp->prev;
    node *next_node = temp->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    free(temp);
}

void destroy_list(node **head)
{
    if (*head == NULL)
    { // Empty list
        return;
    }

    node *temp;
    node *cur = *head;
    while (cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    *head = NULL;
}
