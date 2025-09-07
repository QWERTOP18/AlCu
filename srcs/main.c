/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 23:58:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 14:42:29 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int	err(t_map *map);

int	main(void)
{
	t_map	*map;

	map = map_factory();

	if (!map || map->errno)
	{
		return (err(map));
	}
	console_map(map);
	return (EXIT_SUCCESS);
}

static int err(t_map *map)
{
	int status;
	status = EXIT_FAILURE;
	if (map)
	{
		status = map->errno;
		free(map);
	}
	write(STDERR_FILENO, "Error\n", 6);
	return (status);
}
