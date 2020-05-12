/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:34:32 by askobins          #+#    #+#             */
/*   Updated: 2020/04/30 12:35:00 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_putlong(long long nb)
{
	if (nb < 0)
	{
		if (nb < -9223372036854775807)
			write(1, "-9223372036854775808", 20);
		else
		{
			write(1, "-", 1);
			nb = -nb;
		}
	}
	if (nb > 9)
		ft_putlong(nb / 10);
	ft_putchar((nb % 10) + '0');
}
