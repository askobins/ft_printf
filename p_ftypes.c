/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ftypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:04:49 by askobins          #+#    #+#             */
/*   Updated: 2020/06/10 17:39:53 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define MSK 0x7FFUL
#define LOG 0.30103

static void	put_precision(double nb, size_t p)
{
	t_ulong	precision;
	size_t	size;
	size_t	total;

	precision = 0;
	total = p;
	p = p <= 16 ? p + 1 : 17;
	size = p - 1;
	while (--p)
		precision = (precision * 10) + ((nb - (long)nb) * 10);
	if (precision || g_flags.alt)
		write(1, ".", 1);
	h_align(size - (!!precision * h_numlen(precision, 10)), '0');
	if (precision)
		ft_putlong(precision, 10, B10SET);
	if (!g_flags.ext)
		h_align(total - size, 0);
}

size_t		p_float_normal(double nb, size_t *wp)
{
	size_t	len;
	char	sign;

	if (nb != nb || is_inf(nb))
		return (put_inf_nan(nb, wp[0]));
	if (!(sign = '-' * (nb < 0)) && (g_flags.pls || g_flags.spc))
		sign = (g_flags.pls ? '+' : ' ');
	len = h_numlen(ft_abs(nb), 10) + wp[1] + !!(wp[1] || g_flags.alt);
	wp[0] = h_usub(wp[0], len + !!sign);
	if (!g_flags.lft && !g_flags.zro)
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	if (g_flags.zro && !g_flags.lft)
		h_align(wp[0], '0');
	ft_putlong(ft_abs(nb), 10, B10SET);
	put_precision(nb, wp[1]);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + len + !!sign);
}

size_t		p_float_scient(double nb, size_t *wp)
{
	size_t	len;
	char	e[2];
	t_uint	exp;
	t_floatlong	u;

	if (nb != nb || is_inf(nb))
		return(put_inf_nan(nb, wp[0]));
	e[0] = g_flags.cap ? 'E' : 'e';
	e[1] = nb < 1 ? '-' : '+';
	u.nb = nb;
	exp = ft_abs((int)((u.raw >> 52 & MSK) - 1023) * LOG) + (nb < 1 && nb > -1);
	wp[0] = h_usub(wp[0], 2 + h_numlen(exp, 10) + (exp < 10));
	len = p_float_normal(nb, wp);
	write(1, e, 2);
	if (exp < 10)
		write(1, "0", 1);
	ft_putlong(exp, 10, B10SET);
	return (len + 2 + h_numlen(exp, 10) + (ft_abs(nb) < 10));
}


//bounds: LOWER = 0.0001
#define DFAC 4503599627370496


size_t		p_float_choose(double nb, size_t *wp)
{
	
}
