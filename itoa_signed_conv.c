/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:06:10 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 12:59:08 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_size(intmax_t n, t_strform st)
{
	int size;

	size = 1;
	if (n == 0 && st.precision == 0)
		return (0);
	while (n >= 10 || n <= -10)
	{
		size++;
		n /= 10;
	}
	if (size < st.precision)
		return (st.precision);
	return (size);
}

static int	get_itoa_size(intmax_t n, int size_n, t_strform st)
{
	int size;

	size = size_n;
	if (st.flag.sign != 0 || n < 0)
		size++;
	if (st.field_width > size)
		size = st.field_width;
	return (size);
}

static int	apply_option(intmax_t n, char *s, t_strform st, t_nconv info)
{
	int		i;
	int		j;

	j = (st.flag.sign != 0 || n < 0 ? 1 : 0);
	if (st.flag.left_adjust != 0 || st.flag.zero == '0')
		i = 0;
	else
		i = info.size - info.size_n - 1;
	if (j == 1)
		s[i++] = (n < 0 ? '-' : st.flag.sign);
	if (st.flag.zero != '0')
		i = (st.flag.left_adjust != 0 ? i + info.size_n : 0);
	while (info.size-- > info.size_n + j)
		s[i++] = st.flag.zero;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_itoa_signed(intmax_t n, t_strform st)
{
	int		i;
	t_nconv	info;
	char	*output;
	char	dig[10];

	ft_strncpy(dig, "0123456789", 10);
	info.size_n = get_number_size(n, st);
	info.size = get_itoa_size(n, info.size_n, st);
	if (!(output = ft_strnew(info.size)))
		return (NULL);
	i = apply_option(n, output, st, info);
	while (info.size_n > 0)
	{
		output[info.size_n - 1 + i] = dig[ft_abs(n % 10)];
		info.size_n--;
		n /= 10;
	}
	return (output);
}
