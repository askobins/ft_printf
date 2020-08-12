/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:15:19 by askobins          #+#    #+#             */
/*   Updated: 2020/08/12 16:45:15 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define LO 0x0101010101010101ULL
# define HI 0x8080808080808080ULL

# define B2SET    "01"
# define B8SET    "01234567"
# define B10SET   "0123456789"
# define B16SETLO "0123456789abcdef"
# define B16SETUP "0123456789ABCDEF"

# define MUL 1
# define DIV 0

typedef long long			t_llong;

typedef unsigned char		t_uchar;

typedef unsigned int		t_uint;

typedef unsigned long		t_ulong;

typedef unsigned long long	t_ullong;

typedef struct	s_flags
{
	union
	{
		t_uchar			val;
		struct
		{
			unsigned	lft : 1;
			unsigned	zro : 1;
			unsigned	spc : 1;
			unsigned	pls : 1;
			unsigned	cap : 1;
			unsigned	pre : 1;
			unsigned	alt : 1;
			unsigned	ext : 1;
		};
	};
}				t_flags;

typedef union
{
	double		nb;
	struct {
		t_ulong	mant : 52;
		t_uint	expo : 11;
		t_uint	sign : 1;
	}			raw;
}				t_floatlong;

t_flags			g_flags;

t_ullong		ft_abs(t_llong nb);

t_uint			ft_is_in(t_ullong a, char b);

t_ullong		ft_pow(t_uint mul, t_uint pow);

size_t			ft_putfloat(double nb, t_uint exp, t_uint p);

size_t			ft_putlong(t_ullong nb, const t_uint base);

t_uint			ft_strlen(const char *str);

void			h_align(size_t size, char c);

t_uint			h_numlen(t_ullong nb, int base);

double			h_muldiv(double nb, t_uint exp, t_uchar op);

t_ullong		h_usub(t_ullong a, t_ullong b);

size_t			handle(const char **str, va_list vars, int nb);

size_t			p_char(const char c, size_t w);

size_t			p_float(double nb, t_uint *wp);

size_t			p_int(t_llong nb, t_uint *wp, t_ullong mask);

size_t			p_string(const char *str, t_uint *wp);

size_t			p_uint(t_ullong nb, t_uint *wp, const t_uint base);

int				ft_printf(const char *fmt, ...);

#endif
