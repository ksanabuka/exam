#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list * tmp;
	tmp = begin_list;
	int i = 0;
	if (tmp)
	{

	while(tmp->next != 0)
	{
		i++;
		tmp = tmp->next;
	}

	return (i + 1);
	}

	else
		return 0;
}