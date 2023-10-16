/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:37:11 by wiharel           #+#    #+#             */
/*   Updated: 2021/12/06 19:14:48 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	nb;

	nb = 0;
	while (nb < n)
	{
		*(char *)(s + nb) = 0;
		nb++;
	}
}
