/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:04:58 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 15:47:26 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	int		conv;
	char	zero;
	int		left_adjust;
	int		space;
	char	sign;
}				t_flag;

typedef struct	s_length
{
	int		h;
	int		l;
	int		j;
	int		z;
}				t_length;

typedef struct	s_strform
{
	t_flag		flag;
	int			field_width;
	int			precision;
	t_length	length;
	char		id;
}				t_strform;

typedef struct	s_nconv
{
	int		size;
	int		size_n;
}				t_nconv;

int				is_convert_id(const char c);
int				is_flag(const char c);
int				is_length_info(const char c);
int				is_format_info(const char c);
void			fill_strform(const char **format, t_strform *st);
char			*string_format(const char **s, t_strform *st, va_list ap);
intmax_t		get_param_for_signed_conv(va_list ap, t_strform st);
uintmax_t		get_param_for_unsigned_conv(va_list ap, t_strform st);
wint_t			get_param_for_char_conv(va_list ap, t_strform st);
int				is_signed_conv(t_strform st);
int				is_unsigned_conv(t_strform st);
int				is_char_conv(t_strform st);
int				get_base(t_strform st);
int				is_octal_conv(t_strform st);
int				is_hexa_conv(t_strform st);
char			*ft_itoa_signed(intmax_t n, t_strform st);
char			*ft_itoa_base_unsigned(uintmax_t n, int base, t_strform st);
char			*char_to_formated_string(wint_t c, t_strform st);
void			signed_int_convert(char **str, t_strform st, va_list ap);
void			unsigned_int_convert(char **str, t_strform st, va_list ap);
void			char_convert(char **str, t_strform st, va_list ap);
int				ft_printf(const char *format, ...);
char			*ft_strupcase(char *s);
void			encode_unicode(wint_t c, int i, char *s);

#endif
