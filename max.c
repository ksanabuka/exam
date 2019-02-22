int		max(int* tab, unsigned int len)
{
    if (!len)
        return 0;

    int tmp;

    unsigned int i = 0;

    tmp = tab[i];

    while (i < len)
    {
        if (tab[i] > tmp)
        {
            tmp = tab[i];
            i++;
        }
        i++;
    }
    return tmp;
}

#include <stdio.h>
int main (void)
{
    int arr[6] = {-9, +8, -7};
    printf("%d\n", max(arr, 6));
}