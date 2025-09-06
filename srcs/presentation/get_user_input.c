/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:02:47 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/06 13:46:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "interface.h"
#include "lib.h"

int	get_user_input(void)
{
	char	*line;
	int		value;

	line = get_next_line(STDIN_FILENO);
	value = atoi(line);
	if (value < 1 || value > MAX_INPUT_NUMBER)
	{
		return (INVALID_NUMBER);
	}
	return (value);
}
