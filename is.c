/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:20:02 by askobins          #+#    #+#             */
/*   Updated: 2020/06/09 18:08:27 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static inline int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

inline int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

inline int				ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

inline int				is_inf(double nb)
{
	t_floatlong	u;

	u.nb = nb;
	return (u.raw & (-1ULL >> 1) >= 0x7ffULL << 52);
}
