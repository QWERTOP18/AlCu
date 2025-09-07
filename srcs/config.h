/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:04:08 by ymizukam          #+#    #+#             */
/*   Updated: 2025/09/07 18:39:26 by mafujima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define INVALID_NUMBER -404

# define MAX_INPUT_NUMBER 3
# define MAX_MAP_HEIGHT 1024
# define MAX_LINE_VALUE 10000

# define ERR_INVALID_INPUT 0b10
# define ERR_MAP_TOO_LARGE 0b100
# define ERR_FATAL 0b1000
# define ERR_AI_MOVE 0b10000

# define WINMSG "You are the winner! Congratulations!\n"
# define WINMSG_LEN 37

# define LOSEMSG "Game Over! Revenge again!\n"
# define LOSEMSG_LEN 26

# define ERRMSG "Error\n"
# define ERRMSG_LEN 6
#endif
