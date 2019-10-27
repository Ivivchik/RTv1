/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 03:39:41 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/27 19:19:23 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		valid_intens(double n)
{
	if (n > 1 || n < 0)
		ft_print_error_exit(&ft_putendl, "Error, incorrect intens");
	else
		n = (double)n;
	return (n);
}

double		valid_radius(double n)
{
	if (n < 0)
		ft_print_error_exit(&ft_putendl, "Error, incorrect radius");
	else
		n = (double)n;
	return (n);
}

double		valid_blesk(double n)
{
	if (n < 0 || n > 1000)
		ft_print_error_exit(&ft_putendl, "Error, incorrect blesk");
	else
		n = (double)n;
	return (n);
}
