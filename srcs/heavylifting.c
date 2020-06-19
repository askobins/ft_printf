/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heavylifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 16:40:52 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

#define FLAGBYTES   0x0000002D2B203023ULL /*-+ 0#*/
#define NOSIGNBYTES 0x0000006F70757858ULL /*bopuxBX*/
#define DOUBLEBYTES 0x0000656667545657ULL /*efgEFG*/
#define CAPSBYTES   0x0000000045565758ULL /*EFGX*/

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
		*str++;
	}
}

static size_t	*numbers(const char **str, va_list vars)
{
	static size_t	wp[2];

	wp[0] = 0;
	wp[1] = 0;
	if (**str == '*')
	{
		wp[0] = va_arg(vars, size_t);
		(*str)++;
	}
	else
		while (*((*str)++) ^ '0' <= 9)
			wp[0] = wp[0] * 10 + (**str - '0');
	if (g_flags.pre = (**str == '.'))
		if (*++(*str) == '*')
		{
			wp[1] = va_arg(vars, size_t);
			(*str)++;
		}
		else
			while (*++(*str) ^ '0' <= 9)
				wp[1] = wp[1] * 10 + (**str - '0');
	else
		wp[1] = 6;
	return (wp);
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

static size_t	cont(char p, va_list vars, size_t *wp, t_ulong mask)
{
	const char *set;

	if (ft_is_in(DOUBLEBYTES, p))
	{
		g_flags.ext = (p == 'g' || p == 'G');
		g_flags.pre = (p == 'e' || p == 'E');
		return (p_float(va_arg(vars, double), wp));
	}
	else
	{
		if (p == 'b' || p == 'B')
			set = B2SET;
		else if (p == 'o')
			set = B8SET;
		else if (p == 'u')
			set = B10SET;
		else if (p == 'x' || p == 'p')
			set = B16SETLO;
		else if (p == 'X')
			set = B16SETUP;
		return (p_uint(va_arg(vars, t_ullong) & mask, wp, set));
	}
}

size_t			handle(const char **str, va_list vars, int nb)
{
	size_t		*wp;
	t_ulong		mask;
	const char	*cpy;

	cpy = *str;
	flags(str);
	wp = numbers(str, vars);
	mask = length(str);
	g_flags.cap = !!(ft_is_in(CAPSBYTES, **str));
	if (**str == '%' && *(*str - 1) == '%')
		return (write(1, *str, 1));
	else if (**str == 'c')
		return (p_char(va_arg(vars, char), wp[0]));
	else if (**str == 's')
		return (p_string(va_arg(vars, char *), wp));
	else if (**str == 'd' || **str == 'i')
		return (p_int(va_arg(vars, t_llong), wp, mask));
	else if (**str == 'n')
		return ((*va_arg(vars, int *) = nb) * 0);
	else if (ft_is_in(DOUBLEBYTES, **str) || ft_is_in(NOSIGNBYTES, **str))
		return (cont(**str, vars, wp, mask));
	else
		return (write(1, cpy, *str - cpy));
}
