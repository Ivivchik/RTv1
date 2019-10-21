/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:12:45 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/19 07:27:00 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane		*create_null_list_plane(int nbr)
{
	t_plane		*n;
	int			i;

	if (nbr == 0)
		return (NULL);
	if (!(n = (t_plane*)malloc(nbr * sizeof(t_plane))))
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		n[i].norm = vec_new(0.0, 0.0, 0.0);
		n[i].blesk = 0.0;
		n[i].color = vec_new(0.0, 0.0, 0.0);
		n[i].line = vec_new(0.0, 0.0, 0.0);
	}
	return (n);
}

t_plane		plane_new(t_vec3 norm, t_vec3 line, double blesk, t_vec3 color)
{
	t_plane		new_plane;

	new_plane.norm = norm;
	new_plane.blesk = blesk;
	new_plane.color = color;
	new_plane.line = line;
	return (new_plane);
}
