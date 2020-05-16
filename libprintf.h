/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:15:19 by askobins          #+#    #+#             */
/*   Updated: 2020/05/16 21:29:37 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>

# define LO 0x0101010101010101UL
# define HI 0x8080808080808080UL

# define LFT 0
# define ZRO 1
# define SPC 2
# define ALT 3
# define PLS 4
# define GRP 5
# define PRE 6
# define CAP 7

typedef long long			t_llong;

typedef unsigned char		t_uchar;

typedef unsigned int		t_uint;

typedef unsigned long		t_ulong;

typedef unsigned long long	t_ullong;

typedef union {
	double		nb;
	t_ullong	bits;
}				t_conv;

size_t			ft_strlen(const char *str);

char			*ft_strchr(const char *str, int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

void			ft_putlong(t_ullong nb);

void			ft_putchar(char c);

void			ft_putstr(char const *str);

t_ullong		ft_abs(t_llong nb);

void			h_align(size_t size, char c);

t_llong			h_mask(t_llong nb, t_llong mask);

t_ullong		h_usub(t_ullong a, t_ullong b);

t_uint			h_numlen(t_ullong nb, int base);

void			p_itypes(t_llong nb, t_uchar flags, size_t *wp);

void			p_char(const char c, t_uchar flags, size_t w);

void			p_string(const char *str, t_uchar flags, size_t *wp);

#endif
