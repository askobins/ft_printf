/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_stypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:54:26 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 16:30:44 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

size_t	p_char(char c, size_t w)
{
	if (!g_flags.lft && w)
		h_align(w - 1, ' ');
	write(1, &c, 1);
	if (g_flags.lft && w)
		h_align(w - 1, ' ');
	return (w ? w : 1);
}

size_t	p_string(const char *str, size_t *wp)
{
	wp[1] = wp[1] * g_flags.pre < ft_strlen(str) ?
		wp[1] : ft_strlen(str);
	wp[0] = h_usub(wp[0], wp[1]);
	if (!g_flags.lft)
		h_align(wp[0], ' ');
	write(1, str, wp[1]);
	if (g_flags.lft)
		h_align(wp[0], ' ');
	return (wp[0] + wp[1]);
}
