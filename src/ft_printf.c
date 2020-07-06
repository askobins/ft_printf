/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 00:50:05 by askobins          #+#    #+#             */
/*   Updated: 2020/07/06 21:11:26 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

static char		*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c && (t_ullong)str & 7)
		str++;
	while (!((((t_ulong)str) - LO) & ~((t_ulong)str) & HI) &&
			!(((((t_ulong)str) ^ LO * (c)) - LO)
				& ~(((t_ulong)str) ^ LO * (c)) & HI))
		str += 8;
	while (*str && *str != c)
		str++;
	return (*str == c ? (char *)str : NULL);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		vars;
	char		*cpy;
	int			ret;

	va_start(vars, fmt);
	ret = 0;
	while ((cpy = ft_strchr(fmt, '%')))
	{
		if (fmt != cpy)
			ret += write(1, fmt, cpy - fmt);
		fmt = cpy;
		ret += handle(&fmt, vars, ret);
		fmt++;
	}
	ret += write(1, fmt, ft_strlen(fmt));
	va_end(vars);
	return (ret);
}
