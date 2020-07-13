/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:19:17 by askobins          #+#    #+#             */
/*   Updated: 2020/07/13 04:08:28 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

inline t_ullong	ft_abs(t_llong nb)
{
	return (nb > 0 ? (t_ullong)nb : (t_ullong)-nb);
}

inline t_uint	ft_is_in(t_ullong a, char b)
{
	a ^= LO * b;
	return (!!((a - LO) & ~a & HI));
}

t_uint			ft_strlen(const char *str)
{
	const char	*cpy;

	if (!str || !*str)
		return (0);
	cpy = str;
	while ((t_ulong)cpy & 7 && cpy++)
		if (!*cpy)
			return (cpy - str);
	while (!((((t_ulong)*cpy) - LO) & ~((t_ulong)*cpy) & HI))
		cpy += 8;
	while (*cpy)
		cpy++;
	return (cpy - str);
}

t_ullong		ft_pow(t_uint mul, t_uint pow)
{
	t_ullong	res;

	res = 1;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (mul);
	while (pow > 0)
	{
		if (pow % 2)
			res *= mul;
		mul *= mul;
		pow /= 2;
	}
	return (res);
}
