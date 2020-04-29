/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:18:31 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 11:41:58 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_align(size_t size, char c)
{
	unsigned long	tmp;

	tmp = LO * c;
	while (size / 8)
	{
		write(1, &tmp, 8);
		size -= 8;
	}
	while (size / 4)
	{
		write(1, &tmp, 4);
		size -= 4;
	}
	while (size / 2)
	{
		write (1, &tmp, 2);
		size -= 2;
	}
	while (size)
	{
		write(1, &c, 1);
		size--;
	}
}
