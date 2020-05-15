/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:34:32 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 20:20:51 by askobins         ###   ########.fr       */
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

void	ft_putlong(t_ullong nb)
{
	if (nb > 9)
		ft_putlong(nb / 10);
	ft_putchar((nb % 10) + '0');
}
