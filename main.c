/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 23:58:46 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/06 00:35:45 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef void	t_map;
typedef void	line;

t_map	*parse_map(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	printf("%s", line);
	while (line != NULL)
	{
		line = get_next_line(STDIN_FILENO);
		printf("%sj", line);
	}
	return (NULL);
}

int	main(void)
{
	t_map	*map;

	map = parse_map();
	return (0);
}
