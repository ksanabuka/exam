#include <stdlib.h>
#include <stdio.h>


int isSpace(char c)
{
    return (c == 32 || (c >= 9 && c <= 13)) ? 1 : 0;
}

int newLen(char *s)
{
    int i = 0;
    while (s[i])
        i++;

    i--;

    while (isSpace(s[i]))
        i--;

    return i; 
}



int wordC(char *s)
{
    int wc = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        while (isSpace((s[i])) && s[i])
            i++;
        if (!(isSpace(s[i])) && s[i])
            wc++;
        while (!(isSpace(s[i])) && s[i])
            i++;
    }
    return wc;
}

int wl(char * s, int pos)
{
    int i = 0;
    while (s[pos] && isSpace(s[pos]))
        pos++;
    while (s[pos] && !(isSpace(s[pos])))
    {
        pos++;
        i++;   
    }
    return i;
}

char *mystrsub(char *s, int pos)
{
    int len = wl(s, pos);

    char * res;
    if (!(res = (char*)malloc(sizeof(char)  * (len + 1))))
        return 0;
    res[len] = '\0';

    while (s[pos] && isSpace(s[pos]))
        pos++;
    
    int i = 0;
    while (s[pos] && !(isSpace(s[pos])))
    {
        res[i] = s[pos];
        i++;
        pos++;
    }
    return res;
}
int passW(char *s, int pos)
{

    while (s[pos] && isSpace(s[pos]))
        pos++;
    
    while (s[pos] && !(isSpace(s[pos])))
    {
        pos++;
    }
    
    return pos;
}

char **ft_split(char *str)
{
    int wc = wordC(str);

    char ** res;

    if (!(res = (char**)malloc(sizeof(char *) * (wc + 1))))
        return 0;
    res[wc] = 0;

    int i = 0;
    int j = 0;
    while (wc--)
    {
        char *sub = mystrsub(&str[i], i);
        printf("%s\n", sub);
        res[j] = sub;
        i = passW(str, i);
        j++;
    }
    return res;
}





// char ** ft_split(char * s)
// {

// }


int main(int argc, char **argv)
{
    argc = 0;
	char **new;
	int		i;

	i = 0;
	new  = ft_split(argv[1]);
	while (new[i] != '\0')
	{
		printf("%s\n", new[i]);
			i++;
	}

}