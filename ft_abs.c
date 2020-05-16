/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:24:45 by askobins          #+#    #+#             */
/*   Updated: 2020/05/15 18:38:30 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_ullong	ft_abs(t_llong nb)
{
	return (nb > 0 ? (t_ullong)nb : (t_ullong)-nb);
}