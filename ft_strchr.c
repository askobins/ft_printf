/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:40:34 by askobins          #+#    #+#             */
/*   Updated: 2020/06/03 17:04:42 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c && (t_ullong)str & 7)
		str++;
	while (!(((t_ullong)str) - LO & ~((t_ullong)str) & HI) &&
			!((((t_ullong)str) ^ LO * (c)) - LO
				& ~(((t_ullong)str) ^ LO * (c)) & HI))
		str += 8;
	while (*str && *str != c)
		str++;
	return (*str == c ? (char *)str : NULL);
}
