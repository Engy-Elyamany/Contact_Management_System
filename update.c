#include "Linked_List.h"
#include "contact_manager.h"

void update(node *head) {
    char name[100];
    int found = 0;
    node *i = head;

    printf("Enter the contact name:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (i != NULL) {
        Data *d = (Data *)i->data;
        if (strcmp(d->contact_name, name) == 0) {
            found = 1;
            int op;
            printf("Contact found\n");
            printf("Enter an option for updating:\n1. Update phone number\n2. Update email\n");
            scanf("%d", &op);
            getchar();

switch (op) {
                case 1: {
                    char temp_phone[30];
                    printf("Enter the new number:\n");
                    fgets(temp_phone, sizeof(temp_phone), stdin);
                    temp_phone[strcspn(temp_phone, "\n")] = '\0';

                    if (!valid_number(temp_phone)) {
                        printf("Invalid number (must be digits only and up to 17 characters)\n");
                    } else {
                        strcpy(d->contact_phone, temp_phone);
                        printf("Contact updated\n");
                    }
                    break;
                }

                case 2: {
                    char temp_mail[200];
                    printf("Enter the new email:\n");
                    fgets(temp_mail, sizeof(temp_mail), stdin);
                    temp_mail[strcspn(temp_mail, "\n")] = '\0';

                    if (!valid_email(temp_mail)) {
                        printf("Invalid Email\n");
                    } else {
                        strcpy(d->contact_mail, temp_mail);
                        printf("Contact updated\n");
                    }
                    break;
                }

                default:
                    printf("Invalid option\n");
            }

            break;
        }
        i = i->next;
    }

    if (!found)
        printf("Contact name not found\n");
}
