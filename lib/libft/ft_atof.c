/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:57:59 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 00:02:12 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	uint8_t		neg;
	uint8_t		point;
	unsigned	fac;
	double		out;

	out = 0;
	fac = 1;
	point = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if ((neg = *str == '-') || *str == '+')
		++str;
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !point))
	{
		if (*str == '.')
		{
			point = 1;
			++str;
			continue ;
		}
		if (point)
			fac *= 10;
		out = out * 10.0f + (double)(*str++ - '0');
	}
	return ((neg ? -out : out) / fac);
}
