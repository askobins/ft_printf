/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:20:02 by askobins          #+#    #+#             */
/*   Updated: 2020/05/12 16:13:56 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}