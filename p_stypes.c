/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:54:26 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 18:46:43 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	p_char(char c, t_uchar flags, size_t w)
{
	if (flags & (1 << LFT))
	{
		write(1, &c, 1);
		if (w)
			h_align(w - 1, ' ');
	}
	else
	{
		if (w)
			h_align(w - 1, ' ');
		write(1, &c, 1);
	}
}

void	p_string(const char *str, t_uchar flags, size_t *wp)
{
	size_t	len;

	len = wp[1] < ft_strlen(str) ? wp[1] : ft_strlen(str);
	if (flags & (1 << LFT))
	{
		write(1, str, len);
		if (wp[0] > len)
			h_align(wp[0] - len, ' ');
	}
	else
	{
		if (wp[0] > len)
			h_align(wp[0] - len, ' ');
		write(1, str, len);
	}
}
