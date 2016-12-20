/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:06:26 by epillot           #+#    #+#             */
/*   Updated: 2016/12/15 15:50:38 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag_info(const char c, t_strform *st)
{
	if (c == '#')
		st->flag.conv = 1;
	else if (c == '0')
		st->flag.zero = '0';
	else if (c == '-')
		st->flag.left_adjust = 1;
	else if (c == ' ')
		st->flag.space = 1;
	else if (c == '+')
		st->flag.sign = 1;
}

void	get_length_info(const char c, t_strform *st)
{
	if (c == 'h')
		st->length.h++;
	else if (c == 'l')
		st->length.l++;
	else if (c == 'j')
		st->length.j = 1;
	else if (c == 'z')
		st->length.z = 1;
}

void	get_precision(const char **format, t_strform *st)
{
	(*format)++;
	if (ft_isdigit(**format))
		st->precision = ft_atoi(*format);
	else
		st->precision = 0;
	while (ft_isdigit(**format))
		(*format)++;
	(*format)--;
}

void	fill_strform(const char **format, t_strform *st)
{
	while (is_format_info(**format))
	{
		if (is_flag(**format))
			get_flag_info(**format, st);
		else if (is_length_info(**format))
			get_length_info(**format, st);
		else if (ft_isdigit(**format))
		{
			st->field_width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		else if (**format == '.')
			get_precision(format, st);
		(*format)++;
	}
	st->id = (is_convert_id(**format) ? **format : 0);
	if (st->id)
		(*format)++;
}
