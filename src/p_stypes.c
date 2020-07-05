/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:54:26 by askobins          #+#    #+#             */
/*   Updated: 2020/07/05 14:13:24 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

size_t			p_char(char c, size_t w)
{
	if (w && !g_flags.lft)
		h_align(w - 1, ' ');
	write(1, &c, 1);
	if (w && g_flags.lft)
		h_align(w - 1, ' ');
	return (w ? w : 1);
}

static size_t	maxlen(const char *str, size_t max)
{
	const char	*cpy;

	if (!str || !max)
		return (0);
	cpy = str;
	while ((t_ullong)cpy & 7 && cpy++ && --max)
		if (!*cpy)
			return (cpy - str);
	while (!((((t_ullong)*cpy) - LO) & ~((t_ullong)*cpy) & HI) && max >= 8)
	{
		cpy += 8;
		max -= 8;
	}
	while (*cpy && max--)
		cpy++;
	return (cpy - str);
}

size_t			p_string(const char *str, t_uint *wp)
{
	if (str)
		wp[1] = g_flags.pre ? maxlen(str, wp[1]) : ft_strlen(str);
	else
		wp[1] = wp[1] >= 6 ? 6 : 0;
	wp[0] = h_usub(wp[0], wp[1]);
	if (!g_flags.lft)
		h_align(wp[0], ' ');
	if (str && *str)
		write(1, str, wp[1]);
	else if (!str && (!g_flags.pre || wp[1]))
		write(1, "(null)", 6);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1]);
}
