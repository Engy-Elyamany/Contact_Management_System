
#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// array of strings to the valid domains
static char *valid_domains[] = {
    "email.com",
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

int get_valid_name(char *name, int size);
int get_valid_phoneNum(char *number, int size);
int get_valid_email(char *mail, int size);

#endif
