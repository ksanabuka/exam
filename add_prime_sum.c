
#include <unistd.h>

int myatoi(char * s)
{
    while ((*s == 32 || (*s >= 9 && *s <= 13)) && *s)
        s++;

    int neg = (*s == '-') ? -1 : 1;

    (*s == '-' || *s == '+') ? s++ : s;

    long res = 0;
    while ((*s>= '0' && *s <= '9') && *s)
    {
        res = res * 10 + *s - '0';
        s++;
    }

    return (int)res * neg;
}


int isPrime(int n)
{
    if (n == 1 || n == 0)
        return 0;
    
    int i = 2;
    
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
     
}

void putn(int n)
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
            write(1, "-", 1);
            n = -n;            
        }
        if (n > 9)
        {
            putn(n/10);
        }
        char tmp = n % 10 + '0';
        write(1, &tmp, 1);
    }
}




int add_prime(int n)
{
    if (n == 0 || n == 1)
        return 0;

    int i = 2;
    int res = 0;
    while ( i <= n)
    {
        res += (isPrime(i)) ? i : 0;
        i++; 
    }
    return res;
}

#include <stdio.h>
#include <stdlib.h>

int main (int ac, char ** av)
{
    if (ac != 2)
    {
        write(1, "0\n", 2);
        return 0;
    }

    if (myatoi(av[1]) < 0)
    {
        write(1, "0\n", 2);
        return 0;
    }

    putn(add_prime(myatoi(av[1])));
    write(1, "\n", 1);
    return 0;
}