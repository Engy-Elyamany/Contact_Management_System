#include "../include/Linked_List.h"
#include "../include/contact_manager.h"

void main()
{
    node *head = NULL;

    Data d1 = {"ahmed", "A@gmail.com", "+27020010996"};
    node *n1 = create_node(&d1);
    head = n1;
     
    Data d2 = {"ali", "Ali@gmail.com", "+8529999996"};
    node * n2 = n1->next = create_node(&d2);
    n2->prev = n1;

     
    Data d3 = {"sara", "sara@gmail.com", "+20277740"};
    node * n3 = n1->next->next = create_node(&d3);
    n3->prev = n2;

    print_content(head);
    delete_node_by_key(&head,&d2);
    printf("--------------------------------------------------\n");
    print_content(head);
}