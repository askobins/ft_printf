/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:18:31 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 18:45:58 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void		h_align(size_t size, char c)
{
	t_ulong	tmp;

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
		write(1, &tmp, 2);
		size -= 2;
	}
	if (size)
	{
		write(1, &c, 1);
		size--;
	}
}

long long	h_mask(t_llong nb, t_llong mask)
{
	return (nb > 0 ? nb & mask : nb | ~mask);
}

int			h_numlen(t_ullong nb, int base)
{
	int		len;

	while (nb /= base)
		len++;
	return (len);
}

t_ullong	h_usub(t_ullong a, t_ullong b)
{
	return (a > b ? a - b : 0);
}
