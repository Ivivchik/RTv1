/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 06:29:53 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/16 16:41:44 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere      *exec_sphere_3(void)
{
  t_sphere  *spheres;
  int       nbrs_sph;
  t_mater   ivory;

  nbrs_sph = NUMB_SPHERE_IN_SCENE3;
  spheres = create_null_list_spheres(nbrs_sph);
  if (!(spheres))
    ft_print_error_exit(&ft_putendl, "Error, no_spheres");
  mater_fill(&ivory, MAT_IVORY);
  // spheres[0] = sphere_new(vec_new(0, -1, 3), 1, ivory);
  // spheres[1] = sphere_new(vec_new(2, 0, 4), 1, ivory);
  // spheres[2] = sphere_new(vec_new(-2, 0, 4), 1, ivory);
  // spheres[3] = sphere_new(vec_new(255, 255, 0), 5000, ivory);
  free (ivory.type_mat);

  spheres[0] = sphere_new(vec_new(-2, -1, 2), 1, 250, vec_new(255,255,0));
  //spheres[1] = sphere_new(vec_new(2, 0, 4), 1, 500, vec_new(0,0,255));
  spheres[1] = sphere_new(vec_new(-2, 0, 4), 1, 10, vec_new(0,255,0));
  //spheres[2] = sphere_new(vec_new(0, -5001, 0), 5000, 10, vec_new(100,100,100));
  return (spheres);
}

t_cone      *exec_cone_3(void)
{
  t_cone  *cone;
  int       nbrs_cone;
  t_mater   ivory;
  t_vec3    v;

  nbrs_cone = NUMB_CONE_IN_SCENE3;
  cone = create_null_list_cone(nbrs_cone);
  if (!(cone))
    ft_print_error_exit(&ft_putendl, "Error, no_cone");
  mater_fill(&ivory, MAT_IVORY);
  // spheres[0] = sphere_new(vec_new(0, -1, 3), 1, ivory);
  // spheres[1] = sphere_new(vec_new(2, 0, 4), 1, ivory);
  // spheres[2] = sphere_new(vec_new(-2, 0, 4), 1, ivory);
  // spheres[3] = sphere_new(vec_new(255, 255, 0), 5000, ivory);
  free (ivory.type_mat);
  v = vec_new(0, 2, 2);
  v = vec_new(v.x - 0, v.y - 0, v.z - 2);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cone[0] = cone_new(vec_new(0, 0, 2), v, 250, vec_new(255,0,255), 0.6);
  //cone[1] = cone_new(vec_new(2, 0, 4), vec_new(2, 0, 5), 500, vec_new(0,0,255), 0.2);
  // cone[2] = cone_new(vec_new(-2, 0, 4), 1, 10, vec_new(0,255,0));
  // cone[3] = cone_new(vec_new(0, -5001, 0), 5000, 1000, vec_new(255,255,0));
  return (cone);
}

t_plane      *exec_plane_3(void)
{
  t_plane  *plane;
  int       nbrs_plane;
  t_mater   ivory;
  t_vec3    v;

  nbrs_plane = NUMB_PLANE_IN_SCENE3;
  plane = create_null_list_plane(nbrs_plane);
  if (!(plane))
    ft_print_error_exit(&ft_putendl, "Error, no_plane");
  mater_fill(&ivory, MAT_IVORY);
  // spheres[0] = sphere_new(vec_new(0, -1, 3), 1, ivory);
  // spheres[1] = sphere_new(vec_new(2, 0, 4), 1, ivory);
  // spheres[2] = sphere_new(vec_new(-2, 0, 4), 1, ivory);
  // spheres[3] = sphere_new(vec_new(255, 255, 0), 5000, ivory);
  free (ivory.type_mat);
  plane[0] = plane_new(vec_new(0, 1, 0), vec_new(0, -1, 3), 250, vec_new(0,255,255));
  plane[1] = plane_new(vec_new(-1, 0, 0), vec_new(1, 0, 3), 250, vec_new(0,255,255));
  plane[2] = plane_new(vec_new(0, 0, -1), vec_new(0, 0, 6), 250, vec_new(0,255,255));
  //cone[1] = cone_new(vec_new2, 0, 4), vec_new(2, 0, 5), 500, vec_new(0,0,255), 0.2);
  // cone[2] = cone_new(vec_new(-2, 0, 4), 1, 10, vec_new(0,255,0));
  // cone[3] = cone_new(vec_new(0, -5001, 0), 5000, 1000, vec_new(255,255,0));
  return (plane);
}

