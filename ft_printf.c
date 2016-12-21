/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:03:19 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:01:50 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	t_option 	st;
	int			ret;
	int			size;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s = string_format(&format, &st, ap, &size);
			write(1, s, size);
			ret += size;
			free(s);
		}
		else
		{
			ft_putchar(*format);
			ret++;
			format++;
		}
	}
	va_end(ap);
	return (ret);
}
