/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_format_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:38:22 by epillot           #+#    #+#             */
/*   Updated: 2016/12/15 15:54:03 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_convert_id(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D'
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == '%'
			|| c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

int	is_length_info(const char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int	is_format_info(const char c)
{
	if (is_flag(c) || is_length_info(c) || ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}
