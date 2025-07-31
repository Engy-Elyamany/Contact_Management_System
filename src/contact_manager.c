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
    const char *at = strchr(email, '@'); // find the first @ symbol
    if (!at || at == email)
        return 0; // incase @ is at first or doesnt exists

    const char *dot = strrchr(email, '.'); // find the last . symbol
    if (!dot || dot < at || dot == email + strlen(email) - 1)
        return 0; // incase (. doesn't exist) OR (exist before @) OR (is the last symbol)

    // Split domain part
    const char *domain = at + 1;
    if (!is_valid_domain(domain))
        return 0; // check last part

    // Check for invalid characters
    for (int i = 0; email[i] != '\0'; i++)
    {
        // allows only letters, numbers, dots, hyphens, underscores, and @ symbol
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '-' && email[i] != '_' && email[i] != '@')
        {
            return 0;
        }
    }
    // if passed all previous conditions, then it must be a valid email
    return 1;
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

node *search_contacts_by_name(node *head, char *name)
{
    node *temp = head;
    while (temp != NULL)
    {
        // search the list for the desired node that match the input name
        Data *node_name = ((Data *)temp->data);
        if (strcmp(node_name->contact_name, name) == 0)
        { // found the matching node
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

node *search_contacts_by_email(node *head, char *email)
{
    node *temp = head;
    while (temp != NULL)
    {
        // search the list for the desired node that match the input email
        Data *node_name = ((Data *)temp->data);
        if (strcmp(node_name->contact_mail, email) == 0)
        { // found the matching node
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

node *search_contacts_by_phoneNum(node *head, char *phoneNum)
{
    node *temp = head;
    while (temp != NULL)
    {
        // search the list for the desired node that match the input phone
        Data *node_name = ((Data *)temp->data);
        if (strcmp(node_name->contact_phone, phoneNum) == 0)
        { // found the matching node
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

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

void delete_contact(node **head)
{
    int delete_state;
    int delete_option;

    printf("======== Delete Contact ========\n");
    printf("1 => Delete by name\n2 => Delete by email\n3 => Delete by phone number\n4 => Delete all\n");
    printf("Your choice: ");
    scanf("%d", &delete_option);

    switch (delete_option)
    {
    case 1:
    {
    
        // this will handle empty list for now, but this should be handled at main for better flow
        //  the user will not be allowed to choose anything but add while the list is empty
        if (*head == NULL)
        {
            delete_state = EMPTY_LIST;
            break;
        }

        /*
        should validate user name here
        */

        printf("Enter the name : ");
        char name_delete[200];
       scanf("%s",name_delete);
        node *temp = search_contacts_by_name(*head, name_delete);
        delete_state = delete_node_by_key(head, temp);
    }
    break;

    case 2:
    {
        /*
       should validate user email here
       */
        printf("Enter the email : ");
        char mail_delete[200];
        scanf("%s", mail_delete);

        node *temp = search_contacts_by_email(*head, mail_delete);
        delete_state = delete_node_by_key(head, temp);
    }
    break;

    case 3:
    {
        /*
       should validate user phone here
       */
        printf("Enter the phone : ");
        char phone_delete[200];
        scanf("%s", phone_delete);

        node *temp = search_contacts_by_phoneNum(*head, phone_delete);
        delete_state = delete_node_by_key(head, temp);
    }
    break;

    case 4:
    {
        int choice = 3;
        while (choice != 0 && choice != 1)
        {
            printf("You are about to delete all your contacts [1 / 0]\n");

            scanf("%d", &choice);
            if (choice == 1)
            {
                destroy_list(head);
                printf("All Contacts Deleted Successfully\n");
            }
            else if (choice == 0)
            {
                printf("Deletion Aborted \n");
            }
            else
            {
                // repeat only case 4
                printf("Invalid Option! Please Choose \"1\" to proceed or \"0\" to abort\n");
            }
        }
    }
    break;

    default:
        printf("test - default switch\n");
        delete_state = INVALID_OPTION;
        break;
    }

    switch (delete_state)
    {
    case EMPTY_LIST:
        printf("Empty List! Please Try Again\n");
        delete_contact(head);
        break;
    case NOT_FOUND:
        printf("No Such Contact! Please Try Again\n");
        delete_contact(head);
        break;
    case INVALID_OPTION:
        printf("Invalid Option! Please Try Again\n");
        delete_contact(head);
        break;
    case SUCCESS:
        printf("Contact Deleted Successfully\n");
        break;

    default:
        break;
    }
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

// int add_node(node * *head, node * added_node)
// {
//     if (!(is_valid_email(((Data *)added_node->data)->contact_mail)))
//     {
//         printf("Invalid email address\n");
//         return 0;
//     }
//     if (!(check_duplicates_by_phoneNum(*head, added_node->data)))
//     {
//         return 0;
//     }

//     if (added_node == NULL)
//     { // allocation faild
//         printf("Allocation failed inside [add]\n");
//         return 0;
//     }
//     node *temp = *head;
//     if (temp == NULL)
//     { // add the very first element
//         *head = added_node;
//         printf("contact added succesfully\n");
//         return SUCCESS;
//     }

//     // there exist multiple elements in the list
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     } // temp is right at the last element

//     temp->next = added_node;
//     added_node->prev = temp;
//     added_node->next = NULL;
//     printf("contact added succesfully\n");
//     return SUCCESS;
// }
