/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:20:02 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 00:06:42 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

inline t_uint				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

inline t_uint				is_in(t_ullong a, char b)
{
	a ^= LO * b;
	return ((a - LO) & ~a & HI);
}
