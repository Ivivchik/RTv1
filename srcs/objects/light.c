/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:34:23 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 07:25:00 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*create_null_list_lights(int nbr)
{
	t_light		*n;
	int			i;

	if (nbr == 0)
		return (NULL);
	if (!(n = (t_light*)malloc(nbr * sizeof(t_light))))
		return (NULL);
	i = -1;
	while (++i < nbr)
	{
		n[i].intens = 0.0;
		n[i].pos = vec_new(0.0, 0.0, 0.0);
	}
	return (n);
}

t_light		light_new(t_vec3 pos, double intens)
{
	t_light		new_light;

	new_light.intens = intens;
	new_light.pos = pos;
	return (new_light);
}
