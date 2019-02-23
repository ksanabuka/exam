#include <unistd.h>
int myatoi( char * s)
{
    while (*s && (*s == 32 || (*s >= 9 && *s <= 13)))
    {
        s++;
    }

    int neg = (*s == '-') ? -1 : 1;

    (*s == '-' || *s == '+') ? s++ : s;

    long res = 0;
    while (*s >= '0' && *s <= '9' && *s)
    {
        res = res * 10 + *s - '0';
        s++;
    }
    return ((int)res * neg);
}

void myputnbr(int n)
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
            myputnbr(n/10);
        
        char tmp = n % 10 + '0';
        write(1, &tmp, 1);
    }
}

int operation(char * s1, char *sign, char *s2 )
{
    int res = 0;

    if (*sign == '+')
    {
        res = myatoi(s1) + myatoi(s2);
       
    }
    if (*sign == '-')
    {
        res = myatoi(s1) - myatoi(s2);
       
    }
    if (*sign == '*')
    {
        res = myatoi(s1) * myatoi(s2);
       
    }
    if (*sign == '/')
    {
        res = myatoi(s1) / myatoi(s2);
       
    }
    if (*sign == '%')
    {
        res = myatoi(s1) % myatoi(s2);
       
    }
    return res;

}

#include <stdio.h>
int main (int ac, char ** av)
{
    if (ac != 4)
    {
        write(1, "\n", 1);
        return 0;
    }

    myputnbr(operation(av[1],  av[2], av[3]));
    write(1, "\n", 1);

    return 0;

}






