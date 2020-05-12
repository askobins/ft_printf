/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:18:31 by askobins          #+#    #+#             */
/*   Updated: 2020/05/12 14:22:35 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void		h_align(size_t size, char c)
{
	unsigned long	tmp;

	tmp = LO * c;
	while (size / 8)
	{
		write(1, &tmp, 8);
		size -= 8;
	}
	if (size / 4)
	{
		write(1, &tmp, 4);
		size -= 4;
	}
	if (size / 2)
	{
		write (1, &tmp, 2);
		size -= 2;
	}
	if (size)
	{
		write(1, &c, 1);
		size--;
	}
}

long long	h_mask(long long nb, long long mask)
{
	return (nb > 0 ? nb & mask : nb | ~mask);
}

int			h_numlen(long long nb, int base)
{
	int		len;

	len = (nb < 0);
	while (nb /= base)
		len++;
	return (len);
}
