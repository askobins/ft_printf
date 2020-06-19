/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 18:57:17 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

size_t					p_int(t_llong nb, size_t *wp, t_ullong mask)
{
	t_uint	len;
	char	sign;

	nb = nb >= 0 ? nb & mask : nb | ~mask;
	sign = 0;
	if (!(sign = '-' * (nb < 0)) && (g_flags.pls || g_flags.spc))
		sign = (g_flags.pls ? '+' : ' ');
	len = h_numlen(ft_abs(nb), 10);
	wp[1] = g_flags.zro && !g_flags.lft && wp[0] - !!sign >
		wp[1] * g_flags.pre ? h_usub(wp[0], len + !!sign) :
		h_usub(wp[1] * g_flags.pre, len);
	wp[0] = h_usub(wp[0], wp[1] + len + !!sign);
	if (!g_flags.lft && !g_flags.zro)
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	h_align(wp[1], '0');
	ft_putlong(ft_abs(nb), 10);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + len + !!sign);
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

size_t					p_uint(t_ullong nb, size_t *wp, const t_uint base)
{
	t_uint	len;
	char	sign;

	if (g_flags.alt)
		wp[0] = h_usub(wp[0], prefix(base));
	sign = 0;
	if (g_flags.pls || g_flags.spc)
		sign = (g_flags.pls ? '+' : ' ');
	len = h_numlen(nb, base);
	wp[1] = g_flags.zro && !g_flags.lft && wp[0] - !!sign >
		wp[1] * g_flags.pre ? h_usub(wp[0], len + !!sign) :
		h_usub(wp[1] * g_flags.pre, len);
	wp[0] = h_usub(wp[0], wp[1] + len + !!sign);
	if (!g_flags.lft && !g_flags.zro)
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	h_align(wp[1], '0');
	ft_putlong(nb, base);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + len + !!sign);
}
