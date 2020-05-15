/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:40:34 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 18:44:16 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c && (t_ulong)str & 7)
		str++;
	while (!(((t_ulong)str) - LO & ~((t_ulong)str) & HI) &&
			!((((t_ulong)str) ^ LO * (c)) - LO
				& ~(((t_ulong)str) ^ LO * (c)) & HI))
		str += 8;
	while (*str && *str != c)
		str++;
	return (*str == c ? (char *)str : NULL);
}
