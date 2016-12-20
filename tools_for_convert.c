/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:03:33 by epillot           #+#    #+#             */
/*   Updated: 2016/12/15 16:39:13 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_octal_conv(t_strform st)
{
	return (st.id == 'o' || st.id == 'O');
}

int		is_hexa_conv(t_strform st)
{
	return (st.id == 'x' || st.id == 'X' || st.id == 'p');
}

int		get_base(t_strform st)
{
	if (st.id == 'u' || st.id == 'U')
		return (10);
	if (is_octal_conv(st))
		return (8);
	if (is_hexa_conv(st))
		return (16);
	return (0);
}

char		*ft_strupcase(char *s)
{
	int i;
	
	i = 0;
	while (*(s + i))
	{
		*(s + i) = ft_toupper(*(s + i));
		i++;
	}
	return (s);
}
