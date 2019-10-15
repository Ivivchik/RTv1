/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:15:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/13 21:04:09 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere      get_sph(void *sdl_s)
{
  t_sphere    sphere;

  ft_memcpy(&sphere, sdl_s, sizeof(t_sphere));
  return (sphere);
}

t_plane				get_pla(void *sdl_p)
{
  t_plane    plane;

  ft_memcpy(&plane, sdl_p, sizeof(t_plane));
  return (plane);
}

t_cone				get_con(void *sdl_o)
{
  t_cone    cone;

  ft_memcpy(&cone, sdl_o, sizeof(t_cone));
  return (cone);
}

t_cylin				get_cyl(void *sdl_c)
{
  t_cylin    cylinder;

  ft_memcpy(&cylinder, sdl_c, sizeof(t_cylin));
  return (cylinder);
}
