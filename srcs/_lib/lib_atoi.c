/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:03:35 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 21:43:23 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <limits.h>

int	lib_atoi(const char *s)
{
	long long	result;

	if (!s)
		return (0);
	result = 0;
	while (*s)
	{
		if (*s == '\n')
			break ;
		if (*s < '0' || *s > '9')
			return (0);
		result = result * 10 + (*s - '0');
		s++;
		if (result > INT_MAX)
			return (0);
	}
	return (result);
}
