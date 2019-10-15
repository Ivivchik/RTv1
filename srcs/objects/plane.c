/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:12:45 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/15 21:31:31 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane    *create_null_list_plane(int nbr)
{
  t_plane    *n;
  int   i;

  n = (t_plane*)malloc(nbr * sizeof(t_plane));
  if (n == NULL || nbr == 0)
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].norm = vec_new(0.0,0.0,0.0);
    n[i].blesk = 0.0;
    n[i].color = vec_new(0.0,0.0,0.0);
	  n[i].line = vec_new(0.0,0.0,0.0);
    //n[i].mater = mater_new();
  }
  return (n);
}

//t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater)
t_plane    plane_new(t_vec3 norm, t_vec3 line, double blesk, t_vec3 color)
{
  t_plane    new_plane;

  new_plane.norm = norm;
  new_plane.blesk = blesk;
  new_plane.color = color;
  new_plane.line = line;
  return (new_plane);
}