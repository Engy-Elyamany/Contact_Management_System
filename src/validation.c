#include "../include/validation.h"

int is_valid_domain(char *domain)
{
    for (int i = 0; valid_domains[i] != NULL; i++)
    {
        if (strcmp(domain, valid_domains[i]) == 0)
        {
            return 1; // Domain found
        }
    }
    return 0; // Domain not found
}

int valid_email(char *email)
{
    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(email);
    if (len > 0 && email[len - 1] == '\n')
        email[len - 1] = '\0';

    char *at = strchr(email, '@'); // find the first @ symbol
    if (!at || at == email)
        return 0; // incase @ is at first or doesnt exists

    char *dot = strrchr(email, '.'); // find the last . symbol
    if (!dot || dot < at || dot == email + strlen(email) - 1)
        return 0; // incase (. doesn't exist) OR (exist before @) OR (is the last symbol)

    // Split domain part
    char *domain = at + 1;
    if (!is_valid_domain(domain))
        return 0; // check last part

    // Check for invalid characters
    for (int i = 0; email[i] != '\0'; i++)
    {
        // allows only letters, numbers, dots, hyphens, underscores, and @ symbol
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '-' && email[i] != '_' && email[i] != '@')
        {
            return 0;
        }
    }
    // if passed all previous conditions, then it must be a valid email
    return 1;
}

int contain_digits(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int contain_special_char(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
          if (!isalnum(str[i]) && str[i] != ' ') // doesn't contain letters or digits = is a special character
            return 1;
        i++;
    }
    return 0;
}

int valid_phone(char *num)
{

    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(num);
    if (len > 0 && num[len - 1] == '\n')
        num[len - 1] = '\0';

    int i = 0;
    while (num[i] != '\0')
    {
        if (!isdigit(num[i]) && num[i] != '+')
            return 0;
        i++;
    }

    if (strlen(num) < 3 || strlen(num) > 17 )
        return 0;

    return 1;
}

int valid_name(char *name)
{

    // newline stripping (remove '\n' at the end of the user input because we're using fgets) before checking
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';
        //check if name is empty
 if (strlen(name) == 0)
    {
        printf("Name cannot be empty.\n");
        return 0;
    }
    //check if name is only spaces
     int only_spaces = 1;
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isspace((unsigned char)name[i])) {
            only_spaces = 0;
            break;
        }
    }
    if (only_spaces) {
        printf("Name cannot be empty or only spaces.\n");
        return 0;
    }

    if (contain_digits(name) || contain_special_char(name))
        return 0;
    else
        return 1;
}

//input, validate, try_again
int get_valid_name(char *name, int size)
{
    while (1)
    {
        int option;
        printf("Enter the name : ");
        fgets(name, size, stdin);
        if (!valid_name(name))
        {
            printf("Invalid Name! Please Enter only letters\n");
            printf("Try again? [1 / 0] ");
            scanf("%d", &option);
            getchar();

            if (!option)
                return 0;
        }
        else
            return 1; // valid name
    }
}

int get_valid_phoneNum(char *number, int size)
{
    while (1)
    {
        int option;
        printf("Enter the phone : ");
        fgets(number, size, stdin);
        if (!valid_phone(number))
        {
            printf("Invalid phone number! Please Enter digits only\n");
            printf("Try again? [1 / 0] ");
            scanf("%d", &option);
            getchar();

            if (!option)
                return 0;
        }
        else
            return 1; // valid name
    }
}

int get_valid_email(char *mail, int size)
{
    while (1)
    {
        int option;
        printf("Enter the email : ");
        fgets(mail, size, stdin);
        if (!valid_email(mail))
        {
            printf("Invalid Email! Make sure to end your email with [@domainName.com]\n");
            printf("Try again? [1 / 0] ");
            scanf("%d", &option);
            getchar();

            if (!option)
                return 0;
        }
        else
            return 1; // valid name
    }
}

