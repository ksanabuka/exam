
#include <stdio.h>
#include <stdlib.h>

void strRev(char *s)
{
    
    int i = 0;

    while (s[i] != '\0')
        i++;

    int half = i / 2;

    i--;
    int beg = 0;
    char tmp;
    
    
        while (half)
        {
            tmp = s[beg];
            s[beg] = s[i];
            s[i] = tmp;
            half--;
            beg++;
            i--;
        }
}
 

char	*ft_itoa_base(int n, int base)
{


    char * res;
    if (!(res = (char*)malloc(sizeof(char) * 34)))
        return 0;

    if (n == 0)
    {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    if (n == -2147483648)
    {
        res = "-2147483648\0";
        return res;
    }
    int i = 0;
    int neg = 0;

    if (n < 0)
    {
        neg = 1;
        n = -n;
    }
    

    int d = 0;
    while (n > 0)
    {
        d = (n % base);
        res[i] = (d >= 0 && d <= 9) ? d + '0': d + 'A' - 10;
        i++;
        n = n / base;
    }
   
    if (neg)
    {
        res[i] = '-';
        i++;
        res[i] = '\0';
    }
    else 
        res[i] = '\0';

    strRev(res);

    return res;

}



int main (int ac, char ** av)
{
    if (ac != 3)
        return 0;

    printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
    return 0;
}