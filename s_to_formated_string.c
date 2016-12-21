/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_formated_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:04:09 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:05:48 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_s_size(char *s, t_option *st)
{
	int	size;

	size = ft_strlen(s);
	if (st->precision == -1)
		st->precision = 2147483647;
	if (st->precision < size)
		return (st->precision);
	return (size);
}

char		*s_to_formated_string(char *s, t_option st, int *n)
{
	char	*output;
	int		size;
	int		size_s;
	int		i;
	int		alloc;

	alloc = 0;
	if (s == NULL)
		s = "(null)";
	size_s = get_s_size(s, &st);
	size = size_s;
	if (size_s < st.field_width)
		size = st.field_width;
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? size_s  : 0);
	while (size-- > size_s)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	while (size_s-- > 0)
		output[i++] = *s++;
	return (output);
}
