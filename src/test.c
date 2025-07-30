#include "../include/Linked_List.h"
#include "../include/contact_manager.h"
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

   }