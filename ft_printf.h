/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:04:58 by epillot           #+#    #+#             */
/*   Updated: 2016/12/13 17:38:07 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_flag
{
	int			convert;
	char		zero;
	int			left_adjust;
	int			space;
	char		sign;
}				t_flag;

typedef struct	s_length
{
	int			h;
	int			l;
	int			j;
	int			z;
}				t_length;

typedef struct	s_strform
{
	t_flag		flag;
	int			field_width;
	int			precision;
	t_length	length;
	char		convert_id;
}				t_strform;

typedef struct	s_nconv
{
	int size_n;
	int size;
}		t_nconv;

int				is_convert_id(const char c);
int				is_flag(const char c);
int				is_length_info(const char c);
int				is_format_info(const char c);
void			fill_strform(const char **format, t_strform *st_format);
char			*string_format(const char **s, t_strform *st, va_list ap);
intmax_t		get_param_for_signed_conv(va_list ap, t_strform *st);
uintmax_t		get_param_for_unsigned_conv(va_list ap, t_strform *st);
int				number_size(int n, int base);
char			*ft_itoa_signed_conv(intmax_t n, t_strform *st);

#endif
