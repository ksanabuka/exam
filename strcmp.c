int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 && *s2 && (*s1 == *s2))
        {
            s1++;
            s2++;
        }
    }
    if (*s1 == '\0' && *s2 == '\0')
            return 0;
    else 
            return *s1 - *s2;
}

#include <stdio.h>
#include <string.h>

int main (int ac, char ** av)
{
    if (ac == 3)
    {
        printf("%d\n", ft_strcmp(av[1], av[2]));
        printf("%d\n", strcmp(av[1], av[2]));

        return 0;
    }
    return 0;
}