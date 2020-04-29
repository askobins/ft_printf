/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_types.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:14:04 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 12:01:50 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	p_int(long long nb, unsigned char flags, size_t *wp)
{
	if (flags & (1 << LFT))
	{
		ft_putlong(nb);
		g_align();
	}
	if (nb >= 0 && (flags & (1 << PLS) || flags & (1 << SPC)))
		write(1, flags & (1 << PLS) ? "+" : " ", 1);
	
}
