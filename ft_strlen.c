/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:45:51 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 18:44:36 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t	ft_strlen(const char *str)
{
	const char	*cpy;

	if (!str)
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
