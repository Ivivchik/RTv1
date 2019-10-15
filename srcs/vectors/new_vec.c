/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:55:46 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 05:25:10 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3    vec_new(double x, double y, double z)
{
	t_vec3 new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3    vec_cpy(t_vec3 v)
{
	return (vec_new(v.x, v.y, v.z));
}

t_vec3		vec_scale(t_vec3 v, double nb)
{
	v.x *= nb;
	v.y *= nb;
	v.z *= nb;
	return (v);
}

double		vec_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3		vec_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	r;

	r.x = v1.y * v2.z - v1.z * v2.y;
	r.y = v1.z * v2.x - v1.x * v2.z;
	r.z = v1.x * v2.y - v1.y * v2.x;
	return (r);
}
