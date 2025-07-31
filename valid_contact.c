#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int valid_name(char *name)
{
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    if (contain_digits(name))
        return 0;
    else
        return 1;
}

int valid_email(char *e)
{
    int index = -1;
    for (int i = 0; i < strlen(e); i++)
    {
        if (e[i] == '@')
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;

    char v[100];
    int j = 0;
    for (int i = index; i < strlen(e); i++)
    {
        v[j++] = e[i];
    }
    v[j] = '\0';

    if (strcmp(v, "@gmail.com") == 0)
        return 1;
    else
        return 0;
}

int valid_phone(char *num)
{
    int i = 0;
    while (num[i] != '\0')
    {
        if (!isdigit(num[i]))
            return 0;
        i++;
    }
    if (strlen(num) > 17&&strlen(num)<2)
        return 0;
    return 1;
}
