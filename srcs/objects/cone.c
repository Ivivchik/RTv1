/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:28:42 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/27 19:01:04 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone		*create_null_list_cone(int nbr)
{
	t_cone	*n;
	int		i;

	if (nbr == 0)
		return (NULL);
	if (!(n = (t_cone*)malloc(nbr * sizeof(t_cone))))
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		n[i].center = vec_new(0.0, 0.0, 0.0);
		n[i].blesk = 0.0;
		n[i].color = vec_new(0.0, 0.0, 0.0);
		n[i].ang = 0.0;
		n[i].vector = vec_new(0.0, 0.0, 0.0);
	}
	return (n);
}

t_cone		cone_new(t_cone pars_cone)
{
	t_cone		new_cone;
	
	new_cone.center = pars_cone.center;
	new_cone.blesk = pars_cone.blesk;
	new_cone.color = pars_cone.color;
	new_cone.ang = pars_cone.ang;
	new_cone.vector = pars_cone.vector;
	return (new_cone);
}
