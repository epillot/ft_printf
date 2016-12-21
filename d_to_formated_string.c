/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_to_formated_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:16:39 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:00:26 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_size(intmax_t n, t_option st)
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

static int	get_itoa_size(intmax_t n, int size_n, t_option st)
{
	int size;

	size = size_n;
	if (st.flag.sign != 0 || n < 0)
		size++;
	if (st.field_width > size)
		size = st.field_width;
	return (size);
}

static int	apply_option(intmax_t n, char *s, t_option st, t_size size)
{
	int		i;
	int		j;

	j = (st.flag.sign != 0 || n < 0 ? 1 : 0);
	if (st.flag.left_adjust != 0 || st.flag.width == '0')
		i = 0;
	else
		i = size.tot - size.n - 1;
	if (j == 1)
		s[i++] = (n < 0 ? '-' : st.flag.sign);
	if (st.flag.width != '0')
		i = (st.flag.left_adjust != 0 ? i + size.n : 0);
	while (size.tot-- > size.n + j)
		s[i++] = st.flag.width;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*d_to_formated_string(intmax_t n, t_option st, int *nb)
{
	int		i;
	t_size	size;
	char	*output;
	char	dig[10];

	ft_strncpy(dig, "0123456789", 10);
	size.n = get_number_size(n, st);
	size.tot = get_itoa_size(n, size.n, st);
	*nb = size.tot;
	if (!(output = ft_strnew(size.tot)))
		return (NULL);
	i = apply_option(n, output, st, size);
	while (size.n > 0)
	{
		output[size.n - 1 + i] = dig[ft_abs(n % 10)];
		size.n--;
		n /= 10;
	}
	return (output);
}