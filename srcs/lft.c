/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:19:17 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 16:21:14 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_ullong	ft_abs(t_llong nb)

{
	return (nb > 0 ? (t_ullong)nb : (t_ullong)-nb);
}

size_t	ft_strlen(const char *str)
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

static void	put_long(t_ullong nb, const char *set, const t_uint base)

{
	if (nb > base - 1)
		put_long(nb / base, set, base);
	write(1, &set[nb % base], 1);
}

void		ft_putlong(t_ullong nb, const char *set)
{
	put_long(nb, set, ft_strlen(set));
}
