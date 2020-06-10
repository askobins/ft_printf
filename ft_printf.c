/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/06/10 16:08:03 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define FLAG   "-+ 0#"
#define NOSIGN "iopuxX"
#define DOUBLE "aefgAEFG"

#define MCHR UCHAR_MAX
#define MSHT USHRT_MAX
#define MINT UINT_MAX
#define MLNG ULONG_MAX
#define MLLG ULLONG_MAX

static void		flags(const char **str)
{
	t_flagschar	u;

	u.flags = g_flags;
	u.raw = 0;
	while (ft_strchr(FLAG, **str))
	{
		if (**str == '-')
			g_flags.lft = 1;
		if (**str == '0')
			g_flags.zro = 1;
		if (**str == ' ')
			g_flags.spc = 1;
		if (**str == '#')
			g_flags.alt = 1;
		if (**str == '+')
			g_flags.pls = 1;
	}
}

static size_t	*numbers(const char **str, va_list vars)
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
	if (g_flags.pre = (**str == '.'))
		if (*(*str + 1) == '*')
		{
			wp[1] = va_arg(vars, size_t);
			(*str)++;
		}
		else
			while (ft_isdigit(*(++(*str))))
				wp[1] = wp[1] * 10 + (**str - '0');
	else
		wp[1] = 6;
	return ((cpy = wp));
}

static t_ulong	length(const char **str)
{
	t_ullong	mask;

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
		{
			mask = MLLG;
			(*str)++;
		}
		else
			mask = MLNG;
	}
	return (mask);
}

static size_t	handle(const char **str, va_list vars)
{
	size_t	*wp;
	t_ulong	mask;

	flags(str);
	wp = numbers(str, vars);
	mask = length(str);
	if (**str == '%' && *(*str - 1) == '%')
		return (write(1, *str, 1));
	if (**str == 'c')
		return (p_char(va_arg(vars, char), wp[0]));
	if (**str == 's')
		return (p_string(va_arg(vars, char *), wp));
	if (**str == 'd' || **str == 'i')
		return (p_itypes(h_mask(va_arg(vars, t_llong), mask), wp));
}

int				ft_printf(const char *str, ...)
{
	va_list		vars;
	char		*ptr;
	int			ret;

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
