/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:04:58 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:15:04 by epillot          ###   ########.fr       */
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
	char	width;
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

typedef struct	s_option
{
	t_flag		flag;
	int			field_width;
	int			precision;
	t_length	length;
	char		id;
}				t_option;

typedef struct	s_size
{
	int		n;
	int		tot;
}				t_size;

int				is_convert_id(const char c);
int				is_flag(const char c);
int				is_length_info(const char c);
int				is_format_info(const char c);
void			get_option(const char **format, t_option *st);
char			*string_format(const char **s, t_option *st, va_list ap, int *n);
intmax_t		get_param_for_signed_conv(va_list ap, t_option st);
uintmax_t		get_param_for_unsigned_conv(va_list ap, t_option st);
int				is_signed_conv(t_option st);
int				is_unsigned_conv(t_option st);
int				get_base(t_option st);
int				is_octal_conv(t_option st);
int				is_hexa_conv(t_option st);
char			*d_to_formated_string(intmax_t n, t_option st, int *nb);
char			*u_to_formated_string(uintmax_t n, int base, t_option st, int *nb);
char			*c_to_formated_string(unsigned char c, t_option st, int *n);
char            *wc_to_formated_string(wint_t c, t_option st, int *n);
char			*ws_to_formated_string(wchar_t *s, t_option st, int *n);
char			*s_to_formated_string(char *s, t_option st, int *n);
void			d_convert(char **str, t_option st, va_list ap, int *n);
void			u_convert(char **str, t_option st, va_list ap, int *n);
void			wc_convert(char **str, t_option st, va_list ap, int *n);
void			c_convert(char **str, t_option st, va_list ap, int *size);
void			ws_convert(char **str, t_option st, va_list ap, int *size);
void			s_convert(char **str, t_option st, va_list ap, int *size);
int				ft_printf(const char *format, ...);
char			*ft_strupcase(char *s);
void			encode_unicode(wint_t c, int *i, char *s);

#endif
