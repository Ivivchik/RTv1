/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vec3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:45:04 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/28 08:05:02 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_VEC3_H
# define RTV1_VEC3_H

typedef struct		s_vec3
{
  double      x;
  double      y;
  double      z;
}                 t_vec3;

/*
**	*_*
*/
double      vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3      vec_cross(t_vec3 v1, t_vec3 v2);

/*
**	normal vec
*/
t_vec3      unit_vector(t_vec3 v);

/*
**	length_vect
*/
double      vec_squared_len(t_vec3 v);
double      vec_length(t_vec3 v);

/*
**	Create vectors
*/
t_vec3      vec_new(double x, double y, double z);
t_vec3      vec_cpy(t_vec3 v);
t_vec3      vec_scale(t_vec3 v, double nb);

/*
**	Some operator on vectors
*/
t_vec3      vec_op_add(t_vec3 v1, t_vec3 v2);
t_vec3      vec_op_sub(t_vec3 v1, t_vec3 v2);
t_vec3      vec_op_div(t_vec3 v1, t_vec3 v2);
t_vec3      vec_op_mult(t_vec3 v1, t_vec3 v2);

/*
**	rotate vectors
*/
t_vec3      vec_rot_x(t_vec3 v, double a);
t_vec3      vec_rot_y(t_vec3 v, double a);
t_vec3      vec_rot_z(t_vec3 v, double a);

#endif
