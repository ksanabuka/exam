#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void myputn(int n)
{
    if (n == -2147483648)
{
        write(1, "-2147483648", 11);
        return ; 
}
    else 
    {
        if (n < 0)
        {
            write(1, "-",1);
            n=-n;
        }
        if (n > 9)
            myputn(n/10);

        char d = n % 10 + '0';
        write(1, &d, 1);
    }
}

int myatoi(char *s)
{
    long res = 0;
    while (*s == 32 && (*s >= 9 && *s <= 13))
        s++;
    int sign = (*s == '-') ? -1 : 1;

    (*s == '-' || *s == '+') ? s++ : s;

    while (*s && (*s >= '0' && *s <= '9'))
    {
        res = res * 10 + *s - '0';
        s++;
    }
    return (int)res * sign; 
}

void fprime(int n)
{
    int i = 2;
    int flag = 0;
    int res = n;
    while (i <= res)
    {
        if (n % i == 0)
        {
            if (flag == 1)
            {
                write(1, "*", 1);

            }
            myputn(i);
            flag = 1;
            n = n / i;
        } 
        else 
            i++; 
    }
}

int main (int ac, char ** av)
{
    

    if (ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }

    if (myatoi(av[1]) == 1)
    {
        write(1, "1\n", 2);
        return 0;
    }

    fprime(myatoi(av[1]));
    write(1, "\n", 1);

    return 0;
}