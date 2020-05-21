/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:54:26 by askobins          #+#    #+#             */
/*   Updated: 2020/05/21 13:20:25 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t	p_char(char c, t_uchar flags, size_t w)
{
	if (!(flags & (1 << LFT)) && w)
		h_align(w - 1, ' ');
	write(1, &c, 1);
	if (flags & (1 << LFT) && w)
		h_align (w - 1, ' ');
	return (w ? w : 1);
}

size_t	p_string(const char *str, t_uchar flags, size_t *wp)
{
	wp[1] = wp[1] < ft_strlen(str) ? wp[1] : ft_strlen(str);
	wp[0] = h_usub(wp[0], wp[1]);
	if (!(flags & (1 << LFT)))
		h_align(wp[0], ' ');
	write(1, str, wp[1]);
	if (flags & (1 << LFT))
		h_align(wp[0], ' ');
	return (wp[0] + wp[1]);
}
