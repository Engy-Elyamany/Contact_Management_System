#include "../include/Linked_List.h"
#include "../include/contact_manager.h"
#include "../include/validation.h"
int x;

int remove_phone_number(Data *contact, const char *number_to_delete)
{
    int index = -1;
    for (int i = 0; i < contact->phone_count; i++)
    {
        if (strcmp(contact->contact_phone[i], number_to_delete) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return NOT_FOUND;

    // Shift remaining numbers left
    for (int i = index; i < contact->phone_count - 1; i++)
    {
        strcpy(contact->contact_phone[i], contact->contact_phone[i + 1]);
    }
    contact->phone_count--;

    return SUCCESS;
}

int check_duplicates_by_phoneNum(node *head, Data *added_node)
{
    node *temp = head;

    while (temp != NULL)
    {
        for (int i = 0; i < added_node->phone_count; i++)
        {
            if (strcmp(added_node->contact_phone[i],
                       ((Data *)temp->data)->contact_phone[i]) == 0)
            {
                printf("Number Already Saved For Another Contact\n");
                return 0;
            }
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
        for (int i = 0; i < node_name->phone_count; i++)
        {
            if (strcmp(node_name->contact_phone[i], phoneNum) == 0)
            { // found the matching node
                x = i;
                return temp;
            }
        }

        temp = temp->next;
    }
    return NULL;
}

void display_contact(node *node_to_display)
{
    Data *data = (Data *)node_to_display->data;

    printf("Name  : %s\n", data->contact_name);
    printf("E-mail: %s\n", data->contact_mail);

    for (int i = 0; i < data->phone_count; i++)
    {
        printf("Number %d: %s\n", i + 1, data->contact_phone[i]);
    }

    printf("------------------------\n");
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

void display_list(node *head)
{
    node *i = head;
    if (i == NULL)
    {
        printf("List is Empty! Nothing to display\n");
        return;
    }
    while (i != NULL)
    {
        Data *node_data = (Data *)i->data;
        printf("Name  : %s\n", node_data->contact_name);
        printf("E-mail: %s", node_data->contact_mail);
        for (int i = 0; i < node_data->phone_count; i++)
        {
            printf("   \nNumber: %s", node_data->contact_phone[i]);
        }

        printf("\n------------------------\n");
        i = i->next;
    }
}

void add_contact(node **head)
{
    Data temp;

    printf("====== ADD A CONTACT ======\n");
    int new_name_check = get_valid_name(temp.contact_name, sizeof(temp.contact_name));
    int new_phone_check;
    int new_mail_check = get_valid_email(temp.contact_mail, sizeof(temp.contact_mail));
    while (1)
    {
        printf("How many numbers to add (max 5)? ");
        scanf("%d", &temp.phone_count);
        getchar(); // flush newline after scanf

        if (temp.phone_count > 0 && temp.phone_count <= 5)
        {
            // Get each phone number one by one
            for (int i = 0; i < temp.phone_count; i++)
            {

                printf("Enter phone number %d: ", i + 1);
                printf("phone number %d: ", i + 1);
                new_phone_check = get_valid_phoneNum(temp.contact_phone[i], sizeof(temp.contact_phone[i]));
                if (!new_phone_check)
                {
                    // if user refused to enter a valid number, addition failed
                    break;
                }
            }
            break; // exit the loop
        }
        else
        {
            printf("Maximum 5 numbers allowed. Please try again.\n");
        }
    }

    if (new_name_check && new_mail_check && new_phone_check)
    { // all valid

        // Check for duplicates
        if (!(check_duplicates_by_phoneNum(*head, &temp)))
        {
            return; // Duplicate found
        }
        node *new_node = create_node(&temp);
        int result = add_node(head, new_node);
        result == SUCCESS ? printf("Contact Added Successfully\n") : printf("Memory allocation failed\n");

        printf("Add another contact \"1\" or exit \'0\" : ");
        int option;
        scanf("%d", &option);
        getchar();

        if (option)
            add_contact(head);
        else
            return;
    }

    else
    {
        printf("Invalid Input! Adding new contact failed\n");
        return;
    }
}

void update_contact(node **head)
{
    char name[100];
    char new_name[100];

    char mail[255];
    char new_mail[255];

    char num[18];
    char new_num[18];

    node *temp = NULL;
    int update_option;
    int update_state;
    int option;
    int new_option;

    // validate user's choice from menu
    while (1)
    {
        printf("Enter an option for updating:\n1 => Update by name\n2 => Update by number\n3 => Update by email\n4 => Update all\n6 => Exit\n");
        scanf("%d", &update_option);
        getchar(); // cleans buffer
        if (update_option > 5 || update_option < 1)
        {
            printf("Invalid Option ! Please Choose From Menu\n");
        }
        else
        {
            break;
        }
    }

    if (*head == NULL)
    {
        printf("Empty List! Nothing to Update\n");
        return;
    }
    switch (update_option)
    {
    case 1:
    {
        option = get_valid_name(name, sizeof(name));
        if (option)
        {
            // grap the node to be updated
            temp = search_contacts_by_name(*head, name);

            if (temp != NULL)
            {

                // get the new name
                printf("Enter the new Data :- \n");
                new_option = get_valid_name(new_name, sizeof(new_name));
                if (new_option)
                {
                    strcpy(((Data *)temp->data)->contact_name, new_name);
                    update_state = SUCCESS;
                }
                else
                {
                    // user didn't want to try again to input a valid new_name
                    update_state = ABORTED;
                    break;
                }
            }
            else
            {
                update_state = NOT_FOUND;
            }
        }
        else
            // user didn't want to try again to input a valid name
            update_state = ABORTED;
    }
    break;

    case 2:
    {
        option = get_valid_phoneNum(num, sizeof(num));
        if (option)
        {
            // grap the node to be updated
            temp = search_contacts_by_phoneNum(*head, num);

            if (temp != NULL)
            {
                // get the new num

                printf("Enter the new Data :- \n");
                new_option = get_valid_phoneNum(new_num, sizeof(new_num));
                if (new_option)
                {
                    strcpy(((Data *)temp->data)->contact_phone[x], new_num);
                    update_state = SUCCESS;
                }
                else
                {
                    // user didn't want to try again to input a valid new_name
                    update_state = ABORTED;
                    break;
                }
            }
            else
            {
                update_state = NOT_FOUND;
            }
        }
        else
        {
            // user didn't want to try again to input a valid name
            update_state = ABORTED;
        }
    }
    break;

    case 3:
    {
        option = get_valid_email(mail, sizeof(mail));
        if (option)
        {
            // grap the node to be updated
            temp = search_contacts_by_email(*head, mail);

            if (temp != NULL)
            {

                printf("Enter the new Data :- \n");
                // get the new num
                new_option = get_valid_email(new_mail, sizeof(new_mail));
                if (new_option)
                {
                    strcpy(((Data *)temp->data)->contact_mail, new_mail);
                    update_state = SUCCESS;
                }
                else
                {
                    // user didn't want to try again to input a valid new_name
                    update_state = ABORTED;
                    break;
                }
            }
            else
            {
                update_state = NOT_FOUND;
            }
        }
        else
        {
            // user didn't want to try again to input a valid name
            update_state = ABORTED;
        }
    }
    break;

    case 4:
    {
        option = get_valid_name(name, sizeof(name));
        if (option)
        {
            // grap the node to be updated
            temp = search_contacts_by_name(*head, name);

            if (temp != NULL)
            {

                printf("Enter the new Data :- \n");
                // get the new data
                Data new_data;

                int new_name_check = get_valid_name(new_data.contact_name, sizeof(new_data.contact_name));
                int new_mail_check = get_valid_email(new_data.contact_mail, sizeof(new_data.contact_mail));

                printf("How many phone numbers to update (max 5)? ");
                scanf("%d", &new_data.phone_count);
                getchar(); // flush newline

                int new_phone_check = 1; // Assume true until any fail
                if (new_data.phone_count > 0 && new_data.phone_count <= 5)
                {
                    for (int i = 0; i < new_data.phone_count; i++)
                    {
                        printf("phone number %d: ", i + 1);
                        new_phone_check = get_valid_phoneNum(new_data.contact_phone[i], sizeof(new_data.contact_phone[i]));
                        if (!new_phone_check)
                        {
                            // if user refused to enter a valid number
                            break;
                        }
                    }
                }
                else
                {
                    printf("MAX 5 numbers ");
                    printf("\n");
                    new_phone_check = 0;
                }

                if (new_name_check && new_phone_check && new_mail_check)
                {
                    update_state = update_node(*head, temp, &new_data);
                }
                else
                {
                    // user didn't want to try again to input a valid data
                    update_state = ABORTED;
                    break;
                }
            }
            else
            {
                update_state = NOT_FOUND;
            }
        }
        else
        {
            // user didn't want to try again to input a valid name
            update_state = ABORTED;
        }
    }
    break;

    case 6:
    {
        printf("Exiting Update Contact...\n");
        return;
    }
    break;

    default:
        update_state = INVALID_OPTION;
        break;
    }

    switch (update_state)
    {
    case NOT_FOUND:
    {
        printf("No Such Contact!\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Update Contact...\n");
            return;
        }
        else
            update_contact(head);
    }
    break;
    case INVALID_OPTION:
    {
        printf("Invalid Option!\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Update Contact...\n");
            return;
        }
        else
            update_contact(head);
    }
    break;
    case ABORTED:
        printf("Updates Aborted\n");
        break;
    case SUCCESS:
        printf("Contact Updated Successfully\n");
        break;

    default:
        break;
    }
}

void delete_contact(node **head)
{
    int delete_state;
    int delete_option;
    int option;

    printf("======== Delete Contact ========\n");

    // validate user's choice from menu
    while (1)
    {
        printf("Enter an option for deleting:\n1 => Delete by name\n2 => Delete by email\n3 => Delete by phone number\n4 => Delete all\n5 => Exit\n");
        printf("Your choice: ");
        scanf("%d", &delete_option);
        getchar(); // cleans buffer
        if (delete_option > 5 || delete_option < 1)
        {
            printf("Invalid Option ! Please Choose From Menu\n");
        }
        else
        {
            break;
        }
    }

    if (*head == NULL)
    {
        printf("Empty List! Nothing to delete\n");
        return;
    }

    switch (delete_option)
    {
    case 1:
    {
        // validate user name
        char name_delete[200] = " ";

        option = get_valid_name(name_delete, sizeof(name_delete));
        if (option)
        {
            node *temp = search_contacts_by_name(*head, name_delete);
            delete_state = delete_node_by_key(head, temp);
            break;
        }
        else
        {
            delete_state = ABORTED;
        }
    }
    break;

    case 2:
    {

        char mail_delete[200];
        // validate user email
        option = get_valid_email(mail_delete, sizeof(mail_delete));
        if (option)
        { // validated
            node *temp = search_contacts_by_email(*head, mail_delete);
            delete_state = delete_node_by_key(head, temp);
            break;
        }
        else
        {
            delete_state = ABORTED;
        }
    }
    break;

    case 3:
    {
        char phone_delete[20];
        // validate user phone
        option = get_valid_phoneNum(phone_delete, sizeof(phone_delete));
        if (option)
        {
            node *temp = search_contacts_by_phoneNum(*head, phone_delete);
            if (temp != NULL)
            {
                // remove phone number
                int res = remove_phone_number((Data *)temp->data, phone_delete);
                if (res == SUCCESS)
                {
                    delete_state = SUCCESS;
                }
                else if (res == NOT_FOUND)
                {
                    delete_state = NOT_FOUND;
                }
                else
                {
                    printf("Failed to delete phone number.\n");
                }
            }
            if (((Data *)temp->data)->phone_count == 0)
            {
                printf("No phone numbers left for this contact.\n");
                delete_node_by_key(head, temp);
            }
        }
        else
        {
            delete_state = ABORTED;
        }
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
                printf("Exiting Delete Contact...\n");
            }
            else
            {
                // repeat only case 4
                printf("Invalid Option! Please Choose \"1\" to proceed or \"0\" to abort\n");
            }
        }
    }
    break;

    case 5:
    {
        printf("Exiting Delete Contact...\n");
        return;
    }

    default:
        delete_state = INVALID_OPTION;
        break;
    }

    switch (delete_state)
    {
    case NOT_FOUND:
    {
        printf("No Such Contact!\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Delete Contact...\n");
            return;
        }
        else
            delete_contact(head);
    }
    break;
    case INVALID_OPTION:
    {
        printf("Invalid Option!\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Delete Contact...\n");
            return;
        }
        else
            delete_contact(head);
    }
    break;
    case ABORTED:
        printf("Deletion Aborted\n");
        break;
    case SUCCESS:
        printf("Contact Deleted Successfully\n");
        break;

    default:
        break;
    }
}

