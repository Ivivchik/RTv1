/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:28:42 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/13 19:47:56 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone    *create_null_list_cone(int nbr)
{
  t_cone    *n;
  int   i;

  n = (t_cone*)malloc(nbr * sizeof(t_cone));
  if (n == NULL || nbr == 0)
    return (NULL);
  i = -1;
  while(++i < nbr)
  {
    n[i].center = vec_new(0.0,0.0,0.0);
    n[i].blesk = 0.0;
    n[i].color = vec_new(0.0,0.0,0.0);
	  n[i].ang = 0.0;
	  n[i].vector = vec_new(0.0, 0.0, 0.0);
    //n[i].mater = mater_new();
  }
  return (n);
}

t_cone    cone_new(t_vec3 center, t_vec3 vector, double blesk, t_vec3 color, double ang)
{
  t_cone    new_cone;

  new_cone.center = center;
  new_cone.blesk = blesk;
  new_cone.color = color;
  new_cone.ang = ang;
  new_cone.vector = vector;
  return (new_cone);
}