/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 00:50:05 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 16:33:05 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static char		*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c && (t_ullong)str & 7)
		str++;
	while (!ft_is_in((t_ullong)str, c))
		str += 8;
	while (*str && *str != c)
		str++;
	return (*str == c ? (char *)str : NULL);
}

int				ft_printf(const char *str, ...)
{
	va_list		vars;
	char		*ptr;
	int			ret;

	va_start(vars, str);
	ret = 0;
	while ((ptr = ft_strchr(str, '%')))
	{
		if (str != ptr)
			ret += write(1, str, ptr - str);
		str = ptr;
		ret += handle(&str, vars);
	}
	ret += ft_strlen(str);
	write(1, str, ft_strlen(str));
	va_end(vars);
	return (ret);
}
