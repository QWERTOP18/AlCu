/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:47:14 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/06 13:44:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "config.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line	t_line;

struct					s_line
{
	int					width;
	t_line				*next;
};

// errnoはbit和を取る予定
typedef struct s_map
{
	int					errno;
	int					max_width;
	int					height;

	lines[MAX_MAP_HEIGHT];
}						t_map;

t_map					*map_factory(void);
void					console_map(t_map *m);

#endif
