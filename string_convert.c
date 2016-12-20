/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:22:43 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 15:46:01 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_int_convert(char **str, t_strform st, va_list ap)
{
	intmax_t	n;

	n = get_param_for_signed_conv(ap, st);
	*str = ft_itoa_signed(n, st);
}

void	unsigned_int_convert(char **str, t_strform st, va_list ap)
{
	uintmax_t	n;
	int			base;

	n = get_param_for_unsigned_conv(ap, st);
	base = get_base(st);
	*str = ft_itoa_base_unsigned(n, base, st);
}

void	char_convert(char **str, t_strform st, va_list ap)
{
	wint_t	c;

	c = get_param_for_char_conv(ap, st);
	*str = char_to_formated_string(c, st);
}
