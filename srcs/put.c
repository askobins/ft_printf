/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:34:32 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 15:54:53 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	put_long(t_ullong nb, const char *set, const t_uint base)
{

	if (nb > base - 1)
		put_long(nb / base, set, base);
	write(1, &set[nb % base], 1);
}

void		ft_putlong(t_ullong nb, const char *set)
{
	put_long(nb, set, ft_strlen(set));
