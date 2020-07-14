/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:43:55 by askobins          #+#    #+#             */
/*   Updated: 2020/07/14 19:28:35 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

static size_t	put_precision(double nb, t_uint p)
{
	t_uint	tmp;
	size_t	ret;

	if ((ret = p) || g_flags.alt)
		ret += write(1, ".", 1);
	while (p)
	{
		tmp = (p > 19 ? 19 : p);
		nb = h_muldiv(nb, tmp, MUL);
		nb += (tmp == p && (nb - (t_ullong)nb) * 10 >= 5);
		if ((t_ullong)nb && (h_numlen((t_ullong)nb, 10) < tmp))
			h_align(tmp - h_numlen((t_ullong)nb, 10), '0');
		if (g_flags.ext)
			while (!((t_ullong)nb % 10))
				nb /= 10;
		if ((t_ullong)nb)
			ft_putlong((t_ullong)nb, 10);
		else if (tmp != p || (!g_flags.ext || g_flags.alt))
			h_align(tmp, '0');
		else
			ret -= tmp;
		nb -= (t_ullong)nb;
		p -= tmp;
	}
	return (ret);
}

size_t			ft_putfloat(double nb, t_uint exp, t_uint p)
{
	if (nb <= (double)ULLONG_MAX)
	{
		ft_putlong((t_ullong)nb, 10);
		return (h_numlen((t_ullong)nb, 10) + put_precision(nb - (long)nb, p));
	}
	h_align(exp + 1, '0');
	return (exp + put_precision(nb, p));
}
