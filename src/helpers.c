/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:18:31 by askobins          #+#    #+#             */
/*   Updated: 2020/07/14 18:57:46 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define LONG 10e100
#define PMAX 10000000000000000000UL

void				h_align(size_t size, char c)
{
	t_ullong	tmp;

	tmp = LO * c;
	while (size >= 8)
	{
		write(1, &tmp, 8);
		size -= 8;
	}
	if (size >= 4)
	{
		write(1, &tmp, 4);
		size -= 4;
	}
	if (size >= 2)
	{
		write(1, &tmp, 2);
		size -= 2;
	}
	if (size)
	{
		write(1, &c, 1);
		size--;
	}
}

inline t_uint		h_numlen(t_ullong nb, int base)
{
	t_uint		len;

	len = 1;
	while (nb /= base)
		len++;
	return (len);
}

inline t_ullong		h_usub(t_ullong a, t_ullong b)
{
	return ((a - b) * (a > b));
}

double				h_muldiv(double nb, t_uint pow, t_uchar op)
{
	if (!pow)
		return (nb);
	while (pow >= 100)
	{
		nb = op ? nb * LONG : nb / LONG;
		pow -= (100);
	}
	while (pow >= 19)
	{
		nb = op ? nb * PMAX : nb / PMAX;
		pow -= 19;
	}
	return (op ? nb * ft_pow(10, pow) : nb / ft_pow(10, pow));
}
