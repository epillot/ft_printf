/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:46:48 by epillot           #+#    #+#             */
/*   Updated: 2016/12/13 16:58:46 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_strform(t_strform *st)
{
	ft_bzero(st, sizeof(t_strform));
	st->flag.zero = ' ';
	st->precision = -1;
}

static void	adjust_strform(t_strform *st)
{
	if (st->precision != -1 || st->flag.left_adjust == 1)
		st->flag.zero = ' ';
	if (st->flag.space == 1 && st->flag.sign == 0)
		st->flag.sign = ' ';
	else if (st->flag.sign == 1)
		st->flag.sign = '+';
}

void		signed_int_convert(char **str, t_strform *st, va_list ap)
{
	intmax_t	n;

	n = get_param_for_signed_conv(ap, st);
	*str = ft_itoa_base_signed_conv(n, 10, st);
}

char		*string_format(const char **s, t_strform *st, va_list ap)
{
	char	*str;

	init_strform(st);
	fill_strform(s, st);
	adjust_strform(st);
	if (st->convert_id == 'd' || st->convert_id == 'i' || st->convert_id == 'D')
		signed_int_convert(&str, st, ap);
	else
		str = ft_strdup("");
	return (str);
}
