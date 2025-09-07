/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:45:45 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 20:01:33 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int	add_line(t_map *map, int line_value)
{
	if (map->height >= MAX_MAP_HEIGHT)
	{
		return (ERR_MAP_TOO_LARGE);
	}
	if (line_value < 0 || line_value > MAX_LINE_VALUE)
	{
		return (ERR_INVALID_INPUT);
	}
	map->lines[map->height++] = line_value;
	return (0);
}

static void	map_zero(t_map *map)
{
	int	i;

	i = 0;
	while (i < MAX_MAP_HEIGHT)
	{
		map->should_ai_take_last[i] = false;
		map->lines[i++] = 0;
	}
	map->max_width = 0;
	map->height = 0;
	map->winner = PLAYER_NONE;
	map->errno = 0;
}

t_map	*map_factory(void)
{
	char	*line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map_zero(map);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		map->errno |= add_line(map, lib_atoi(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	compute_should_ai_take_last(map);
	return (map);
}
