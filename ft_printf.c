/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/05/21 13:18:52 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define FLAG "-+ 0'#"
#define NOSIGN "iopuxX"
#define DOUBLE "aefgAEFG"

#define MCHR 0x00000000000000ffUL
#define MSHT 0x000000000000ffffUL
#define MINT 0x00000000ffffffffUL
#define MLNG 0xffffffffffffffffUL

static t_uchar	g_flags(const char **str)
{
	t_uchar flags;

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

static size_t	*g_numbers(const char **str, va_list vars, t_uchar *flags)
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

static t_ulong	g_length(const char **str)
{
	t_ulong	mask;

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

static size_t	handle(const char **str, va_list vars)
{
	t_uchar	flags;
	size_t	*wp;
	t_ulong	mask;

	flags = g_flags(str);
	wp = g_numbers(str, vars, &flags);
	mask = g_length(str);
	if (**str == '%' && !flags && !wp[0] && wp[1] == ~0UL && mask == MINT)
		return (write(1, *str, 1));
	if (**str == 'c')
		return (p_char(va_arg(vars, char), flags, wp[0]));
	if (**str == 's')
		return (p_string(va_arg(vars, char *), flags, wp));
	if (**str == 'd' || **str == 'i')
		return (p_itypes(h_mask(va_arg(vars, long long), mask), flags, wp));
}

ssize_t			ft_printf(const char *str, ...)
{
	va_list		vars;
	char		*ptr;
	ssize_t		ret;

	va_start(vars, str);
	ret = 0;
	while ((ptr = ft_strchr(str, '%')))
	{
		if (str != ptr)
			ret += write(1, str, ptr - str);
		str = ptr;
		ret += handle(&str, vars);
	}
	ret += ft_strlen(str);
	ft_putstr(str);
	va_end(vars);
	return (ret);
}
