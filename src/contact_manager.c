#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

int remove_phone_number(Data *contact, const char *number_to_delete) {
    int index = -1;
    for (int i = 0; i < contact->phone_count; i++) {
        if (strcmp(contact->contact_phone[i], number_to_delete) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) return NOT_FOUND;

    // Shift remaining numbers left
    for (int i = index; i < contact->phone_count - 1; i++) {
        strcpy(contact->contact_phone[i], contact->contact_phone[i + 1]);
    }
    contact->phone_count--;

    return SUCCESS;
}
int is_valid_domain(char *domain)
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

int valid_email(char *email)
{
    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(email);
    if (len > 0 && email[len - 1] == '\n')
        email[len - 1] = '\0';

    char *at = strchr(email, '@'); // find the first @ symbol
    if (!at || at == email)
        return 0; // incase @ is at first or doesnt exists

    char *dot = strrchr(email, '.'); // find the last . symbol
    if (!dot || dot < at || dot == email + strlen(email) - 1)
        return 0; // incase (. doesn't exist) OR (exist before @) OR (is the last symbol)

    // Split domain part
    char *domain = at + 1;
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

int contain_digits(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int contain_special_char(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!isalnum(str[i])) // doesn't contain letters or digits = is a special character
            return 1;
        i++;
    }
    return 0;
}

int valid_phone(char *num)
{

    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(num);
    if (len > 0 && num[len - 1] == '\n')
        num[len - 1] = '\0';

    int i = 0;
    while (num[i] != '\0')
    {
        if (!isdigit(num[i]) && num[i] != '+')
            return 0;
        i++;
    }
    if (strlen(num) > 17 && strlen(num) < 2)
        return 0;

    return 1;
}

int valid_name(char *name)
{

    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    if (contain_digits(name) || contain_special_char(name))
        return 0;
    else
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

    // validate user's choice from menu
    while (1)
    {
        printf("1 => Delete by name\n2 => Delete by email\n3 => Delete by phone number\n4 => Delete all\n");
        printf("Your choice: ");
        scanf("%d", &delete_option);
        getchar(); // cleans buffer
        if (delete_option > 4 || delete_option < 0)
        {
            printf("Invalid Option ! Please Choose From Menu\n");
        }
        else
        {
            break;
        }
    }

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

        // validate user name
        char name_delete[200] = " ";
        while (1)
        {
            printf("Enter the name : ");
            fgets(name_delete, sizeof(name_delete), stdin);
            if (!valid_name(name_delete))
            {
                printf("Invalid Name! Please Enter only letters\n");
            }
            else
            {
                break;
            }
        }
        node *temp = search_contacts_by_name(*head, name_delete);
        delete_state = delete_node_by_key(head, temp);
    }
    break;

    case 2:
    {
        // this will handle empty list for now, but this should be handled at main for better flow
        //  the user will not be allowed to choose anything but add while the list is empty
        if (*head == NULL)
        {
            delete_state = EMPTY_LIST;
            break;
        }

        char mail_delete[200];
        // validate user email
        while (1)
        {
            printf("Enter the email : ");
            fgets(mail_delete, sizeof(mail_delete), stdin);
            if (!valid_email(mail_delete))
            {
                printf("Invalid Email! Make sure to end your email with [@domainName.com]\n");
            }
            else
                break;
        }

        node *temp = search_contacts_by_email(*head, mail_delete);
        delete_state = delete_node_by_key(head, temp);
    }
    break;

    case 3:
    {
        // this will handle empty list for now, but this should be handled at main for better flow
        //  the user will not be allowed to choose anything but add while the list is empty
        if (*head == NULL)
        {
            delete_state = EMPTY_LIST;
            break;
        }
        char phone_delete[20];
        // validate user phone
        while (1)
        {
            printf("Enter the phone : ");
            fgets(phone_delete, sizeof(phone_delete), stdin);
            if (!valid_phone(phone_delete))
            {
                printf("Invalid phone number! Please Enter digits only\n");
            }
            else
                break;
        }

        node *temp = search_contacts_by_phoneNum(*head, phone_delete);
if (temp != NULL) {
    Data *contact = (Data *)temp->data;
    if (remove_phone_number(contact, phone_delete) == SUCCESS) {
        printf("Phone number removed from contact.\n");

        // Optional: If contact has no more numbers, delete the node
        if (contact->phone_count == 0) {
            delete_node_by_key(head, temp);
            printf("No more phone numbers. Contact deleted.\n");
        }

        delete_state = SUCCESS;
    } else {
        delete_state = NOT_FOUND;
    }
} else {
    delete_state = NOT_FOUND;
}
    }
    break;

    case 4:
    {
        // this will handle empty list for now, but this should be handled at main for better flow
        //  the user will not be allowed to choose anything but add while the list is empty
        if (*head == NULL)
        {
            delete_state = EMPTY_LIST;
            break;
        }
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
        delete_state = INVALID_OPTION;
        break;
    }

    switch (delete_state)
    {
    case EMPTY_LIST:
        printf("Empty List! Nothing to delete\n");
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

void search_contacts(node *head)
{
    char contact_name[100];
    char num[18];
    int op;
    int found = 0;
    printf("Choose an option:\n1 for searching by name\n2 for searching by number\n");
    scanf("%d", &op);
    getchar();
    node *i = head;

    switch (op)
    {
    case 1:
        printf("Enter the name:\n");
        fgets(contact_name, sizeof(contact_name), stdin);
        contact_name[strcspn(contact_name, "\n")] = '\0';
        while (i != NULL)
        {
            Data *c = (Data *)i->data;
            if (strcmp(c->contact_name, contact_name) == 0)
            {
                printf("Contact found\n");
                printf("Name  : %s\n", c->contact_name);
                printf("E-mail: %s\n", c->contact_mail);
                printf("Number: %s\n", c->contact_phone);
                printf("------------------------\n");
                found = 1;
            }
            i = i->next;
        }
        if (!found)
            printf("No matching contacts\n");
        break;
    case 2:
        printf("Enter the number:\n");
        scanf("%s", &num);
        while (i != NULL)
        {
            Data *c = (Data *)i->data;
            if (strcmp(c->contact_phone, num) == 0)
            {
                printf("Contact found\n");
                printf("Name  : %s\n", c->contact_name);
                printf("E-mail: %s\n", c->contact_mail);
                printf("Number: %s\n", c->contact_phone);
                printf("------------------------\n");
                found = 1;
            }
            i = i->next;
        }
        if (!found)
            printf("No matching contacts\n");
        break;
    default:
        printf("Invalid option\n");
        return;
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
        for (int i = 0; i < node_data->phone_count; i++) {
    printf("   Number %d: %s\n", i + 1, node_data->contact_phone[i]);
}
        printf("------------------------\n");
        i = i->next;
    }
}

int add_contact(node **head)
{
    Data temp;

    printf("====== ADD A CONTACT ======\n");

    while (1)
    {
        printf("Please enter the name: ");
        scanf("%s", temp.contact_name);
        if (valid_name(temp.contact_name))
            break;
        else
            printf("Invalid name. Please use only letters.\n");
    }

    // Validate phone
while (1)
    {printf("How many numbers to add (max 5)? ");
scanf("%d", &temp.phone_count);
getchar(); // flush

for (int i = 0; i < temp.phone_count; i++) {
    printf("Enter phone number %d: ", i + 1);
    fgets(temp.contact_phone[i], sizeof(temp.contact_phone[i]), stdin);
    temp.contact_phone[i][strcspn(temp.contact_phone[i], "\n")] = '\0';

    if (!valid_phone(temp.contact_phone[i])) {
        printf("Invalid phone number format!\n");
        i--; // retry
    }
}
  break ;  }

    // Check for duplicates
    if (!check_duplicates_by_phoneNum(*head, &temp))
    {
        return 0; // Duplicate found
    }


    while (1)
    {
        printf("Please enter the email: ");
        scanf("%s", temp.contact_mail);
        if (valid_email(temp.contact_mail))
            break;
        else
            printf("Invalid email. Must end with valid domain like '@gmail.com'\n");
    }

 
    node *new_node = create_node(&temp);
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    int result = add_node(head, new_node);
    return result == SUCCESS ? 1 : 0;
}

void update(node *head)
{
    char name[100];
    char mail[255];
    char num[18];
    int found = 0;
    node *i = head;
    int x;
    printf("Enter an option for updating:\n1. Update by name\n2. Update by number\n3. Update by email");
    scanf("%d", &x);
    getchar();

    switch (x)
    {
    case 1:
    {
        printf("Enter the contact name:\n");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        while (i != NULL)
        {
            Data *d = (Data *)i->data;
            if (strcmp(d->contact_name, name) == 0)
            {
                found = 1;
                int op;
                printf("Contact found\n");

                while (1)
                {

                    printf("Enter an option for updating:\n1. Update phone number\n2. Update email\n");
                    scanf("%d", &op);
                    getchar();

                    switch (op)
                    {
                    case 1:
                    {
                        char temp_phone[30];
                        while (1)
                        {
                            printf("Enter the new number:\n");
                            fgets(temp_phone, sizeof(temp_phone), stdin);
                            temp_phone[strcspn(temp_phone, "\n")] = '\0';

                            if (!valid_phone(temp_phone))
                                printf("Invalid number.Try again\n");

                            else
                            {
                                strcpy(d->contact_phone, temp_phone);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        char temp_mail[200];
                        while (1)
                        {
                            printf("Enter the new email:\n");
                            fgets(temp_mail, sizeof(temp_mail), stdin);
                            temp_mail[strcspn(temp_mail, "\n")] = '\0';

                            if (!valid_email(temp_mail))
                                printf("Invalid Email. Try again\n");

                            else
                            {
                                strcpy(d->contact_mail, temp_mail);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }

                    default:
                        printf("Invalid input. Enter a valid option\n");
                        break;
                    }
                    break;
                }
                break;
            }
            i = i->next;
        }

        if (!found)
            printf("Contact name not found.\n");
        break;
    }
    case 2:
    {

        printf("Enter the contact number:\n");
        getchar();
        fgets(num, sizeof(num), stdin);
        name[strcspn(name, "\n")] = '\0';

        while (i != NULL)
        {
            Data *d = (Data *)i->data;
            if (strcmp(d->contact_phone, num) == 0)
            {
                found = 1;
                int op;
                printf("Contact found\n");

                while (1)
                {

                    printf("Enter an option for updating:\n1. Update name\n2. Update email\n");
                    scanf("%d", &op);
                    getchar();

                    switch (op)
                    {
                    case 1:
                    {
                        char temp_name[100];
                        while (1)
                        {
                            printf("Enter the new name:\n");
                            fgets(temp_name, sizeof(temp_name), stdin);
                            temp_name[strcspn(temp_name, "\n")] = '\0';

                            if (!valid_name(temp_name))

                                printf("Invalid number.Try again\n");

                            else
                            {
                                strcpy(d->contact_name, temp_name);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }

                    case 2:
                    {
                        char temp_mail[200];
                        while (1)
                        {
                            printf("Enter the new email:\n");
                            fgets(temp_mail, sizeof(temp_mail), stdin);
                            temp_mail[strcspn(temp_mail, "\n")] = '\0';

                            if (!valid_email(temp_mail))

                                printf("Invalid Email. Try again\n");

                            else
                            {
                                strcpy(d->contact_mail, temp_mail);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }

                    default:
                        printf("Invalid input. Enter a valid option\n");
                        break;
                    }
                    break;
                }
                break;
            }
            i = i->next;
        }

        if (!found)
            printf("Contact number not found.\n");
        break;
    }
    case 3:
    {

        printf("Enter the contact email:\n");
        getchar();
        fgets(mail, sizeof(mail), stdin);
        mail[strcspn(mail, "\n")] = '\0';
        i = head;

        while (i != NULL)
        {
            Data *d = (Data *)i->data;
            if (strcmp(d->contact_mail, mail) == 0)
            {
                found = 1;
                int op;
                printf("Contact found\n");

                while (1)
                {
                    printf("Enter an option for updating:\n1. Update name\n2. Update phone number\n");
                    scanf("%d", &op);
                    getchar();
                    switch (op)
                    {

                    case 1:
                    {
                        char temp_name[30];
                        while (1)
                        {
                            printf("Enter the new name:\n");
                            fgets(temp_name, sizeof(temp_name), stdin);
                            temp_name[strcspn(temp_name, "\n")] = '\0';

                            if (!valid_name(temp_name))
                                printf("Invalid number.Try again\n");
                            else
                            {
                                strcpy(d->contact_name, temp_name);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        char temp_phone[30];
                        while (1)
                        {
                            printf("Enter the new number:\n");
                            fgets(temp_phone, sizeof(temp_phone), stdin);
                            temp_phone[strcspn(temp_phone, "\n")] = '\0';

                            if (!valid_phone(temp_phone))
                                printf("Invalid number.Try again\n");
                            else
                            {
                                strcpy(d->contact_phone, temp_phone);
                                printf("Contact updated\n");
                                break;
                            }
                        }
                        break;
                    }
                    default:
                        printf("Invalid input. Enter a valid option\n");
                        break;
                    }
                    break;
                }
                break;
            }
            i = i->next;
        }
        if (!found)
            printf("Contact email not found.\n");
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }
}
