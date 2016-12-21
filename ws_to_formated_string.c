/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_to_formated_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:59:45 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:14:06 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  get_wchar_size(wchar_t c)
{
	if (c <= 0x7f)
		return (1);
	if (c >= 0x80 && c <= 0x7ff)
		return (2);
	if (c >= 0x800 && c <= 0xffff)
		return (3);
	if (c >= 0x10000 && c <= 0x10ffff)
		return (4);
	return (0);
}

static int	get_ws_size(wchar_t *s, t_option *st)
{
	int size;
	int prec;

	size = 0;
	if (st->precision == -1)
		st->precision = 2147483647;
	prec = st->precision;
	while (*s && prec > 0)
	{
		size += get_wchar_size(*s);
		prec -= get_wchar_size(*s);
		s++;
	}
	if (prec < 0)
		size -= get_wchar_size(*--s);
	return (size);
}

char	*ws_to_formated_string(wchar_t *s, t_option st, int *n)
{
	char	*output;
	int		size;
	int		size_ws;
	int		i;

	if (s == NULL)
		return (s_to_formated_string((char*)s, st, n));
	size_ws = get_ws_size(s, &st);
	size = size_ws;
	if (size_ws < st.field_width)
		size = st.field_width;
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? size_ws  : 0);
	while (size-- > size_ws)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	while (size_ws > 0)
	{
		encode_unicode(*s, &i, output);
		size_ws -= get_wchar_size(*s);
		s++;
	}
	return (output);
}
