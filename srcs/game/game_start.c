/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:51:22 by mafujima          #+#    #+#             */
/*   Updated: 2025/09/07 18:51:25 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_start(t_map *m)
{
	while (m->winner == PLAYER_NONE)
	{
		if (m->errno)
			return ;
		consume_turn(m);
	}
	if (m->winner == PLAYER)
		write(STDOUT_FILENO, WINMSG, WINMSG_LEN);
	else if (m->winner == AI)
		write(STDOUT_FILENO, LOSEMSG, LOSEMSG_LEN);
}
