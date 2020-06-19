/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:18:31 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 18:24:35 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

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

	len = 0;
	while (nb /= base)
		len++;
	return (len);
}

inline t_ullong		h_usub(t_ullong a, t_ullong b)
{
	return ((a - b) * (a > b));
}
