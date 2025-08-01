#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <ctype.h>

// intial declaration of contact_data
typedef struct Data
{
    char contact_name[200];
    char contact_mail[200];
    char contact_phone[5][18]; // 5 strings, each up to 17 digits
    int phone_count;    // number of phone numbers stored
} Data;

// array of strings to the valid domains
static char *valid_domains[] = {
    "gmail.com",
    "yahoo.com",
    "outlook.com",
    "hotmail.com",
    "protonmail.com",
    NULL};


//validation functions
int is_valid_domain( char *domain);
int valid_email( char *email);
int contain_digits(char *str);
int contain_special_char(char *str);
int valid_phone(char *num);
int valid_name(char *name);

//helper functions
int check_duplicates_by_phoneNum(node *head, Data *added_node);
node * search_contacts_by_name(node * head, char * name);
node *search_contacts_by_email(node *head, char *email);
node *search_contacts_by_phoneNum(node *head, char *phoneNum);

// main business logic functions
void sort_list_by_name( node *head, int count);
void delete_contact(node **head);
void search_contacts(node *head);
void display_list(node *head); 
int remove_phone_number(Data *contact, const char *number_to_delete) ;

int add_contact(node **head);

void update(node *head);


#endif
