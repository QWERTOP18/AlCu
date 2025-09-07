/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 23:58:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 19:02:25 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int	err(t_map *map);

int	main(void)
{
	t_map	*map;

	map = map_factory();
	if (!map || map->errno)
		return (err(map));
	game_start(map);
	if (map->errno)
		return (err(map));
	map_clear(&map);
	return (EXIT_SUCCESS);
}

static int	err(t_map *m)
{
	int	status;

	status = EXIT_FAILURE;
	if (m)
	{
		status = m->errno;
		map_clear(&m);
	}
	write(STDERR_FILENO, ERRMSG, ERRMSG_LEN);
	return (status);
}
