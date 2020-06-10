/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:15:19 by askobins          #+#    #+#             */
/*   Updated: 2020/06/10 16:01:09 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>

# define LO 0x0101010101010101ULL
# define HI 0x8080808080808080ULL

# define B2SET "01"
# define B10SET "0123456789"
# define B16SETLO "0123456789abcdef"
# define B16SETHI "0123456789ABCDEF"


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
	t_uchar	pre : 1;
	t_uchar	cap : 1;
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

t_flags	g_flags;

size_t			ft_strlen(const char *str);

char			*ft_strchr(const char *str, int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

void			ft_putlong(t_ullong nb, t_uint base, const char *charset);

void			ft_putchar(char c);

void			ft_putstr(char const *str);

t_ullong		ft_abs(t_llong nb);

void			h_align(size_t size, char c);

t_llong			h_mask(t_llong nb, t_ullong mask);

t_ullong		h_usub(t_ullong a, t_ullong b);

t_uint			h_numlen(t_ullong nb, int base);

int				is_inf(double nb);

size_t			put_inf_nan(double nb, size_t w);

size_t			p_itypes(t_llong nb, size_t *wp);

size_t			p_char(const char c, size_t w);

size_t			p_string(const char *str, size_t *wp);

#endif
