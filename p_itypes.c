/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/06/10 00:06:53 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t	p_int(t_llong nb, size_t *wp)
{
	t_uint	len;
	char	sign;

	sign = 0;
	if (!(sign = '-' * (nb < 0)) && g_flags.pls || g_flags.spc)
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
	ft_putlong(ft_abs(nb));
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1] + len + !!sign);
}
