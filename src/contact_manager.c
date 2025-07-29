#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

// Bouns: implement a quicker sorting algorithm
void sort_list_by_name(node *head, int count)
{
    for (int i = 0; i < count; i++)
    {
        node *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            Data *a = (Data *)curr->data;
            Data *b = (Data *)curr->next->data;
            if (strcmp(a->contact_name, b->contact_name) > 0)
            {
                void *temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
    }
}
int check_duplicates_by_phoneNum(node *head, Data *added_node)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (strcmp(added_node->contact_phone,
                   ((Data *)temp->data)->contact_phone) == 0)
        {
            printf("NUMBER ALREADY SAVED\n");
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void display_list(node *head)
{
    node *i = head;
    if (i == NULL)
    {
        printf("The list is empty(inside display_list)\n");
        return;
    }
    while (i != NULL)
    {
        Data *node_data = (Data *)i->data;
        // printf("   ID    : %d\n", node_data->contact_id);
        printf("   Name  : %s", node_data->contact_name);
        printf("   E-mail: %s", node_data->contact_mail);
        printf("   Number: %s\n", node_data->contact_phone);
        printf("------------------------\n");
        i = i->next;
    }
}