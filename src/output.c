/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:43:55 by askobins          #+#    #+#             */
/*   Updated: 2020/07/13 20:05:33 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

static void		put_long(t_ullong nb, const char *set, const t_uint base)
{
	if (nb > base - 1)
		put_long(nb / base, set, base);
	write(1, &set[nb % base], 1);
}

size_t			ft_putlong(t_ullong nb, const t_uint base)
{
	if (base == 2)
		put_long(nb, B2SET, base);
	else if (base == 8)
		put_long(nb, B8SET, base);
	else if (base == 10)
		put_long(nb, B10SET, base);
	else if (base == 16)
		put_long(nb, g_flags.cap ? B16SETUP : B16SETLO, base);
	return (h_numlen(nb, base));
}

#include <stdio.h>
static size_t	put_precision(double nb, t_uint p)
{
	t_uint	tmp;
	size_t	ret;

	ret = p;
	if (p || g_flags.alt)
		ret += write(1, ".", 1);
	while (p)
	{
		tmp = (p > 19 ? 19 : p);
		nb = h_muldiv(nb, tmp, MUL);
		nb += (tmp == p && (nb - (t_ullong)nb) * 10 >= 5);
		if ((t_ullong)nb && (h_numlen((t_ullong)nb, 10) < tmp))
			h_align(tmp - h_numlen((t_ullong)nb, 10), '0');
		if ((t_ullong)(nb))
		{
			if (g_flags.ext)
				while (!((t_ullong)nb % 10))
					nb /= 10;
			ft_putlong((t_ullong)nb, 10);
		}
		else if (tmp != p || (!g_flags.ext || g_flags.alt))
			h_align(tmp, '0');
		else
			ret -= tmp;
		nb -= (t_ullong)nb;
		p -= tmp;
	}
	return (ret);
}

/*
static size_t	put_precision(double nb, t_uint p)
{
	t_uint	precision;
	t_uint	size;
	t_uint	total;

	precision = 0;
	total = p;
	p = p <= 16 ? p + 1 : 17;
	size = p - 1;
	while (--p)
	{
		precision = (precision * 10) + ((nb - (int)nb) * 10);
		nb = (nb - (int)nb) * 10;
	}
	precision += (!p && (nb - (t_ullong)nb) * 10 >= 5);
	if (precision || g_flags.alt)
		write(1, ".", 1);
	h_align(size - (!!precision * h_numlen(precision, 10)), '0');
	if (precision)
		ft_putlong(precision, 10);
	if (!g_flags.ext || g_flags.alt)
		h_align(total - size, 0);
	return ((precision || g_flags.alt) + h_numlen(precision, 10) +
			((total - size) * !g_flags.ext));
}*/

size_t			ft_putfloat(double nb, t_uint exp, t_uint p)
{
	if (nb <= (double)ULLONG_MAX)
	{
		ft_putlong((t_ullong)nb, 10);
		return (exp + put_precision(nb - (long)nb, p));
	}
	h_align(exp + 1, '0');
	return (exp + put_precision(nb, p));
}
