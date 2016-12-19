/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:03:19 by epillot           #+#    #+#             */
/*   Updated: 2016/12/13 20:06:48 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	t_strform 	st;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s = string_format(&format, &st, ap);
			ft_putstr(s);
			free(s);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	return (1);
}

int main()
{
	ft_printf("%-10.d\n", 0);
	printf("%-10.d\n", 0);
}
