/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conv_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:57:25 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 15:47:10 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_signed_conv(t_strform st)
{
	if (st.id == 'd' || st.id == 'i' || st.id == 'D')
		return (1);
	return (0);
}

int		is_unsigned_conv(t_strform st)
{
	if (is_octal_conv(st) || is_hexa_conv(st) || st.id == 'u'
			|| st.id == 'U')
		return (1);
	return (0);
}

int		is_char_conv(t_strform st)
{
	if (st.id == 'c' || st.id == 'C' || st.id == '%')
		return (1);
	return (0);
}
