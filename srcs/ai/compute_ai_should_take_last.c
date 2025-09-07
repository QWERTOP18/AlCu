/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ai_should_take_last.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:56:59 by yui               #+#    #+#             */
/*   Updated: 2025/09/07 20:13:50 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	compute_should_ai_take_last(t_map *m)
{
    int	i;

    m->should_ai_take_last[0] = false;
   
    i = 0;
    while (++i < m->height)
    {
        if (m->lines[i - 1] % (MAX_INPUT_NUMBER + 1) == 1)
            m->should_ai_take_last[i] = !m->should_ai_take_last[i - 1];
        else
            m->should_ai_take_last[i] = m->should_ai_take_last[i - 1];
    }
}
