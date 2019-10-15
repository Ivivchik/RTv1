/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:51:17 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 04:53:47 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	vec_rot_x(t_vec3 v, double a)
{
	t_vec3	r;

	r.x = v.x;
	r.y = v.y * cos(a) - v.z * sin(a);
	r.z = v.y * sin(a) + v.z * cos(a);
	return (r);
}

t_vec3	vec_rot_y(t_vec3 v, double a)
{
	t_vec3	r;

  r.x = v.x * cos(a) + v.z * sin(a);
	r.y = v.y;
	r.z = v.z * cos(a) - v.x * sin(a);
	return (r);
}

t_vec3	vec_rot_z(t_vec3 v, double a)
{
	t_vec3	r;

  r.x = v.x * cos(a) - v.y * sin(a);
	r.y = v.x * sin(a) + v.y * cos(a);
	r.z = v.z;
	return (r);
}
