/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askobins <askobins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 10:13:48 by askobins          #+#    #+#             */
/*   Updated: 2020/04/29 12:07:08 by askobins         ###   ########.fr       */
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

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c);

int		ft_isdigit(int c);

int		ft_isalpha(int c);

int		ft_isalnum(int c);

void	ft_putlong(long long nb);

void	ft_putchar(char c);

void	ft_putstr(char const *str);

void	h_align(size_t size, char c);

void	p_itypes(long long nb, unsigned char flags, size_t *wp);

void	p_char(const char c, unsigned char flags, size_t w);

void	p_string(const char *str, unsigned char flags, size_t *wp);


