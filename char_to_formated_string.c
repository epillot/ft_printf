/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_formated_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:53:14 by epillot           #+#    #+#             */
/*   Updated: 2016/12/20 16:14:27 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_char_size(wint_t c)
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

static int	get_total_size(int size_c, t_strform st)
{
	int size;

	size = size_c;
	if (size < st.field_width)
		size = st.field_width;
	return (size);
}

char		*char_to_formated_string(wint_t c, t_strform st)
{
	char	*output;
	int		size;
	int		size_c;
	int		i;

	size_c = get_char_size(c);
	size = get_total_size(size_c, st);
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? size_c  : 0);
	while (size-- > size_c)
		output[i++] = st.flag.zero;
	if (st.flag.left_adjust == 1)
		i = 0;
	encode_unicode(c, i, output);
	return (output);
}