#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct Data
{
    char contact_name[200];
    char contact_mail[200];
    char contact_phone[5][18]; // max phone number length is 17
    int phone_count;
} Data;


//helper functions
int check_duplicates_by_phoneNum(node *head, Data *added_node);
node * search_contacts_by_name(node * head, char * name);
node *search_contacts_by_email(node *head, char *email);
node *search_contacts_by_phoneNum(node *head, char *phoneNum);
int remove_phone_number(Data *contact, const char *number_to_delete);


// main business logic functions
void sort_list_by_name( node *head, int count);
void display_list(node *head);
void add_contact(node **head);
void update_contact(node *head);
void delete_contact(node **head);
void search_contact(node *head);

#endif
