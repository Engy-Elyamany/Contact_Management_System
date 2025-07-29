#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

//intial declaration of contact_data
typedef struct Data
{
    char contact_name[200];
    char contact_mail[200];
    char contact_phone[18]; // max phone number length is 17
} Data;

void display_list(node *head); 
void sort_list_by_name( node *head, int count);
int check_duplicates_by_phoneNum(node *head, Data *added_node);

#endif