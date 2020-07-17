/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/07/17 14:51:18 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t					p_int(t_llong nb, t_uint *wp, t_ullong mask)
{
	t_uint	len;
	char	sign;

	nb = (t_ullong)nb & (mask + 1) / 2 ? nb | ~mask : nb & mask;
	if (!(sign = '-' * (nb < 0)) && (g_flags.pls || g_flags.spc))
		sign = g_flags.pls ? '+' : ' ';
	len = (nb || !g_flags.pre) ? h_numlen(ft_abs(nb), 10) : 0;
	wp[1] = g_flags.pre ? h_usub(wp[1], len * !!nb) :
		(g_flags.zro && !g_flags.lft) * h_usub(wp[0], len + !!sign);
	wp[0] = h_usub(wp[0], wp[1] + !!sign + (len * !(g_flags.pre && !nb)));
	if (!g_flags.lft && (!g_flags.zro || g_flags.pre))
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	h_align(wp[1], '0');
	if (nb || !g_flags.pre)
		ft_putlong(ft_abs(nb), 10);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + (len * !(!nb && g_flags.pre)) + !!sign);
}

inline static t_uint	prefix(t_uint base)
{
	if (base == 2)
		return (write(1, g_flags.cap ? "0B" : "0b", 2));
	else if (base == 8)
		return (write(1, "0", 1));
	else if (base == 16)
		return (write(1, g_flags.cap ? "0X" : "0x", 2));
	else
		return (0);
}

size_t					p_uint(t_ullong nb, t_uint *wp, const t_uint base)
{
	t_uint	len;
	char	sign;

	sign = 0;
	if (g_flags.pls || g_flags.spc)
		sign = g_flags.pls ? '+' : ' ';
	len = (nb || !g_flags.pre) ? h_numlen(nb, base) : 0;
	wp[1] = g_flags.pre ? h_usub(wp[1], len * !!nb) :
		(g_flags.zro && !g_flags.lft) * h_usub(wp[0], len + !!sign);
	wp[0] = h_usub(wp[0], wp[1] + !!sign + (len * !(g_flags.pre && !nb)));
	if (g_flags.alt)
		wp[0] = h_usub(wp[0], (base != 10) + (base == 2 || base == 16));
	if (!g_flags.lft && (!g_flags.zro || g_flags.pre))
		h_align(wp[0], ' ');
	prefix(base * g_flags.alt);
	if (sign)
		write(1, &sign, 1);
	h_align(wp[1], '0');
	if (nb || !g_flags.pre)
		ft_putlong(nb, base);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + (len * !(!nb && g_flags.pre)) + !!sign +
			(g_flags.alt * ((base != 10) + (base == 2 || base == 16))));
}
