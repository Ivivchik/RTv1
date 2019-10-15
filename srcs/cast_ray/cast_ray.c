/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:20:44 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/15 23:32:44 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double    com(t_vec3 point, t_vec3 nbig, t_sdl *sdl)
{
    t_light light[3];
    t_vec3 light_dir;
  light[0].intens = 0.5;
	light[0].pos = vec_new(0, 0, 0);
	light[1].intens = 0.4;
	light[1].pos = vec_new(2, 2, 1);
	light[2].intens = 0.1;
	light[2].pos = vec_new(1, 4, 4);
  double diff_light_intens = 0;
    int		i = -1;
	  while (++i < 2)
	  {
		  light_dir = unit_vector(vec_op_sub(light[i].pos, point));
		//add shadows
		double light_distance = vec_length(vec_op_sub(light[i].pos, point));
		// t_vec3 shadow_orig = ((vec_dot(light_dir,nbig) < 0) ? vec_op_sub(point,vec_scale(nbig,0.001)) : vec_op_add(point,vec_scale(nbig,0.001)));
		// t_vec3 shadow_pt,shadow_n;
		// t_mater	tmpmater;
		// t_ray shadow_ray = new_ray(shadow_orig, light_dir);
		// if (scene_intersect(plane, sphers,shadow_ray,&shadow_pt,&shadow_n,&tmpmater) && (vec_length(vec_op_sub(shadow_pt,shadow_orig)) < 1000))
		// 	continue;
		diff_light_intens += light[i].intens * fmax(0.f, vec_dot(light_dir, nbig));
		// left_part_powf = fmax(0.f, vec_dot(vec_scale(reflect(vec_scale(light_dir,-1.0), nbig),-1.f),ray.direct));
		// spec_light_intens += powf(left_part_powf, mater.spec_exp)*light[i].intens;
	}
	// left_return = vec_scale(vec_scale(mater.diff_col,diff_light_intens),mater.albedo.x);
	// right_return = vec_scale(vec_scale(vec_new(1.0, 1.0, 1.0),spec_light_intens),mater.albedo.y);
	// t_vec3 col = vec_op_add(vec_op_add(left_return,right_return),vec_scale(reflect_color,mater.albedo.z));

  return (diff_light_intens);
}

double		computer_lighting(t_vec3 p, t_vec3 n, t_sdl *rt)//, t_vec3 v, int s)
{
	t_light l[5];
	t_vec3 li;
	t_vec3 r;
	t_vec3 shadow_orig;
	t_vec3 shadow_pt;
	t_vec3 shadow_n;
	int		j;

	rt->intens = 0;
	l[0].intens = 0.5;
	l[0].pos = vec_new(0, 0, 0);
	l[1].intens = 0.2;
	l[1].pos = vec_new(2, 1, 0);
	l[2].intens = 0.3;
	l[2].pos = vec_new(1, 4, 4);
	j = 0;
	while (j < 3)
	{
		li = vec_new(l[j].pos.x - p.x, l[j].pos.y - p.y, l[j].pos.z - p.z);
    li = vec_new(li.x / vec_length(li), li.y / vec_length(li), li.z / vec_length(li));
		rt->n_dot_l = vec_dot(li, n);
		if (rt->n_dot_l > 0)
			rt->intens += l[j].intens * rt->n_dot_l / vec_length(li);
		// if (s != -1)
		// {
		// 	r = vec_new(2 * n.x * vec_dot(n, li) - li.x,
		// 	2 * n.y * vec_dot(n, li) - li.y,
		// 	2 * n.z * vec_dot(n, li) - li.z);
		// 	rt->r_dot_v = vec_dot(r, v);
		// 	if (rt->r_dot_v > 0)
		// 		rt->intens += l[j].intens * pow(rt->r_dot_v /
		// 		(vec_length(r) * vec_length(v)), s);
		// }
		j++;
	}
	return (rt->intens);
}

