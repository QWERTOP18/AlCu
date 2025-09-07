/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ai_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:54:36 by yui               #+#    #+#             */
/*   Updated: 2025/09/07 20:57:36 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"


static int	compute_for_win(int remaining)
{
    int target;

    target = 1;
	if (remaining <= MAX_INPUT_NUMBER)
		target = remaining - 1;
	else
	    target =  (remaining - 1) % (MAX_INPUT_NUMBER + 1);
    if (target > remaining || target == 0)
        return (1);
    return (target);
}

static int	compute_for_lose(int remaining)
{
	int target = remaining % (MAX_INPUT_NUMBER + 1);
	if (target > remaining || target == 0)
		return (1);
	return (target);
}

int	compute_ai_move(t_map *m)
{
	int	remaining;

	remaining = m->lines[m->height - 1];

	
	if (m->should_ai_take_last[m->height - 1])
	{
        return compute_for_lose(remaining);
	}
    return compute_for_win(remaining);
}
