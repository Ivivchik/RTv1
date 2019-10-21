/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:01:06 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 06:24:10 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		vec_op_add(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3		vec_op_sub(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3		vec_op_mult(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3		vec_op_div(t_vec3 v1, t_vec3 v2)
{
	if (v2.x && v2.y && v2.z)
	{
		v1.x /= v2.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
	}
	return (v1);
}