void search_contact(node *head)
{
    char name[100];
    char num[18];
    char mail[255];
    int search_option;
    node *temp = NULL;
    int search_state;
    int option;

    printf("======== Search Contact ========\n");

    // validate user's choice from menu
    while (1)
    {
        printf("Choose an option for searching:\n1. Search by name\n2. Search by phone number\n3. Search by email\n4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &search_option);
        getchar();

        if (search_option > 4 || search_option < 1)
        {
            printf("Invalid Option ! Please Choose From Menu\n");
        }
        else
        {
            break;
        }
    }

    if (head == NULL)
    {
        printf("Empty List! Can't Search\n");
        return;
    }

    switch (search_option)
    {
    case 1:
    {
        option = get_valid_name(name, sizeof(name));
        if (option)
        {
            temp = search_contacts_by_name(head, name);

            if (temp != NULL) // successful search
                search_state = SUCCESS;
            else
                search_state = NOT_FOUND;

            break;
        }
        else
        {
            search_state = ABORTED;
        }
    }
    break;

    case 2:
    {
        option = get_valid_phoneNum(num, sizeof(num));
        if (option)
        {
            temp = search_contacts_by_phoneNum(head, num);

            if (temp != NULL) // successful search
                search_state = SUCCESS;
            else
                search_state = NOT_FOUND;

            break;
        }
        else
        {
            search_state = ABORTED;
        }
    }
    break;

    case 3:
    {
        option = get_valid_email(mail, sizeof(mail));
        if (option)
        {
            temp = search_contacts_by_email(head, mail);

            if (temp != NULL) // successful search
                search_state = SUCCESS;
            else
                search_state = NOT_FOUND;

            break;
        }
        else
        {
            search_state = ABORTED;
        }
    }
    break;

    case 4:
    {
        printf("Exiting search...\n");
        return;
    }

    default:
        search_state = INVALID_OPTION;
        break;
    }

    switch (search_state)
    {
    case NOT_FOUND:
    {
        printf("No Matching Contact!\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Search Contact...\n");
            return;
        }
        else
            search_contact(head);
    }
    break;
    case INVALID_OPTION:
    {
        printf("Invalid Option! Please Try Again\n");
        printf("Try again? [1 / 0] ");
        scanf("%d", &option);
        getchar();

        if (!option)
        {
            printf("Exiting Search Contact...\n");
            return;
        }
        else
            search_contact(head);
    }
    break;
    case ABORTED:
        printf("Search Aborted\n");
        printf("Exiting Search Contact...\n");
        break;
    case SUCCESS:
    {
        printf("Contact Found Successfully\n");
        display_contact(temp);
    }

    break;

    default:
        break;
    }
}
