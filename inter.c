#include<unistd.h>

void myputc(char c)
{
	char tmp = c;
	write(1, &tmp, 1 );
}

int was(char * s, char c, int pos)
{
	int i = 0;
	if (pos == 0)
		return -1;
	while (s[i] &&  i < pos)
	{
		if (s[i] == c)
			return i;
		else
			i++;
	}
	return -1;

}


int mylen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return i;
}

int main (int ac, char ** av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}


	int 	i = 0;


	while (av[1][i])
	{
	if  ( ( av[1][i] && (was(av[1], av[1][i], i) == -1)  && (was(av[2], av[1][i], mylen(av[2])) >= 0)))
	{
		myputc(av[1][i]);
		i++;
	}
	else
		i++;
	}

		myputc('\n');
		return 0;

}