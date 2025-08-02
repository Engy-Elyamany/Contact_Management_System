#include "../include/Linked_List.h"
#include "../include/contact_manager.h"
#include "../include/validation.h"

int main()
{

    node *head = NULL;

    while (1)
    {
        int choice;
        printf("\033[35m");
        printf("\n======= CONTACT MANAGER =======\n");
        printf("1. Add Contact\n");
        printf("2. Update Contact\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline
        printf("\033[38;2;255;182;193m");
        switch (choice)
        {
        case 1:
            add_contact(&head);
            break;
        case 2:
            update_contact(&head);
            break;
        case 3:
            search_contact(head);
            break;
        case 4:
            delete_contact(&head);
        case 5:
            sort_list_by_name(head, count_nodes(head));
            display_list(head);
            break;

        case 6:
            destroy_list(&head);
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid Choice. Try Again.\n");
        }
    }

    return 0;
}
