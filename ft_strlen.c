/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:45:51 by askobins          #+#    #+#             */
/*   Updated: 2020/06/03 17:05:20 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

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
