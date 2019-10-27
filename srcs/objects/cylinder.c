/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:08:46 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/27 19:00:59 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylin		*create_null_list_cylinder(int nbr)
{
	t_cylin	*n;
	int		i;

	if (nbr == 0)
		return (NULL);
	if (!(n = (t_cylin*)malloc(nbr * sizeof(t_cylin))))
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		n[i].radius = 0.0;
		n[i].center = vec_new(0.0, 0.0, 0.0);
		n[i].blesk = 0.0;
		n[i].color = vec_new(0.0, 0.0, 0.0);
		n[i].vector = vec_new(0.0, 0.0, 0.0);
	}
	return (n);
}

t_cylin		cylin_new(t_cylin pars_cylin)
{
	t_cylin		new_cylin;

	new_cylin.center = pars_cylin.center;
	new_cylin.radius = pars_cylin.radius;
	new_cylin.blesk = pars_cylin.blesk;
	new_cylin.color = pars_cylin.color;
	new_cylin.vector = pars_cylin.vector;
	return (new_cylin);
}
