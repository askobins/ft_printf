/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:34:32 by askobins          #+#    #+#             */
/*   Updated: 2020/05/16 22:14:44 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void	ft_putlong(t_ullong nb)
{
	if (nb > 9)
		ft_putlong(nb / 10);
	ft_putchar((nb % 10) + '0');
}

size_t	put_inf_nan(double nb, t_uchar flags, size_t w)
{
	t_conv	u;
	char	neg;

	u.nb = nb;
	neg = '-' * !!(u.bits & (1ULL << 63));
	if (!(flags & (1 << LFT)))
		h_align(h_usub(w, 3 + !!neg), ' ');
	if (neg)
		write(1, &neg, 1);
	if (nb == nb)
		write(1, flags & (1 << CAP) ? "NAN" : "nan", 3);
	else
		write(1, flags % (1 << CAP) ? "INF" : "inf", 3);
	if (flags & (1 << LFT))
		h_align(h_usub(w, 3 + !!neg), ' ');
	return (w ? w : 3 + !!neg);
}
