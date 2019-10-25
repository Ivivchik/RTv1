/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:39:41 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:44:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		valid_intens(double n)
{
	if (n > 1)
		n = 1;
	else if (n < 0)
		n = 0;
	else
		n = (double)n;
	return (n);
}

double		valid_radius(double n)
{
	if (n < 0)
		n = 0;
	else
		n = (double)n;
	return (n);
}

double		valid_blesk(double n)
{
	if (n < 0)
		n = 0;
	else
		n = (double)n;
	return (n);
}
