/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/05/16 18:28:26 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void			p_int(t_llong nb, t_uchar flags, size_t *wp)
{
	t_uint	len;
	char	sign;

	sign = 0;
	if (!(sign = '-' * (nb < 0)) && (flags & (1 << PLS) || flags & (1 << SPC)))
		sign = (flags & (1 << PLS) ? '+' : ' ');
	len = h_numlen(ft_abs(nb), 10);
	wp[1] = flags & (1 << ZRO) && !(flags & (1 << LFT)) && wp[0] - !!sign >
		wp[1] * !!(flags & (1 << PRE)) ? h_usub(wp[0], len + !!sign) :
		h_usub(wp[1] * !!(flags & (1 << PRE)), len);
	wp[0] = h_usub(wp[0], len + !!sign);
	if (!(flags & (1 << LFT)) && !(flags & (1 << ZRO)))
		h_align(wp[0], ' ');
	if (sign)
		write(1, &sign, 1);
	h_align(wp[1], '0');
	ft_putlong(ft_abs(nb));
	if (flags & (1 << LFT))
		h_align(wp[0], ' ');
}
