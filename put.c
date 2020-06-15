/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:34:32 by askobins          #+#    #+#             */
/*   Updated: 2020/06/13 13:24:03 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	put_long(t_ullong nb, const char *charset, t_uint base)
{
	if (nb > base - 1)
		put_long(nb / base, charset, base);
	write(1, &charset[nb % base], 1);
}

void		ft_putlong(t_ullong nb, const char *charset)
{
	put_long(nb, charset, ft_strlen(charset));
}
