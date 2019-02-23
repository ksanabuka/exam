#include<stdio.h>

char    *ft_strrev(char *str)
{
    char tmp;
    int i = 0;

    while (str[i])
    {
        i++;
    }

    int len = i / 2;
    int start = 0;
    int end = i - 1;
    while (len--)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
    }
    return str;
}

int main (int ac, char ** av)
{
    if (ac == 2)
    {
        printf("%s\n", ft_strrev(av[1]));
    }
    return 0;
}