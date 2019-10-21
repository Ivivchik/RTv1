/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:41:38 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 07:28:17 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*create_null_list_spheres(int nbr)
{
	t_sphere	*n;
	int			i;

	if (nbr == 0)
		return (NULL);
	if (!(n = (t_sphere*)malloc(nbr * sizeof(t_sphere))))
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		n[i].radius = 0.0;
		n[i].center = vec_new(0.0, 0.0, 0.0);
		n[i].blesk = 0.0;
		n[i].color = vec_new(0.0, 0.0, 0.0);
	}
	return (n);
}

t_sphere	sphere_new(t_vec3 center, double radius, double blesk, t_vec3 color)
{
	t_sphere	new_sphere;

	new_sphere.center = center;
	new_sphere.radius = radius;
	new_sphere.blesk = blesk;
	new_sphere.color = color;
	return (new_sphere);
}
