/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conv_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:57:25 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:01:30 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_signed_conv(t_option st)
{
	if (st.id == 'd' || st.id == 'i' || st.id == 'D')
		return (1);
	return (0);
}

int		is_unsigned_conv(t_option st)
{
	if (is_octal_conv(st) || is_hexa_conv(st) || st.id == 'u'
			|| st.id == 'U')
		return (1);
	return (0);
}
