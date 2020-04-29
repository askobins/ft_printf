/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:45:51 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 12:00:51 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

size_t	ft_strlen(const char *str)
{
	const char	*cpy;

	if (!str)
		return (0);
	cpy = str;
	while ((unsigned long)cpy & 7 && cpy++)
		if (!*cpy)
			return (cpy - str);
	while (!((((unsigned long)*cpy) - LO) & ~((unsigned long)*cpy) & HI))
		cpy += 8;
	while (*cpy)
		cpy++;
	return (cpy - str);
}
