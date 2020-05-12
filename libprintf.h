/* **********+t**************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 10:13:48 by askobins          #+#    #+#             */
/*   Updated: 2020/05/12 14:23:14 by askobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#define LO 0x0101010101010101UL
#define HI 0x8080808080808080UL

#define LFT 0
#define ZRO 1
#define SPC 2
#define ALT 3
#define PLS 4
#define GRP 5
#define PRE 6
#define CAP 7

size_t		ft_strlen(const char *str);

char		*ft_strchr(const char *str, int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

void		ft_putlong(long long nb);

void		ft_putchar(char c);

void		ft_putstr(char const *str);

void		h_align(size_t size, char c);

long long	h_mask(long long nb, long long mask);

int			h_numlen(long long nb, int base);

void		p_itypes(long long nb, unsigned char flags, size_t *wp);

void		p_char(const char c, unsigned char flags, size_t w);

void		p_string(const char *str, unsigned char flags, size_t *wp);
