/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:47:14 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 19:56:24 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "config.h"
# include "lib.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef enum e_player
{
	PLAYER_NONE = 0,
	PLAYER = 1,
	AI = 2,
}				t_player;

typedef struct s_map
{
	int					errno;
	int					max_width;
	int					height;
	t_player			winner;
	int					lines[MAX_MAP_HEIGHT];
	bool				should_ai_take_last[MAX_MAP_HEIGHT];
}						t_map;

t_map					*map_factory(void);
void					map_clear(t_map **m);
void					console_map(t_map *m);
void					game_start(t_map *m);

int     				compute_ai_move(t_map *m);
void 					compute_should_ai_take_last(t_map *m);

#endif
