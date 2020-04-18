/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:37:09 by askobins          #+#    #+#             */
/*   Updated: 2020/04/18 20:30:31 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/srcs/libft.h"
#include <stdarg.h>
#include <string.h>

#define CONV "cspdiuxXnfge%\0"
#define FLAG "-+ 0'#"


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
#define ZRO 1
#define SPC 2
#define ALT 3
#define PLS 4
#define GRP 5

#define LONG 0
#define LLONG 1
#define CHINT 2
#define SHINT 3

/*size_t	ft_handler(const char **str, va_list vars)
  {
  const char		*ptr;
  unsigned char	flags;
  size_t			width;
  size_t			precision;
  char	length;

  width = 0;
  ptr = str;
  while (ft_strchr(FLAG, *(++ptr)))
  {
  if (*ptr == '-')
  flags |= 1 << LFT;
  if (*ptr == '0')
  flags |= 1 << ZRO;
  if (*ptr == ' ')
  flags |= 1 << SPC;
  if (*ptr == '#')
  flags |= 1 << ALT;
  if (*ptr == '#')
  flags |= 1 << PLS;
  if (*ptr == '#')
  flags |= 1 << GRP;
  }

  if (*ptr == '*')
  {
  width = va_arg(vars, size_t);
  ptr++;
  }
  else
  while (ft_isdigit(*(ptr++)))
  width = width * 10 + (*ptr - 48);

  if (*ptr == '.')
  {
  if (*(ptr + 1) == '*')
  {
  precision = va_arg(vars, size_t);
  ptr++;
  }
  else
  while (ft_isdigit(*(++ptr)))
  precision = precision * 10 + (*ptr - 48);
  }

  if (*ptr == 'h')
  if (*(ptr + 1) == 'h')
  {
  length = 'H';
  ptr++;
  }
  else
  length = 'h';
  else if (*ptr == 'l')
  {
  if (*(ptr + 1) == 'l')
  {
  length = 'L';
  }
  else
  length = 'l';
  }

  return (0);

  }*/

unsigned char ft_flags(const char **str)
{
	unsigned char flags;
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
		if (**str == '#')
			flags |= 1 << PLS;
		if (**str == '#')
			flags |= 1 << GRP;
	}
	return (flags);
}

size_t	*ft_numbers(const char **str, va_list vars)
{
	size_t	pw[2];
	size_t	*cpy;

	pw[0] = 0;
	pw[1] = 0;
	if (**str == '*')
{
	pw[0] = va_arg(vars, size_t);
	(*str)++;
}
	else
while (ft_isdigit(*((*str)++)))
	pw[0] = pw[0] * 10 + (**str - 48);
	if (**str == '.')
	if (*(*str + 1) == '*')
{
	pw[1] = va_arg(vars, size_t);
	(*str)++;
}
	else if (ft_isdigit(*((*str) + 1)))
while (ft_isdigit(*(++(*str))))
	pw[1] = pw[1] * 10 + (**str - 48);
	else
	pw[1] = ~0UL;
	return ((cpy = pw));
	}

unsigned char	ft_length(const char **str)
{
	unsigned char	length;

	if (**str == 'h')
		if (*(*str + 1) == 'h')
		{
			length = 'H';
			ptr++;
		}
		else
			length = 'h';
	else if (**str == 'l')
	{
		if (*(*str + 1) == 'l')
		{
			length = 'L';
		}
		else
			length = 'l';
	}
	return (length);
}

void			ft_handler(const char **str, va_list vars)
{
	unsigned char	flags;
	size_t			*pw;
	unsigned char	length;

	flags = ft_flags(str);
	pw = ft_numbers(str, vars);
	length = ft_length(str);
	if (**str == '%' || **str == 'c')
		ft_char(**str, vars);
	else if (**str == 's')

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
		ft_handler(&str, vars);
	}
	ft_putstr(str);
	va_end(vars);
	return (0);
}
