/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ftypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:04:49 by askobins          #+#    #+#             */
/*   Updated: 2020/05/12 15:27:41 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

//precision is 6 by default

void	p_float_normal(double nb, unsigned char flags, size_t *wp)
{
	int len;

	len = h_numlen((long long)nb, 10) +
		(flags & (1 << PRE) ? wp[1] + !!wp[1] : 7);
	width = wp[0] > len + !!(flags & (1 << PLS)) ?
		wp[0] - len - !!(flags & (1 << PLS)) : 0;
	if (width && !(flags & (1 << LFT)))

}
