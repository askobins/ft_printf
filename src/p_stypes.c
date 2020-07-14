/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:54:26 by askobins          #+#    #+#             */
/*   Updated: 2020/07/14 18:58:25 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t			p_char(char c, size_t w)
{
	if (w && !g_flags.lft)
		h_align(w - 1, ' ');
	write(1, &c, 1);
	if (w && g_flags.lft)
		h_align(w - 1, ' ');
	return (w ? w : 1);
}

static t_uint	maxlen(const char *str, t_uint max)
{
	const char	*cpy;

	if (!str || !*str || !max)
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
	str = str ? str : "(null)";
	wp[1] = g_flags.pre ? maxlen(str, wp[1]) : ft_strlen(str);
	wp[0] = h_usub(wp[0], wp[1]);
	if (!g_flags.lft)
		h_align(wp[0], ' ');
	if (*str)
		write(1, str, wp[1]);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1]);
}
