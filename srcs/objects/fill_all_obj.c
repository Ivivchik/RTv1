/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_all_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:51:19 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/13 21:05:07 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    fill_objs_sphere(t_obj ***all_obj, t_sphere *sphere, int *i, int max)
{
  int  k;

  k = -1;
  while (++k < max)
  {
    (*all_obj)[*i]->type = &sphere[k];
    (*all_obj)[*i]->c_type = STR_SPHERE;
    *i += 1;
  }
  return ;
}

void    fill_objs_cone(t_obj ***all_obj, t_cone *cone, int *i, int max)
{
  int  k;

  k = -1;
  while (++k < max)
  {
    (*all_obj)[*i]->type = &cone[k];
    (*all_obj)[*i]->c_type = STR_CONE;
    *i += 1;
  }
  return ;
}

void    fill_objs_plane(t_obj ***all_obj, t_plane *plane, int *i, int max)
{
  int  k;

  k = -1;
  while (++k < max)
  {
    (*all_obj)[*i]->type = &plane[k];
    (*all_obj)[*i]->c_type = STR_PLANE;
    *i += 1;
  }
  return ;
}

void    fill_objs_cylin(t_obj ***all_obj, t_cylin *cylindr, int *i, int max)
{
  int  k;

  k = -1;
  while (++k < max)
  {
    (*all_obj)[*i]->type = &cylindr[k];
    (*all_obj)[*i]->c_type = STR_CYLINDR;
    *i += 1;
  }
  return ;
}
