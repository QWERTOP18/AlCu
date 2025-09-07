#include "interface.h"

void	console_map(t_map *m)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->lines[i])
		{
			printf("| ");
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}
