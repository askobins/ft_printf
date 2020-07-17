/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ftypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:00:17 by askobins          #+#    #+#             */
/*   Updated: 2020/07/17 15:45:57 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define LOG 0.30103

static size_t	put_inf_nan(double nb, t_uint w)
{
	t_floatlong	u;
	char		neg;

	u.nb = nb;
	neg = '-' * u.raw.sign;
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

static size_t	p_float_normal(double nb, t_uint *wp)
{
	char		sign;
	t_uint		exp;
	t_floatlong	u;

	if (!(sign = '-' * (nb < 0)) && (g_flags.pls || g_flags.spc))
		sign = g_flags.pls ? '+' : ' ';
	u.nb = nb;
	u.raw.sign = 0;
	exp = ft_abs((long)((int)u.raw.expo - 1023) * LOG) + (u.nb < 1);
	exp += (t_uint)h_muldiv(u.nb, exp, u.nb < 1) > 9;
	wp[0] = h_usub(wp[0], exp + !!sign + wp[1] + 2 - g_flags.alt);
	if (!g_flags.lft && !g_flags.zro)
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	if (!g_flags.lft && g_flags.zro)
		h_align(wp[0], '0');
	wp[1] = ft_putfloat(u.nb, exp, wp[1]);
	if (g_flags.lft && !g_flags.alt)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + !!sign);
}

static size_t	p_float_scient(double nb, t_uint *wp)
{
	size_t		len;
	char		e[2];
	t_uint		exp;
	t_floatlong	u;

	u.nb = nb;
	u.raw.sign = 0;
	e[0] = g_flags.cap ? 'E' : 'e';
	e[1] = u.nb < 1 ? '-' : '+';
	exp = ft_abs((long)((int)u.raw.expo - 1023) * LOG) + (u.nb < 1);
	exp += ((t_uint)h_muldiv(u.nb, exp, u.nb < 1) > 9);
	wp[0] = h_usub(wp[0], 3 + h_numlen(exp, 10) + (exp < 10));
	len = p_float_normal(h_muldiv(nb, exp, u.nb < 1), wp);
	write(1, e, 2);
	if (exp < 10)
		write(1, "0", 1);
	ft_putlong(exp, 10);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (len + 2 + h_numlen(exp, 10) + (exp < 9));
}

size_t			p_float(double nb, t_uint *wp)
{
	int			exp;
	t_floatlong	u;

	if (!g_flags.pre)
		wp[1] = 6;
	u.nb = nb;
	if (nb != nb || u.raw.expo == 2048)
		return (put_inf_nan(nb, wp[0]));
	if (g_flags.ext)
	{
		exp = (int)((int)(u.raw.expo - 1023) * LOG);
		if (exp >= -4 && (exp < 0 || (size_t)exp < wp[1]))
		{
			wp[1] = h_usub(wp[1], exp + 1);
			return (p_float_normal(nb, wp));
		}
		else
		{
			g_flags.alt = 1;
			wp[1] = wp[1] ? wp[1] - 1 : 0;
			return (p_float_scient(nb, wp));
		}
	}
	return (g_flags.alt ? p_float_scient(nb, wp) : p_float_normal(nb, wp));
}
