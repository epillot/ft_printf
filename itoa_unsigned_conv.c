/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_unsigned_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:54:30 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 12:58:00 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_size(uintmax_t n, int base, t_strform *st)
{
	int size;

	size = 1;
	if (n == 0 && st->precision == 0)
	{
		if (is_octal_conv(*st) && st->flag.conv == 1)
			return (1);
		return (0);
	}
	while (n >= (uintmax_t)base)
	{
		size++;
		n /= base;
	}
	if (is_octal_conv(*st) && st->flag.conv == 1 && st->precision <= size)
		return (size + 1);
	if (size < st->precision)
		return (st->precision);
	return (size);
}

static int	get_itoa_size(uintmax_t n, int size_n, t_strform st)
{
	int size;

	size = size_n;
	if (is_hexa_conv(st) && st.flag.conv == 1 && n != 0)
		size += 2;
	if (st.field_width > size)
		size = st.field_width;
	return (size);
}

static int	apply_option(uintmax_t n, char *s, t_strform st, t_nconv info)
{
	int		i;
	int		j;

	j = (is_hexa_conv(st) && st.flag.conv == 1 && n != 0 ? 2 : 0);
	if (st.flag.left_adjust != 0 || st.flag.zero == '0')
		i = 0;
	else if (!j)
		i = info.size - info.size_n - 1;
	else
		i = info.size - info.size_n - 2;
	if (j == 2)
	{
		s[i++] = '0';
		s[i++] = 'x';
	}
	if (st.flag.zero != '0')
		i = (st.flag.left_adjust != 0 ? i + info.size_n : 0);
	while (info.size-- > info.size_n + j)
		s[i++] = st.flag.zero;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_itoa_base_unsigned(uintmax_t n, int base, t_strform st)
{
	int		i;
	t_nconv	info;
	char	*output;
	char	dig[16];

	ft_strncpy(dig, "0123456789abcdef", base);
	info.size_n = get_number_size(n, base, &st);
	info.size = get_itoa_size(n, info.size_n, st);
	if (!(output = ft_strnew(info.size)))
		return (NULL);
	i = apply_option(n, output, st, info);
	while (info.size_n > 0)
	{
		output[info.size_n - 1 + i] = dig[ft_abs(n % base)];
		info.size_n--;
		n /= base;
	}
	return (st.id == 'X' ? ft_strupcase(output) : output);
}
