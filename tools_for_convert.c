/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:03:33 by epillot           #+#    #+#             */
/*   Updated: 2016/12/12 15:01:13 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		number_size(int n, int base);
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
