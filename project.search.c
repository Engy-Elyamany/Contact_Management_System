#include "Linked_List.h"
#include "contact_manager.h"
void search(struct node *head)
{
    char name[100];
    char num[18];
    char mail[255];
    int op;
    node *i;
    int found;

    while (1) {
        found = 0;
        i = head;

        printf("Choose an option for searching:\n1. Searching by name\n2. Searching by number\n3. Searching by email\n4. Exit");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            printf("Enter the name:\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            while (i != NULL)
            {
                Data *c = (Data *)i->data;
                if (strcmp(c->contact_name, name) == 0)
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
            else
                return;
            break;

        case 2:
            printf("Enter the number:\n");
            fgets(num, sizeof(num), stdin);
            num[strcspn(num, "\n")] = '\0';

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
            else
                return;
            break;

        case 3:
            printf("Enter the email:\n");
            fgets(mail, sizeof(mail), stdin);
            mail[strcspn(mail, "\n")] = '\0';

            while (i != NULL)
            {
                Data *c = (Data *)i->data;
                if (strcmp(c->contact_mail, mail) == 0)
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
            else
                return;
            break;
            case 4:
            { 
                printf("Exiting search...\n");
            return;
            }

        default:
            printf("Invalid option\n");
            break;
        }
    }
}
