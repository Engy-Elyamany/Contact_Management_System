#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

void test_add_contact(node **head)
{
    Data data = {" "};

    printf("   Name  :");
    scanf("%s", data.contact_name);
    printf("   E-mail: ");
    scanf("%s", data.contact_mail);
    printf("   Number: ");
    scanf("%s", data.contact_phone);
    printf("------------------------\n");
    if (check_duplicates_by_phoneNum(*head, &data))
    {
        add_node(head, create_node(&data));
    }
}

void main()
{
    node *head = NULL;

   
    Data d1 = {"ahmed", "A@gmail.com", "+27020010996"};
    Data d2 = {"khaled", "Ali@gmail.com", "+8529999996"};
    Data d3 = {"sara", "sara@gmail.com", "+20277740"};
    // Data d4 = {"hala", "hala@gmail.com", "+203330"};
    // Data d5 = {"hossam", "hos@gmail.com", "+20109986"};
    // Data d6 = {"aahmed", "hosin@gmail.com", "+20109986"};
    add_node(&head, create_node(&d1));
    add_node(&head, create_node(&d2));
    add_node(&head, create_node(&d3));
    // add_node(&head, create_node(&d4));
    // add_node(&head, create_node(&d5));
    // add_node(&head, create_node(&d6));

    display_list(head);
    delete_contact(&head);
    display_list(head);
   
    // Data dd = {"Ali", "Ali@gggg", "+2065555"};
    // node *s = search_list_by_key(head, &d3);
    // update_node(head, s, &dd);
    // delete_node_by_key(&head,&d6);
    // display_list(head);

    // printf("Test1: test (add,create, display) function\n");
    // display_list(head);
    // printf("Test1 successful\n");
    // printf("------------------------------------------------\n");

    // printf("Test2: (update) second node content with d3 content\n");
    // node * res = search_contacts_by_name(head,"khaled");
    // update_node(head,res,&d3);
    // display_list(head);
    // printf("Test2 successful\n");

    // printf("------------------------------------------------\n");

    // printf("Test3: (delete) third node \n");
    // node *de = search_list_by_key(head, &d3);
    // delete_node_by_key(&head,&d3); //sara
    // display_list(head);
    // printf("Test3 successful\n");

    // printf("------------------------------------------------\n");

    // printf("Test4: (business - sort)  \n");
    // sort_list_by_name(head,count_nodes(head));
    // display_list(head); //aahmed to the top
    // printf("Test4 successful\n");

    // printf("------------------------------------------------\n");

    // printf("Test5: (business - duplicates)  \n");
    // int check = check_duplicates_by_phoneNum(head,&d6); //check = 0 => it's a duplicate
    // if(!check) printf("IT's a duplicate \n");
    // else printf("IT's a duplicate \n");
    // printf("Test5 successful\n");

    // printf("------------------------------------------------\n");

    // printf("Test6: (destroy)  \n");
    // destroy_list(&head);
    // display_list(head);
    // printf("Test6 successful\n");

    // printf("------------------------------------------------\n");

    // printf("Test7: (search - business)  \n");
    // display_list(head);
    // delete_node_by_key(&head, &d3);
    // printf("Test6 successful\n");

    // printf("------------------------------------------------\n");
}