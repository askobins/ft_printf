/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 11:46:07 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define FLAG "-+ 0'#"
#define NOSIGN "iopuxX"
#define DOUBLE "aefgAEFG"

#define MCHR 0x0000000fUL
#define MSHT 0x000000ffUL
#define MINT 0x0000ffffUL
#define MLNG 0xffffffffUL


unsigned char g_flags(const char **str)
{
	unsigned char flags;

	flags = 0;
	while (ft_strchr(FLAG, **str))
	{
		if (**str == '-')
			flags |= 1 << LFT;
		if (**str == '0')
			flags |= 1 << ZRO;
		if (**str == ' ')
			flags |= 1 << SPC;
		if (**str == '#')
			flags |= 1 << ALT;
		if (**str == '+')
			flags |= 1 << PLS;
		if (**str == '\'')
			flags |= 1 << GRP;
	}
	return (flags);
}

size_t	*g_numbers(const char **str, va_list vars, unsigned char *flags)
{
	size_t	wp[2];
	size_t	*cpy;

	wp[0] = 0;
	wp[1] = 0;
	if (**str == '*')
	{
		wp[0] = va_arg(vars, size_t);
		(*str)++;
	}
	else
		while (ft_isdigit(*((*str)++)))
			wp[0] = wp[0] * 10 + (**str - '0');
	if (*flags |= (**str == '.') << PRE)
		if (*(*str + 1) == '*')
		{
			wp[1] = va_arg(vars, size_t);
			(*str)++;
		}
		else
			while (ft_isdigit(*(++(*str))))
				wp[1] = wp[1] * 10 + (**str - '0');
	return ((cpy = wp));
}

unsigned long	g_length(const char **str)
{
	unsigned long	mask;

	mask = MINT;
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h')
		{
			mask = MCHR;
			(*str)++;
		}
		else
			mask = MSHT;
	}
	else if (**str == 'l')
	{
		if (*(*str + 1) == 'l')
			(*str)++;
		mask = MLNG;
	}
	return (mask);
}

void			handle(const char **str, va_list vars)
{
	unsigned char	flags;
	size_t			*wp;
	unsigned long	mask;

	flags = g_flags(str);
	wp = g_numbers(str, vars, &flags);
	mask = g_length(str);
	if (**str == '%' && !flags && !wp[0] && wp[1] == ~0UL && mask == MINT)
		write(1, *str, 1);
	else if (**str == 'c')
		p_char(va_arg(vars, char), flags, wp[0]);
	else if (**str == 's')
		p_string(va_arg(vars, char *), flags, wp);
	else if (**str == 'd' || **str == 'i')
		p_int((va_arg(vars, long long)) & mask, flags, wp);

}

int				ft_printf(const char *str, ...)
{
	va_list		vars;
	char		*ptr;

	va_start(vars, str);
	while ((ptr = ft_strchr(str, '%')))
	{
		if (str != ptr)
			write(1, str, ptr - str);
		str = ptr;
		handle(&str, vars);
	}
	ft_putstr(str);
	va_end(vars);
	return (0);
}
