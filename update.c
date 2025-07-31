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

            if (op == 1) {
                char temp_phone[30];
                printf("Enter the new number:\n");
                fgets(temp_phone, sizeof(temp_phone), stdin);
                temp_phone[strcspn(temp_phone, "\n")] = '\0';

                int is_valid = 1;
                int p = 0;
                while (temp_phone[p] != '\0') {
                    if (!isdigit(temp_phone[p])) {
                        is_valid = 0;
                        break;
                    }
                    p++;
                }

                if (!is_valid) {
                    printf("Invalid number (must contain digits only)\n");
                } else {
                    strcpy(d->contact_phone, temp_phone);
                    printf("Contact updated\n");
                }

            } else if (op == 2) {
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
            } else {
                printf("Invalid option\n");
            }

            break; 
        }
        i = i->next;
    }

    if (!found)
        printf("Contact name not found\n");
}
