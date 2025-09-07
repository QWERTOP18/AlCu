/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:59:00 by mafujima          #+#    #+#             */
/*   Updated: 2025/09/07 20:24:01 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	console_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->height)
	{
		j = 0;
		while (j < m->lines[i])
		{
			write(STDOUT_FILENO, "| ", 2);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return ;
}
