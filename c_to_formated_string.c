/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_to_formated_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:21:49 by epillot           #+#    #+#             */
/*   Updated: 2016/12/21 18:16:03 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_to_formated_string(unsigned char c, t_option st, int *n)
{
	char	*output;
	int		size;
	int		i;

	size = 1;
	if (st.field_width > 1)
		size = st.field_width;
	*n = size;
	if (!(output = ft_strnew(size)))
		return (NULL);
	i = (st.flag.left_adjust == 1 ? 1 : 0);
	while (size-- > 1)
		output[i++] = st.flag.width;
	if (st.flag.left_adjust == 1)
		i = 0;
	output[i] = (char)c;
	return (output);
}
