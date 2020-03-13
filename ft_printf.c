/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/03/06 20:03:08 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>

#define CONV "" //cspdiuxXnfge%\0
#define FLAG "" //-0.*#+lh 


#define CHR 1
#define STR 2
#define PTR 3
#define INT 4
#define UINT 5
#define HEX 6
#define CHEX 7
#define NOT 8
#define FFLOAT 9
#define EFLOAT 10
#define AFLOAT 11
#define MOD 12


#define LFT 0
#define ZERO 1
#define SPC 2
#define ALT 3

#define LONG 6
#define LLONG 7
#define CHINT 8
#define SHINT 9

size_t	ft_handler(const char *str, va_list vars)
{
	const char		*ptr;
	int				val;
	unsigned char	opt;
	size_t			width;
	size_t			precision;
	size_t			size;

	width = 0;
	ptr = str;
	while (ft_strchr(FLAG, *(++ptr)))
	{
		if (*ptr == '-')
			opt |= 1 << LFT;
		if (*ptr == '0')
			opt |= 1 << ZERO;
		if (*ptr == ' ')
			opt |= 1 << SPC;
		if (*ptr == '#')
			opt |= 1 << ALT;
	}
	if (*ptr == '*')
	{
		width = va_arg(vars, size_t);
		ptr++;
	}
	else
		while (ft_isnum(*(ptr++)))
			width = width * 10 + (*ptr - 48);
	if (*ptr == '.')
	{
		if (*(ptr + 1) == '*')
		{
			precision = va_arg(vars, size_t);
			ptr++;
		}
		else
			while (ft_isnum(*(++ptr)))
				precision = precision * 10 + (*ptr - 48);
	}
	while (*ptr == 'h' || *ptr == 'l')
	{

		ptr++;
	}
	return (ptr - str);
}

int		ft_printf(const char *str, ...)
{
	va_list		vars;
	char		*ptr;

	va_start(vars, str);
	while ((ptr = ft_strchr(str, '%')))
	{
		if (str != ptr)
			write (1, str, str - ptr);
		str += ft_handler(str, vars);
	}
	ft_putstr(str);
	va_end(vars);
	return (0);
}
