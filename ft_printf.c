/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:03:19 by epillot           #+#    #+#             */
/*   Updated: 2016/12/23 20:00:35 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strnjoin(char const *s1, char const *s2, int n1, int n2)
{
	int		i;
	char	*new;

	i = -1;
	if (!(new = ft_strnew(n1 + n2)))
		return (NULL);
	new = ft_memcpy(new, s1, n1);
	while (++i < n2)
		new[n1 + i] = s2[i];
	return (new);
}

static int	add_formated_s(const char **format, va_list ap, char **s, int ret)
{
	t_option	st;
	char		*tmp1;
	char		*tmp2;
	int			size;
	int n;

	n = 0;
	(*format)++;
	tmp1 = *s;
	if (!(*s = str_format(format, &st, ap, &size)))
		return (-1);
	if (size == -2)
	{
		size = 0;
		n = 1;
	}
	tmp2 = *s;
	if (!(*s = ft_strnjoin(tmp1, *s, ret, size)))
		return (-1);
	free(tmp1);
	free(tmp2);
	if (n)
		return (-2);
	return (size);
}

static int	add_other_part(const char *format, int ret, char **s)
{
	char	*tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (*(format + i) && *(format + i) != '%')
		i++;
	if (!(*s = ft_strnjoin(*s, format, ret, i)))
		return (-1);
	free(tmp);
	return (i);
}

static int	ft_printf_aux(const char *format, va_list ap)
{
	char		*s;
	int			size;
	int			ret;
	int	*n;

	s = ft_strdup("");
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if ((size = add_formated_s(&format, ap, &s, ret)) == -1)
				return (-1);
			if (size == -2)
			{
				if ((n = va_arg(ap, int*)))
					*n = ret;
				size = 0;
			}
			ret += size;
		}
		else
		{
			if ((size = add_other_part(format, ret, &s)) == -1)
				return (-1);
			ret += size;
			format += size;
		}
	}
	write(1, s, ret);
	free(s);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_printf_aux(format, ap);
	va_end(ap);
	return (ret);
}
