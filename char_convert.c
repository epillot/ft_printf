/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:09:52 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 17:49:37 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wc_convert(char **str, t_option st, va_list ap, int *size)
{
	wint_t	c;

	c = va_arg(ap, wint_t);
	*str = wc_to_formated_string(c, st, size);
}

void	c_convert(char **str, t_option st, va_list ap, int *size)
{
	unsigned char c;

	if (st.id == 'c')
		c = (unsigned char)va_arg(ap, int);
	else
		c = '%';
	*str = c_to_formated_string(c, st, size);
}

void	ws_convert(char **str, t_option st, va_list ap, int *size)
{
	wchar_t	*s;

	s = va_arg(ap, wchar_t*);
	*str = ws_to_formated_string(s, st, size);
}

void	s_convert(char **str, t_option st, va_list ap, int *size)
{
	char	*s;

	s = va_arg(ap, char*);
	*str = s_to_formated_string(s, st, size);
}
