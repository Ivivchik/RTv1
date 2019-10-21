/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_exec_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:42:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/20 11:46:27 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exec_1(t_all_obj *objs)
{
	(*objs).new_sphere = exec_sphere_1();
	(*objs).new_cone = exec_cone_1();
	(*objs).new_plane = exec_plane_1();
	(*objs).new_cylinder = exec_cylinder_1();
	return ;
}

void	exec_2(t_all_obj *objs)
{
	(*objs).new_sphere = exec_sphere_2();
	(*objs).new_cone = exec_cone_2();
	(*objs).new_plane = exec_plane_2();
	(*objs).new_cylinder = exec_cylinder_2();
	return ;
}

void	exec_3(t_all_obj *objs)
{
	(*objs).new_sphere = exec_sphere_3();
	(*objs).new_cone = exec_cone_3();
	(*objs).new_plane = exec_plane_3();
	(*objs).new_cylinder = exec_cylinder_3();
	return ;
}

void	exec_4(t_all_obj *objs)
{
	(*objs).new_sphere = exec_sphere_4();
	(*objs).new_cone = exec_cone_4();
	(*objs).new_plane = exec_plane_4();
	(*objs).new_cylinder = exec_cylinder_4();
	return ;
}

void	exec_5(t_all_obj *objs)
{
	(*objs).new_sphere = exec_sphere_5();
	(*objs).new_cone = exec_cone_5();
	(*objs).new_plane = exec_plane_5();
	(*objs).new_cylinder = exec_cylinder_5();
	return ;
}
