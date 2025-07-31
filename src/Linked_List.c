#include "../include/Linked_List.h"
#include "../include/contact_manager.h"
int count_nodes(node *head)
{
    int count = 0;
    node *temp = head;
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

    Data *data_copy = malloc(sizeof(Data));
    memcpy(data_copy, (Data *)node_data, sizeof(Data));

    new_node->data = data_copy;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// added_node takes the return of create_node
int add_node(node **head, node *added_node)
{
    if (added_node == NULL)
    { // allocation faild
        printf("Allocation failed inside [add]\n");
        return MEMORY_ERROR;
    }
    node *temp = *head;
    if (temp == NULL)
    { // add the very first element
        *head = added_node;
        printf("contact added succesfully\n");
        return SUCCESS;
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
    return SUCCESS;
}

// node *search_list_by_key(node *head, void *desired_data)
// {
//     printf("inside search linkedlist\n");
//     if (head == NULL)
//     { // empty list
//         printf("inside search linkedlist - head is null\n");
//         return NULL;
//     }
//     printf("inside search linkedlist - after if\n");
//     node *temp = head;
//     while (temp != NULL && temp->data != desired_data)
//     {
//         printf("inside search linkedlist - inside while\n");
//         temp = temp->next;
//     }
//     printf("inside search linkedlist - after search logic\n");
//     return temp;
// }

// takes return of search function in node_to_be_update, the new Data struct that carries new information
int update_node(node *head, node *node_to_be_updated, void *new_data)
{
    node *temp = node_to_be_updated; // temp is right at the desired node to update
    if (temp == NULL)
    { // node not found
        printf("node not found\n");
        return NOT_FOUND;
    }

    free(node_to_be_updated->data); // free the old Data memory location

    Data *data_copy = malloc(sizeof(Data));
    memcpy(data_copy, (Data *)new_data, sizeof(Data)); // create a copy of the new data allocated on heap

    temp->data = data_copy; // store the copy inside the node
    printf("contact updated successfully\n");
    return SUCCESS;
}

// get the desired node from search function
int delete_node_by_key(node **head, node *desired_node)
{
    if (*head == NULL)
    { // Empty list
        return EMPTY_LIST;
    }


    if (desired_node == NULL)
    { // element not found
        return NOT_FOUND;
    }

    // handle node cases
    if (desired_node == *head && desired_node->next == NULL)
    {                 // there exists only one node in the list
        *head = NULL; // empty list
        free(desired_node->data);
        free(desired_node);
        return SUCCESS;
    }

    if (desired_node == *head)
    { // delete the first node
        *head = desired_node->next;
        desired_node->next->prev = NULL; // prev pointer of head now points to null
        free(desired_node->data);
        free(desired_node);
        return SUCCESS;
    }

    if (desired_node->next == NULL)
    { // delete the last node
        node *prev_node = desired_node->prev;
        free(desired_node->data);
        free(desired_node);
        prev_node->next = NULL;
        return SUCCESS;
    }

    // delete any middle node
    node *prev_node = desired_node->prev;
    node *next_node = desired_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    free(desired_node->data);
    free(desired_node);
    return SUCCESS;
}

int destroy_list(node **head)
{
    if (*head == NULL)
    { // Empty list
        return EMPTY_LIST;
    }

    node *temp;
    node *cur = *head;
    while (cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp->data);
        free(temp);
    }
    *head = NULL;
    return SUCCESS;
}
