/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:06:10 by epillot           #+#    #+#             */
/*   Updated: 2016/12/13 20:07:35 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_size(intmax_t n, int base)
{
	int size;

	size = 1;
	while (n >= base || n <= -base)
	{
		size++;
		n /= base;
	}
	return (size);
}

static int	get_itoa_size(intmax_t n, int size_n, t_strform *st)
{
	int size;

	size = size_n;
	if (st->flag.space == 1 || st->flag.sign == 1 || n < 0)
		size++;
	if (st->precision > size_n)
		size += st->precision - size_n;
	if (st->field_width > size)
		size = st->field_width;
	return (size);
}

static int	apply_option(intmax_t n, char *s, t_strform *st, int base)
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		size_n;

	size_n = get_number_size(n, base);
	size = get_itoa_size(n, size_n, st);
	k = size;
	j = (st->flag.sign != 0 || n < 0 ? 1 : 0);
	i = (st->flag.left_adjust == 0 ? 0 : ft_max(size_n, st->precision) + j);
	if (j == 1 && st->flag.zero == '0')
		i++;
	while (size-- > ft_max(size_n, st->precision) + j)
		s[i++] = st->flag.zero;
	i = (st->flag.left_adjust == 0 && st->flag.zero != '0' ? i : 0);
	if (j == 1)
		s[i++] = (n < 0 ? '-' : st->flag.sign);
	while (size_n < st->precision)
	{
		s[i++] = '0';
		st->precision--;
	}
	return (st->flag.zero == '0' ? k - size_n : i);
}

char		*ft_itoa_base_signed_conv(intmax_t n, int base, t_strform *st)
{
	int		i;
	int		size_n;
	char	*output;
	char	dig[16];

	ft_strncpy(dig, "0123456789ABCDEF", base);
	size_n = get_number_size(n, base);
	i = get_itoa_size(n, size_n, st);
	if (!(output = ft_strnew(i)))
		return (NULL);
	i = apply_option(n, output, st, base);
	while (size_n - 1 >= 0)
	{
		output[size_n - 1 + i] = dig[ft_abs(n % base)];
		size_n--;
		n /= base;
	}
	return (output);
}
