/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:53:57 by wiharel           #+#    #+#             */
/*   Updated: 2022/07/25 14:53:59 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	to_decimal(char *str)
{
	int	i;
	int	pow;
	int	num;
	int	ret;

	i = 0;
	ret = 0;
	while (i < 8)
	{
		pow = 7 - i;
		if (str[i] == '1')
		{
			num = 1;
			while (pow > 0)
			{
				num = num * 2;
				pow--;
			}
		}
		else if (str[i] == '0')
			num = 0;
		ret = ret + num;
		i++;
	}
	return (ret);
}