t_cylin      *exec_cylinder_3(void)
{
  t_cylin  *cylin;
  int       nbrs_cylin;
  t_mater   ivory;
  t_vec3    v;

  nbrs_cylin = NUMB_CYLINDR_IN_SCENE3;
  cylin = create_null_list_cylinder(nbrs_cylin);
  if (!(cylin))
    ft_print_error_exit(&ft_putendl, "Error, no_cylinder");
  mater_fill(&ivory, MAT_IVORY);
  // spheres[0] = sphere_new(vec_new(0, -1, 3), 1, ivory);
  // spheres[1] = sphere_new(vec_new(2, 0, 4), 1, ivory);
  // spheres[2] = sphere_new(vec_new(-2, 0, 4), 1, ivory);
  // spheres[3] = sphere_new(vec_new(255, 255, 0), 5000, ivory);
  free (ivory.type_mat);
  //v = vec_new(-10, -5, 1);
   v = vec_new(-2, -2, 2);
  v = vec_new(v.x - 0, v.y - 0, v.z - 2);
  v = vec_new(v.x / vec_length(v), v.y / vec_length(v), v.z / vec_length(v));
  cylin[0] = cylin_new(vec_new(0, 0, 2), v, 0.5, 250, vec_new(255,100,0));
  //cone[1] = cone_new(vec_new(2, 0, 4), vec_new(2, 0, 5), 500, vec_new(0,0,255), 0.2);
  // cone[2] = cone_new(vec_new(-2, 0, 4), 1, 10, vec_new(0,255,0));
  // cone[3] = cone_new(vec_new(0, -5001, 0), 5000, 1000, vec_new(255,255,0));
  return (cylin);
}

t_all_obj     exec_obj_3(void)
{
  t_all_obj  objs;

  objs.new_sphere = exec_sphere_3();
  objs.new_cone = exec_cone_3();
  objs.new_plane = exec_plane_3();
  objs.new_cylinder = exec_cylinder_3();
  return (objs);
}

/*
**	Creating scene1 with numbers obj
*/
void    init_obj_3(t_obj    ***all_obj, int *num)
{
  t_all_obj   objs;
  int         i;

  objs = exec_obj_3();
  *num = NUMB_OBJ_IN_SCENE3;
  if (!((*all_obj) = (t_obj **)malloc(sizeof(t_obj*) * *num)))
    ft_print_error_exit(&ft_putendl, "Error, no_obj");
  i = -1;
  while (++i < NUMB_OBJ_IN_SCENE3)
  {
    if (!((*all_obj)[i] = (t_obj *)malloc(sizeof(t_obj))))
      ft_print_error_exit(&ft_putendl, "Error, no_obj_elem");
  }
  i = 0;
 fill_objs_sphere(all_obj, objs.new_sphere, &i, NUMB_SPHERE_IN_SCENE3);
  fill_objs_cone(all_obj, objs.new_cone, &i, NUMB_CONE_IN_SCENE3);
  fill_objs_plane(all_obj, objs.new_plane, &i, NUMB_PLANE_IN_SCENE3);
  fill_objs_cylin(all_obj, objs.new_cylinder, &i, NUMB_CYLINDR_IN_SCENE3);

  return ;
}

void    scene3(t_sdl **sdl)
{
  SDL_Surface   *frame;

  frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
  init_obj_3(&((*sdl)->obj), &((*sdl)->num_obj));
  //sdl->light = init_light_1;
  (*sdl)->camera = vec_new(0,0,0);
  draw_scene1(frame, sdl);
  (*sdl)->image = frame;
  ft_putstr("Loading: scene3\n");
  return;
}

// void    scene3(t_sdl **sdl)
// {
//   SDL_Surface		*frame;
//   frame = create_surface(WIN_WIDTH,WIN_HEIGHT);
//   back_scene3(frame);
  
//   ft_flip(frame); //  rotatte  verticaly
//   (*sdl)->image = frame;
//   ft_putstr("Loading: scene3\n");
//   return;
// }
