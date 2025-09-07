/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:02:47 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 15:23:19 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int	get_user_input(void)
{
	char	*line;
	int		value;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (INVALID_NUMBER);
	value = lib_atoi(line);
	if (value < 1 || value > MAX_INPUT_NUMBER)
		return (INVALID_NUMBER);
	return (value);
}
