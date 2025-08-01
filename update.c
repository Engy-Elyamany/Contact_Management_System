#include "Linked_List.h"
#include "contact_manager.h"

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

                            if (!valid_number(temp_phone))
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

                            if (!valid_number(temp_phone))
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