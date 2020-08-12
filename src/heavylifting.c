/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heavylifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/08/12 16:45:57 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define FLAGBYTES   0x0000002D2B203023ULL
#define NOSIGNBYTES 0x0062426F70757858ULL
#define DOUBLEBYTES 0x0000656667545657ULL
#define CAPSBYTES   0x0000000045565758ULL

#define MCHR UCHAR_MAX
#define MSHT USHRT_MAX
#define MINT UINT_MAX
#define MLNG ULONG_MAX
#define MLLG ULLONG_MAX

static void		flags(const char **str)
{
	g_flags.val = 0;
	while (ft_is_in(FLAGBYTES, **str))
	{
		if (**str == '-')
			g_flags.lft = 1;
		else if (**str == '0')
			g_flags.zro = 1;
		else if (**str == ' ')
			g_flags.spc = 1;
		else if (**str == '#')
			g_flags.alt = 1;
		else if (**str == '+')
			g_flags.pls = 1;
		(*str)++;
	}
}

static t_uint	*numbers(const char **str, va_list vars)
{
	static t_uint	wp[2];

	wp[0] = 0;
	wp[1] = 0;
	if (**str == '*')
	{
		(*str)++;
		g_flags.lft |= ((int)(wp[0] = va_arg(vars, int)) < 0);
		wp[0] = ft_abs((int)wp[0]);
	}
	else
		while (**str >= '0' && **str <= '9')
			wp[0] = wp[0] * 10 + (*((*str)++) - '0');
	if ((g_flags.pre = (**str == '.')))
	{
		if (*(++(*str)) == '*')
		{
			(*str)++;
			g_flags.pre -= ((int)(wp[1] = va_arg(vars, int)) < 0);
		}
		else
			while (**str >= '0' && **str <= '9')
				wp[1] = wp[1] * 10 + (*((*str)++) - '0');
	}
	return (wp);
}

static t_ullong	length(const char **str)
{
	if (**str == 'h')
		if (*(++(*str)) == 'h')
		{
			(*str)++;
			return ((t_ullong)MCHR);
		}
		else
			return ((t_ullong)MSHT);
	else if (**str == 'l')
		if (*(++(*str)) == 'l')
		{
			(*str)++;
			return ((t_ullong)MLLG);
		}
		else
			return ((t_ullong)MLNG);
	else
		return ((t_ullong)MINT);
}

static size_t	cont(char p, va_list vars, t_uint *wp, t_ullong mask)
{
	t_uint base;

	if (ft_is_in(DOUBLEBYTES, p))
	{
		g_flags.ext = (p == 'g' || p == 'G');
		g_flags.alt = (p == 'e' || p == 'E');
		return (p_float(va_arg(vars, double), wp));
	}
	if (p == 'b' || p == 'B')
		base = 2;
	else if (p == 'o')
		base = 8;
	else if (p == 'u')
		base = 10;
	else
		base = 16;
	if (p == 'p')
	{
		g_flags.alt = 1;
		mask = MLLG;
	}
	return (p_uint(va_arg(vars, t_ullong) & mask, wp, base));
}

size_t			handle(const char **str, va_list vars, int nb)
{
	t_uint		*wp;
	t_ullong	mask;
	const char	*cpy;

	cpy = *str;
	(*str)++;
	flags(str);
	wp = numbers(str, vars);
	mask = length(str);
	g_flags.cap = ft_is_in(CAPSBYTES, **str);
	if (**str == 's')
		return (p_string(va_arg(vars, char *), wp));
	else if (**str == 'n')
		return ((*va_arg(vars, int *) = nb) * 0);
	else if (**str == 'c' || **str == '%')
		return (p_char(**str == '%' ? '%' : va_arg(vars, int), wp[0]));
	else if (**str == 'd' || **str == 'i')
		return (p_int(va_arg(vars, t_ullong), wp, mask));
	else if (ft_is_in(DOUBLEBYTES, **str) || ft_is_in(NOSIGNBYTES, **str))
		return (cont(**str, vars, wp, mask));
	else
		return (write(1, cpy, *str - cpy));
}
