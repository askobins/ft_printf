/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:19:17 by askobins          #+#    #+#             */
/*   Updated: 2020/06/28 14:45:37 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

inline t_ullong	ft_abs(t_llong nb)
{
	return (nb > 0 ? (t_ullong)nb : (t_ullong)-nb);
}

inline t_uint	ft_is_in(t_ullong a, char b)
{
	a ^= LO * b;
	return (!!((a - LO) & ~a & HI));
}

static void		put_long(t_ullong nb, const char *set, const t_uint base)
{
	if (nb > base - 1)
		put_long(nb / base, set, base);
	write(1, &set[nb % base], 1);
}

void			ft_putlong(t_ullong nb, const t_uint base)
{
	if (base == 2)
		put_long(nb, B2SET, base);
	else if (base == 8)
		put_long(nb, B8SET, base);
	else if (base == 10)
		put_long(nb, B10SET, base);
	else if (base == 16)
		put_long(nb, g_flags.cap ? B16SETUP : B16SETLO, base);
}

size_t			ft_strlen(const char *str)
{
	const char	*cpy;

	if (!str)
		return (0);
	cpy = str;
	while ((t_ullong)cpy & 7 && cpy++)
		if (!*cpy)
			return (cpy - str);
	while (!((((t_ullong)*cpy) - LO) & ~((t_ullong)*cpy) & HI))
		cpy += 8;
	while (*cpy)
		cpy++;
	return (cpy - str);
}
