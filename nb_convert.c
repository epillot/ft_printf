/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:09:13 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:04:45 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_convert(char **str, t_option st, va_list ap, int *size)
{
	intmax_t	n;

	n = get_param_for_signed_conv(ap, st);
	*str = d_to_formated_string(n, st, size);
}

void	u_convert(char **str, t_option st, va_list ap, int *size)
{
	uintmax_t	n;
	int			base;

	n = get_param_for_unsigned_conv(ap, st);
	base = get_base(st);
	*str = u_to_formated_string(n, base, st, size);
}
