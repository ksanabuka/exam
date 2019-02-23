#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    while (src[i])
        i++;
    
    char * res = (char *)malloc(sizeof(char) * (i + 1));

    if (!res)
        return 0;

    res[i] = '\0';
    i--;
    while (i >= 0)
    {
        res[i] = src[i];
        i--;
    }
    return res;
}

#include<stdio.h>

int main(int ac, char ** av)
{
    if (ac == 2)
        printf("%s\n", ft_strdup(av[1]));
    return 0;
}