t_vec3      calc_color(double close_t, t_vec3 b, t_sdl *sdl, int i)
{
  t_vec3  col_out;
  t_vec3  p;
  t_vec3  n;
  t_vec3  a;
  double m;

 a = sdl->camera;
  p = vec_new(a.x + close_t * b.x, a.y + close_t * b.y, a.z + close_t * b.z);
  if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
  {
    n = vec_new(p.x - sdl->f_center.x, p.y - sdl->f_center.y, p.z - sdl->f_center.z);
  }
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
  {
    sdl->f_center = vec_scale(sdl->f_center, -1);
    m = vec_dot(b, sdl->f_center) * close_t + vec_dot(sdl->x, sdl->f_center);
    n = vec_new(p.x - sdl->f_center.x - (1 + sdl->k * sdl->k) * sdl->norm_cone.x * m,
    p.y - sdl->f_center.y - (1 + sdl->k * sdl->k) * sdl->norm_cone.y * m,
    p.z - sdl->f_center.z - (1 + sdl->k * sdl->k) * sdl->norm_cone.z * m);
    //n = vec_scale(n, -1);
  }
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
    n = vec_scale(vec_new(p.x - sdl->f_center.x, p.y - sdl->f_center.y, p.z - sdl->f_center.z), -1);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
  {
    m = vec_dot(b, sdl->f_center) * close_t + vec_dot(sdl->x, sdl->f_center);
      n = vec_new(p.x - sdl->f_center.x - sdl->norm_cylin.x * m,
      p.y - sdl->f_center.y - sdl->norm_cylin.y * m,
      p.z - sdl->f_center.z - sdl->norm_cylin.z * m);
      n = vec_scale(n, -1);
   }
  //n = vec_new(p.x - sdl->f_center.x, p.y - sdl->f_center.y, p.z - sdl->f_center.z);
 // n = vec_scale(vec_new(p.x - sdl->f_center.x, p.y - sdl->f_center.y, p.z - sdl->f_center.z), -1);
  n = vec_new(n.x / vec_length(n), n.y / vec_length(n), n.z / vec_length(n));
  col_out = sdl->f_color;
  //col_out = vec_scale(sdl->f_color, computer_lighting(p, n, sdl));//, vec_scale(b, -1), sdl->f_blesk));
  return (col_out);
}

double    *cast_ray_for_obj(t_sdl *sdl, t_vec3 b, int i)
{
  double      *t;
  double        tp;

  if (ft_strcmp(sdl->obj[i]->c_type, STR_SPHERE) == 0)
    t = intersec_sphere(sdl->camera, b, get_sph(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CONE) == 0)
    t = intersec_conus(sdl->camera, b, get_con(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
      tp = intersec_plane(sdl->camera, b, get_pla(sdl->obj[i]->type), sdl);
  else if (ft_strcmp(sdl->obj[i]->c_type, STR_CYLINDR) == 0)
      t = intersec_cylinder(sdl->camera, b, get_cyl(sdl->obj[i]->type), sdl);
  return (t);
}

t_vec3    cast_ray(t_vec3 b, t_sdl *sdl)
{
  t_vec3  color = vec_new(255, 255, 245);
  int     i;
  double  close_t;
  double  *t;
  double tp;

  i = -1;
  close_t = MAX_DIST;
  while (++i < sdl->num_obj)
  {
    if (ft_strcmp(sdl->obj[i]->c_type, STR_PLANE) == 0)
    {
      tp = intersec_plane(sdl->camera, b, get_pla(sdl->obj[i]->type), sdl);
      if (tp >= MIN_DIST && tp <= MAX_DIST && tp < close_t)
      {
       close_t = tp;
       color = calc_color(close_t, b, sdl, i);
      }
    }
    else
    {  
      t = cast_ray_for_obj(sdl, b, i);
      if (t[0] >= MIN_DIST && t[0] <= MAX_DIST && t[0] < close_t)
      {
       close_t = t[0];
       color = calc_color(close_t, b, sdl, i);
      }
      if (t[1] >= MIN_DIST && t[1] <= MAX_DIST && t[1] < close_t)
      {
       close_t = t[1];
       color = calc_color(close_t, b, sdl, i);
      }
		  free(t);
    }
  }
	return (color);
}
