#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <ctype.h>

// intial declaration of contact_data
typedef struct Data
{
    char contact_name[200];
    char contact_mail[200];
    char contact_phone[18]; // max phone number length is 17
} Data;

// array of strings to the valid domains
static char *valid_domains[] = {
    "gmail.com",
    "yahoo.com",
    "outlook.com",
    "hotmail.com",
    "protonmail.com",
    NULL};

int check_duplicates_by_phoneNum(node *head, Data *added_node);
node * search_contacts_by_name(node * head, char * name);
node *search_contacts_by_email(node *head, char *email);
node *search_contacts_by_phoneNum(node *head, char *phoneNum);

void delete_contact(node **head);
void sort_list_by_name( node *head, int count);
void search_contacts(node *head);
void display_list(node *head); 

int is_valid_domain(const char *domain);
int is_valid_email(const char *email);
int add_node(node **head, node *added_node);

#endif