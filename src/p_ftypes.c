/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ftypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:04:49 by askobins          #+#    #+#             */
/*   Updated: 2020/07/06 20:43:28 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

#define MSK 0x7FFUL
#define LOG 0.30103

static size_t	put_inf_nan(double nb, t_uint w)
{
	t_floatlong		u;
	char			neg;

	u.nb = nb;
	neg = '-' * !!(u.raw & (1ULL << 63));
	if (!g_flags.lft)
		h_align(h_usub(w, 3 + !!neg), ' ');
	if (neg)
		write(1, &neg, 1);
	if (nb == nb)
		write(1, g_flags.cap ? "NAN" : "nan", 3);
	else
		write(1, g_flags.cap ? "INF" : "inf", 3);
	if (g_flags.lft)
		h_align(h_usub(w, 3 + !!neg), ' ');
	return (w ? w : 3 + !!neg);
}

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
	if (precision || g_flags.alt)
		write(1, ".", 1);
	h_align(size - (!!precision * h_numlen(precision, 10)), '0');
	if (precision)
		ft_putlong(precision, 10);
	if (!g_flags.ext || g_flags.alt)
		h_align(total - size, 0);
	return ((precision || g_flags.alt) + h_numlen(precision, 10) +
			((total - size) * !g_flags.ext));
}

static size_t	p_float_normal(double nb, t_uint *wp)
{
	size_t	len;
	char	sign;

	if (!(sign = '-' * (nb < 0)) && (g_flags.pls || g_flags.spc))
		sign = (g_flags.pls ? '+' : ' ');
	len = h_numlen(ft_abs(nb), 10);
	wp[0] = h_usub(wp[0], len + !!sign);
	if (!g_flags.lft && !g_flags.zro)
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	if (g_flags.zro && !g_flags.lft)
		h_align(wp[0], '0');
	ft_putlong(ft_abs(nb), 10);
	len += put_precision(nb, wp[1]);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + len + !!sign);
}

static size_t	p_float_scient(double nb, t_uint *wp)
{
	size_t		len;
	char		e[2];
	t_uint		exp;
	t_floatlong	u;

	e[0] = g_flags.cap ? 'E' : 'e';
	e[1] = nb < 1 ? '-' : '+';
	u.nb = nb;
	exp = ft_abs((int)((u.raw >> 52 & MSK) - 1023) * LOG) + (nb < 1 && nb > -1);
	wp[0] = h_usub(wp[0], 2 + h_numlen(exp, 10) + (exp < 10));
	len = p_float_normal(nb, wp);
	write(1, e, 2);
	if (exp < 10)
		write(1, "0", 1);
	ft_putlong(exp, 10);
	return (len + 2 + h_numlen(exp, 10) + (ft_abs(nb) < 10));
}

size_t			p_float(double nb, t_uint *wp)
{
	int			exp;
	t_floatlong	u;

	u.nb = nb;
	if (nb != nb || ((u.raw & (-1ULL >> 1)) >= MSK << 52))
		return (put_inf_nan(nb, wp[1]));
	if (g_flags.ext)
	{
		exp = ((int)((u.raw >> 52 & MSK) - 1023) * LOG) - (nb < 1 && nb > -1);
		if (exp >= -4 && (exp < 0 || (size_t)exp < wp[1]))
		{
			wp[1] = h_usub(wp[1], exp + 1);
			return (p_float_normal(nb, wp));
		}
		else
		{
			wp[1] = wp[1] ? wp[1] - 1 : 0;
			return (p_float_scient(nb, wp));
		}
	}
	return (g_flags.pre ? p_float_scient(nb, wp) : p_float_normal(nb, wp));
}
