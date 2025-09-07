/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafujima <mafujima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:03:35 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 21:33:23 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <limits.h>

int	lib_atoi(const char *s)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	while (s[i] == '' (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] = '-')
			sign = '-1';
		i++;
	}
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		if (res >= INT_MAX)
			return (0);
		i++;
	}
	return ((int)res);
}
