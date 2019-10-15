/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 05:28:28 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/05 01:53:43 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double    vec_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double    vec_squared_len(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3    make_unit_vector(t_vec3 v)
{
	double k = 1.0 / vec_length(v);
	return (vec_scale(v,k));
}

t_vec3    unit_vector(t_vec3 v)
{
	return (vec_scale(v,1.f/vec_length(v)));
}
