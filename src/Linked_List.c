#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

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


node *search_list_by_key(node *head, void *desired_data)
{
    /*
    
    search logic - Malak's implementation
    
    */

    //This code is just for testing
        // node *temp = head;
        // while (temp->data != desired_data)
        // {
        //     temp = temp->next;
        // }
        // return temp;
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
    { // there exists only one node in the list
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

void destroy_list(node ** head)
{
     if (*head == NULL)
    { // Empty list
        return;
    }
    
    node * temp;
    node * cur = *head;
    while(cur != NULL)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    *head = NULL;
}

//This code is just for testing
void print_content(node *head)
{
    if(head == NULL){
        printf("empty list\n");
        return;
    }
    node * temp = head;
    while (temp != NULL)
    {
        printf("%s |", ((Data *)temp->data)->contact_name);
        printf("%s |", ((Data *)temp->data)->contact_mail);
        printf("%s\n", ((Data *)temp->data)->contact_phone);
        temp = temp->next;
    }
    printf("\n");
}
