/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:59:00 by mafujima          #+#    #+#             */
/*   Updated: 2025/09/07 18:59:02 by mafujima         ###   ########.fr       */
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
			printf("| ");
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}
