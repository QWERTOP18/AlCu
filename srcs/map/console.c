#include "interface.h"

void	console_map(t_map *m)
{
	int	i;
	i = 0;
	while (i < m->height)
	{
		printf("line: %d\n", m->lines[i]);

		i++;
	}
	printf("height: %d\n", m->height);
	printf("errno: %d\n", m->errno);
	return ;
}
