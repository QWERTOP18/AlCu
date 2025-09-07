/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:44:57 by mafujima          #+#    #+#             */
/*   Updated: 2025/09/07 21:27:11 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	map_action(t_map *m, int value, t_player player)
{
	int	current_line;

	if (m->height == 0)
		return (false);
	current_line = m->height - 1;
	if (value < 1 || value > MAX_INPUT_NUMBER)
		return (false);
	if (value > m->lines[current_line])
		return (false);
	m->lines[current_line] -= value;

	if (player == AI)
    {
		write(STDOUT_FILENO,"AI took ", 9);
        lib_putnbr(value);
        write(STDOUT_FILENO, "\n", 1);
    }
	if (m->lines[current_line] == 0)
		m->height--;
	return (true);
}

void	ai_move(t_map *m)
{
	console_map(m);
	if (map_action(m, compute_ai_move(m), AI) == false)
		m->errno |= ERR_AI_MOVE;
}

void	player_move(t_map *m)
{
	int	value;

	console_map(m);
	value = 0;
	while (1)
	{
		value = get_user_input();
		if (value == -ERR_FATAL)
		{
			m->errno |= ERR_FATAL;
			return ;
		}
		if (map_action(m, value, PLAYER))
			return ;
		write(STDERR_FILENO, INPUT_ERR_MSG, INPUT_ERR_MSG_LEN);
	}
}

int	check_game_over(t_map *m)
{
	if (m->height == 0)
		return (1);
	return (0);
}

void	consume_turn(t_map *m)
{
	ai_move(m);
	if (check_game_over(m))
		m->winner = PLAYER;
	if (m->winner || m->errno)
		return ;
	player_move(m);
	if (check_game_over(m))
		m->winner = AI;
}
