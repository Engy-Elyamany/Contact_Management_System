#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

node *search_list_by_key(node *head, void *desired_data)
{
    /*

    search logic - Malak's implementation

    */

    node *temp = head;
    while (temp->data != desired_data)
    {
        temp = temp->next;
    }
    return temp;
}

void main()
{
    node *head = NULL;

    Data d1 = {"ahmed", "A@gmail.com", "+27020010996"};
    Data d2 = {"khaled", "Ali@gmail.com", "+8529999996"};
    Data d3 = {"sara", "sara@gmail.com", "+20277740"};
    Data d4 = {"hala", "hala@gmail.com", "+203330"};
    Data d5 = {"hossam", "hos@gmail.com", "+20109986"};
    Data d6 = {"aahmed", "hosin@gmail.com", "+20109986"};
    add_node(&head, create_node(&d1));
    add_node(&head, create_node(&d2));
    add_node(&head, create_node(&d3));
    add_node(&head, create_node(&d4));
    add_node(&head, create_node(&d5));
    add_node(&head, create_node(&d6));

    printf("Test1: test (add,create, display) function\n");
    display_list(head);
    printf("Test1 successful\n");
    printf("------------------------------------------------\n");

    printf("Test2: (update) second node content with d4 content\n");
    node *desired = search_list_by_key(head, &d2);
    update_node(head, desired, &d4);
    display_list(head);
    printf("Test2 successful\n");

    printf("------------------------------------------------\n");

    printf("Test3: (delete) third node \n");
    node *de = search_list_by_key(head, &d3);
    delete_node_by_key(&head,&d3); //sara
    display_list(head);
    printf("Test3 successful\n");

    printf("------------------------------------------------\n");

    printf("Test4: (business - sort)  \n");
    sort_list_by_name(head,count_nodes(head));
    display_list(head); //aahmed to the top 
    printf("Test4 successful\n");

    printf("------------------------------------------------\n");

    printf("Test5: (business - duplicates)  \n");
    int check = check_duplicates_by_phoneNum(head,&d6); //check = 0 => it's a duplicate
    if(!check) printf("IT's a duplicate \n");
    else printf("IT's a duplicate \n");
    printf("Test5 successful\n");

    printf("------------------------------------------------\n");

    printf("Test6: (destroy)  \n");
    destroy_list(&head);
    display_list(head);
    printf("Test6 successful\n");

    printf("------------------------------------------------\n");
}