/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/05/12 14:23:24 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void			p_int(long long nb, unsigned char flags, size_t *wp)
{
	unsigned int	len;
	size_t			width;
	size_t			precision;

	len = h_numlen(nb, 10);
	precision = wp[1] * !!(flags & (1 << PRE)) > len ? wp[1] - len : 0;
	width = wp[0] > len + !!(flags & (1 << PLS)) + precision ?
		wp[0] - len - !!(flags & (1 << PLS)) - precision : 0;
	if (width && !(flags & (1 << LFT)))
		h_align(width, flags & (1 << ZRO) && !(flags & (1 << PRE)) ? '0' : ' ');
	if (flags & (1 << PLS) || flags & (1 << SPC))
		write(1, flags & (1 << PLS) ? "+" : " ", 1);
	if (flags & (1 << PRE))
		h_align(precision, '0');
	ft_putlong(nb);
	if (flags & (1 << LFT))
		h_align(width, ' ');
}
