/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ftypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:04:49 by askobins          #+#    #+#             */
/*   Updated: 2020/05/21 13:22:35 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	put_precision(double nb, size_t p)
{
	t_ulong	precision;
	t_uint	size;
	t_uint	total;

	precision = 0;
	total = p;
	p = p <= 16 ? p + 1 : 17;
	size = p - 1;
	while (--p)
		precision = (precision * 10) + (t_uint)((nb - (long)nb) * 10);
	write(1, ".", 1);
	h_align(size - h_numlen(precision, 10), '0');
	ft_putlong(precision);
	h_align(total - size, 0);
}

size_t		p_float_normal(double nb, t_uchar flags, size_t *wp)
{
	size_t	len;
	char	sign;

	if (nb != nb || is_inf(nb))
		return (put_inf_nan(nb, flags, wp[0]));
	sign = 0;
	if (!(sign = '-' * (nb < 0)) && (flags & (1 << PLS) || flags & (1 << SPC)))
		sign = (flags & (1 << PLS) ? '+' : ' ');
	wp[1] = flags & (1 << PRE) ? wp[1] : 6;
	len = h_numlen(ft_abs((long)nb), 10) + wp[1] + !!wp[1];
	wp[0] = h_usub(wp[0], len + !!sign);
	if (!(flags & (1 << LFT)) && !(flags & (1 << ZRO)))
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	if (flags & (1 << ZRO) && !(flags & (1 << LFT)))
		h_align(wp[0], '0');
	ft_putlong(ft_abs((long)nb));
	if (wp[1])
		put_precision(nb, wp[1]);
	if (flags & (1 << LFT))
		h_align(wp[0], ' ');
	return (wp[0] + len + !!sign);
}
