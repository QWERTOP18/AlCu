/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:02:47 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 15:54:04 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_user_input(void)
{
	char	*line;
	int		value;

	value = 0;
	line = NULL;
	while(1)
	{
		write(STDERR_FILENO, INPUT_MSG, INPUT_MSG_LEN);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		return (-ERR_FATAL);
		value = lib_atoi(line);
		free(line);
		if (value > 0 &&  value <= MAX_INPUT_NUMBER)
		{
			break;
		}
	}

	return (value);
}
