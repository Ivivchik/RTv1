/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:41:38 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 09:02:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere    *create_null_list_spheres(int nbr)
{
  t_sphere    *n;
  int   i;

  n = (t_sphere*)malloc(nbr * sizeof(t_sphere));
  if (n == NULL || nbr == 0)
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].radius = 0.0;
    n[i].center = vec_new(0.0,0.0,0.0);
    n[i].blesk = 0.0;
    n[i].color = vec_new(0.0,0.0,0.0);
    //n[i].mater = mater_new();
  }
  return (n);
}

//t_sphere    sphere_new(t_vec3 center, double radius, t_mater mater)
t_sphere    sphere_new(t_vec3 center, double radius, double blesk, t_vec3 color)
{
  t_sphere    new_sphere;

  new_sphere.center = center;
  new_sphere.radius = radius;
  new_sphere.blesk = blesk;
  new_sphere.color = color;
  return (new_sphere);
}
