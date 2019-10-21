/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_init_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:50:20 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/20 12:31:15 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			error(t_all_obj *objs)
{
	ft_bzero(objs, sizeof(t_all_obj));
	ft_print_error_exit(&ft_putendl, "Error, exec_scene");
}

t_all_obj		exec_obj(int num_scene)
{
	t_all_obj	objs;

	if (num_scene == SCENE1_IMG)
		exec_1(&objs);
	else if (num_scene == SCENE2_IMG)
		exec_2(&objs);
	else if (num_scene == SCENE3_IMG)
		exec_3(&objs);
	else if (num_scene == SCENE4_IMG)
		exec_4(&objs);
	else if (num_scene == SCENE4_1_IMG)
		exec_4(&objs);
	else if (num_scene == SCENE4_2_IMG)
		exec_4(&objs);
	else if (num_scene == SCENE5_IMG)
		exec_5(&objs);
	else if (num_scene == SCENE5_1_IMG)
		exec_5(&objs);
	else if (num_scene == SCENE5_2_IMG)
		exec_5(&objs);
	else
		error(&objs);
	return (objs);
}

static int		parse_numb_obj_sc(int **nbr, int num_scene)
{
	int		i;

	i = 0;
	if (num_scene == SCENE1_IMG)
		load_1(&i, nbr);
	else if (num_scene == SCENE2_IMG)
		load_2(&i, nbr);
	else if (num_scene == SCENE3_IMG)
		load_3(&i, nbr);
	else if (num_scene == SCENE4_IMG)
		load_4(&i, nbr);
	else if (num_scene == SCENE4_1_IMG)
		load_4(&i, nbr);
	else if (num_scene == SCENE4_2_IMG)
		load_4(&i, nbr);
	else if (num_scene == SCENE5_IMG)
		load_5(&i, nbr);
	else if (num_scene == SCENE5_1_IMG)
		load_5(&i, nbr);
	else if (num_scene == SCENE5_2_IMG)
		load_5(&i, nbr);
	else
		ft_print_error_exit(&ft_putendl, "Error, no_scene_numbrs");
	return (i);
}

static void		fill_all(t_obj ***all_obj, t_all_obj objs, int *nmbr)
{
	int	i;

	i = 0;
	if (objs.new_sphere)
		fill_objs_sphere(all_obj, objs.new_sphere, &i, nmbr[0]);
	if (objs.new_cone)
		fill_objs_cone(all_obj, objs.new_cone, &i, nmbr[1]);
	if (objs.new_plane)
		fill_objs_plane(all_obj, objs.new_plane, &i, nmbr[2]);
	if (objs.new_cylinder)
		fill_objs_cylin(all_obj, objs.new_cylinder, &i, nmbr[3]);
	return ;
}

void			init_obj(t_obj ***all_obj, int *num, int scene_num)
{
	t_all_obj	objs;
	int			i;
	int			*nmbr;

	if (!(nmbr = (int*)malloc(sizeof(int) * 4)))
		ft_print_error_exit(&ft_putendl, "Error, no_alloc_nbr_obj");
	objs = exec_obj(scene_num);
	*num = parse_numb_obj_sc(&nmbr, scene_num);
	if (!((*all_obj) = (t_obj **)malloc(sizeof(t_obj*) * *num)))
		ft_print_error_exit(&ft_putendl, "Error, no_obj");
	i = -1;
	while (++i < *num)
	{
		if (!((*all_obj)[i] = (t_obj *)malloc(sizeof(t_obj))))
			ft_print_error_exit(&ft_putendl, "Error, no_obj_elem");
	}
	fill_all(all_obj, objs, nmbr);
	free(nmbr);
	return ;
}
