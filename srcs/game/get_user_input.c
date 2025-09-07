/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:02:47 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 18:28:36 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_user_input(void)
{
	char	*line;
	int		value;
	int		fd;

	value = 0;
	line = NULL;
	fd = open("/dev/tty", O_RDONLY);
	if (fd == -1)
		return (-ERR_FATAL);
	while (1)
	{
		write(STDERR_FILENO, INPUT_MSG, INPUT_MSG_LEN);
		line = get_next_line(fd);
		if (!line)
			return (close(fd), -ERR_FATAL);
		value = lib_atoi(line);
		free(line);
		if (value > 0 && value <= MAX_INPUT_NUMBER)
		{
			break ;
		}
		write(STDERR_FILENO, INPUT_ERR_MSG, INPUT_ERR_MSG_LEN);
	}
	close(fd);
	return (value);
}
