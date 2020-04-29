/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:40:34 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 12:00:07 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c && (unsigned long)str & 7)
		str++;
	while (!(((unsigned long)str) - LO & ~((unsigned long)str) & HI) &&
			!((((unsigned long)str) ^ LO * (c)) - LO
				& ~(((unsigned long)str) ^ LO * (c)) & HI))
		str += 8;
	while (*str && *str != c)
		str++;
	return (*str == c ? (char *)str : NULL);
}
