/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:54:03 by wiharel           #+#    #+#             */
/*   Updated: 2022/07/25 14:54:04 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YYL "\e[0;33m"

# include "./includes/ft_printf.h"
# include "./includes/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <assert.h>
# include <time.h>

int	to_decimal(char *str);

#endif
