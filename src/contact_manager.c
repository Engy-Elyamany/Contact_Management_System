#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

int is_valid_domain(const char *domain)
{
    for (int i = 0; valid_domains[i] != NULL; i++)
    {
        if (strcmp(domain, valid_domains[i]) == 0)
        {
            return 1; // Domain found
        }
    }
    return 0; // Domain not found
}

int is_valid_email(const char *email)
{
    const char *at = strchr(email, '@'); //find the first @ symbol
    if (!at || at == email)
        return 0; // incase @ is at first or doesnt exists

    const char *dot = strrchr(email, '.'); //find the last . symbol
    if (!dot || dot < at || dot == email + strlen(email) - 1)
        return 0; //incase (. doesn't exist) OR (exist before @) OR (is the last symbol)

    // Split domain part
    const char *domain = at + 1;
    if (!is_valid_domain(domain))
        return 0; // check last part

    // Check for invalid characters
    for (int i = 0; email[i] != '\0'; i++)
    {
        //allows only letters, numbers, dots, hyphens, underscores, and @ symbol
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '-' && email[i] != '_' && email[i] != '@')
        {
            return 0;
        }
    }
    //if passed all previous conditions, then it must be a valid email
    return 1;
}
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

int add_node(node **head, node *added_node)
{
    if (!(is_valid_email(((Data *)added_node->data)->contact_mail)))
    {
        printf("Invalid email address\n");
        return 0;
    }
if (! (check_duplicates_by_phoneNum(*head, added_node->data )))
{
        return 0;
}

    if (added_node == NULL)
    { // allocation faild
        printf("Allocation failed inside [add]\n");
        return 0;
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
