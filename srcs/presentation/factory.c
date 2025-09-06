/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:45:45 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/06 14:05:59 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int	add_line(t_map *map, int line_value)
{


	if (line_value < 0)
	{
		map->errno |= ERR_INVALID_INPUT;
	}
	map->lines[map->height++] = line_value;
}

t_map	*map_factory(void)
{
	char	*line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	line = get_next_line(STDIN_FILENO);
	printf("%s", line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(STDIN_FILENO);
		add_line(map, lib_atoi(line));
	}
	return (NULL);
}
