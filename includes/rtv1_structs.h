/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/13 22:38:31 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_vec3.h"

typedef struct		s_ray
{
  t_vec3      origin;
  t_vec3      direct;
}                 t_ray;

/*
**	Materials
*/
typedef struct		s_mater
{
  char      *type_mat;
  t_vec3    albedo;
  t_vec3    diff_col;
  double    spec_exp;
}                 t_mater;

/*
**	Camera
*/
typedef struct		s_cam
{
  t_vec3    lower_l;
  t_vec3    horiz;
  t_vec3    vert;
  t_vec3    origin;
}                 t_cam;

/*
**	Objects
*/
typedef struct		s_obj
{
  void              *type;
  char              *c_type;
}                 t_obj;

typedef struct		s_sphere
{
  double            radius;
  t_vec3            center;
  t_vec3            color;
  double            blesk;
  //t_mater           mater;
}                 t_sphere;

typedef struct		s_plane
{
  t_vec3            norm;
  t_vec3            line;
  t_mater           mater;
  t_vec3            color;
  double            blesk;
}                 t_plane;

typedef struct		s_cone
{
  t_vec3            center;
  t_vec3            vector;
  t_vec3            color;
  double            ang;
  t_mater           mater;
  double            blesk;
}                 t_cone;

typedef struct    s_cylin
{
  t_vec3          center;
  t_vec3          vector;
  t_mater         mater;
  t_vec3            color;
  double            blesk;
  double          radius;
}                 t_cylin;

/*
**	Light
*/
typedef struct		s_light
{
  double    intens;
  t_vec3    pos;
}                 t_light;

typedef struct		s_all_obj
{
  t_sphere    *new_sphere;
  t_cone      *new_cone;
  t_plane     *new_plane;
  t_cylin     *new_cylinder;
}                 t_all_obj;

/*
**	Main struct
*/
typedef struct		s_sdl
{
  SDL_Window      *win;
  SDL_Surface     *screen;
  SDL_Surface     *image;
  SDL_Event       event;
  uint8_t         run_main;
  uint8_t         scene_num;
  int             num_obj;
  t_mater         *mater;
  t_obj           **obj;
  t_vec3          camera;
  double          k1;
  double          k2;
  double          k3;
  double          dis;
  double          n_dot_l;
  double          r_dot_v;
  double          intens;
  t_vec3          f_center;
  double          f_blesk;
  t_vec3          f_color;
  t_vec3          norm_cylin;
  t_vec3          norm_cone;
  double          k;
  t_vec3          x;
}                 t_sdl;

#endif
