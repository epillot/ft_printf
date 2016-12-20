/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:25:15 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 15:43:12 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	encode_unicode(wint_t c, int i, char *s)
{
	if (c <= 0x7f)
		s[i] = (char)c;
	else if (c >= 0x80 && c <= 0x7ff)
	{
		s[i++] = (char)(0xc0 | (c >> 6));
		s[i] = (char)(0x80 | (0x3f & c));
	}
	else if (c >= 0x800 && c <= 0xffff)
	{
		s[i++] = (char)(0xe0 | (0xf & (c >> 12)));
		s[i++] = (char)(0x80 | (0x3f & (c >> 6)));
		s[i] = (char)(0x80 | (0x3f & c));
	}
	else if (c >= 0x10000 && c <= 0x10ffff)
	{
		s[i++] = (char)(0xf0 | (0x7 & (c >> 18)));
		s[i++] = (char)(0x80 | (0x3f & (c >> 12)));
		s[i++] = (char)(0x80 | (0x3f & (c >> 6)));
		s[i] = (char)(0x80 | (0x3f & c));
	}
}
