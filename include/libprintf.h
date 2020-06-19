/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:15:19 by askobins          #+#    #+#             */
/*   Updated: 2020/06/19 17:11:18 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

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

typedef long long			t_llong;

typedef unsigned char		t_uchar;

typedef unsigned int		t_uint;

typedef unsigned long		t_ulong;

typedef unsigned long long	t_ullong;

typedef struct	s_flags{
	t_uchar	lft : 1;
	t_uchar	zro : 1;
	t_uchar	spc : 1;
	t_uchar	alt : 1;
	t_uchar	pls : 1;
	t_uchar	cap : 1;
	t_uchar	pre : 1;
	t_uchar	ext : 1;
}				t_flags;

typedef union {
	double		nb;
	t_ullong	raw;
}				t_floatlong;

typedef union {
	t_flags		flags;
	t_uchar		raw;
}	t_flagschar;

t_flags			g_flags;

t_ullong		ft_abs(t_llong nb);

t_uint			ft_is_in(t_ullong a, char b);

void			ft_putlong(t_ullong nb, const char *charset);

size_t			ft_strlen(const char *str);

void			h_align(size_t size, char c);

t_uint			h_numlen(t_ullong nb, int base);

t_ullong		h_usub(t_ullong a, t_ullong b);

size_t			handle(const char **str, va_list vars, int nb);

size_t			p_char(const char c, size_t w);

size_t			p_float(double nb, size_t *wp);

size_t			p_int(t_llong nb, size_t *wp, t_ullong mask);

size_t			p_string(const char *str, size_t *wp);

size_t			p_uint(t_ullong nb, size_t *wp, const char *charset);

#endif
