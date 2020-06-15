/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heavylifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/06/15 02:48:49 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

#define FLAG   "-+ 0#"
#define NOSIGN "opuxX"
#define DOUBLE "efgEFG"
#define CAPS   "EFGX"

#define FLAGBYTES   0x0000002D2B203023ULL
#define NOSIGNBYTES 0x0000006F70757858ULL
#define DOUBLEBYTES 0x0000656667545657ULL
#define CAPSBYTES   0x0000000045565758ULL

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
	while (is_in(FLAGBYTES, **str))
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
		while (**str >= '0' && **str <= '9')
		{
			wp[0] = wp[0] * 10 + (**str - '0');
			str++;
		}
	if (g_flags.pre = (**str == '.'))
		if (++(*str) == '*')
		{
			wp[1] = va_arg(vars, size_t);
			(*str)++;
		}
		else
			while (ft_isdigit(**str))
			{
				wp[1] = wp[1] * 10 + (**str - '0');
				(*str)++;
			}
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

static size_t	handle(const char **str, va_list vars)
{
	size_t		*wp;
	t_ulong		mask;
	const char	*cpy;

	cpy = *str;
	flags(str);
	wp = numbers(str, vars);
	mask = length(str);
	g_flags.cap = !!(is_in(CAPSBYTES, **str));
	if (**str == '%' && *(*str - 1) == '%')
		return (write(1, *str, 1));
	else if (**str == 'c')
		return (p_char(va_arg(vars, char), wp[0]));
	else if (**str == 's')
		return (p_string(va_arg(vars, char *), wp));
	else if (**str == 'd' || **str == 'i')
		return (p_int(va_arg(vars, t_llong), wp, mask));
	else if (is_in(DOUBLEBYTES, **str))
	{
		g_flags.ext = (**str == 'g' || **str == 'G');
		g_flags.pre = (**str == 'e' || **str == 'E');
		return (p_float(va_arg(vars, double), wp));
	}
	else if (is_in(NOSIGNBYTES, **str))
		return (e_nosign(**str, va_arg(vars, t_ullong), wp, mask));
	else
		return ((write(1, cpy, *str - cpy)));
}
