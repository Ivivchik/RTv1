/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:13:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/15 19:52:31 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    draw_scene1(SDL_Surface *surf, t_sdl  **sdl)
{
  int     x;
  int     y;
  t_vec3  color;
  t_vec3  a;
  int     rgb;

  x = -surf->w / 2 - 1;
  while (++x >= -surf->w / 2 && x < surf->w / 2)
  {
    y = -surf->h / 2 - 1;
    while (++y >= -surf->h / 2 && y < surf->h / 2)
    {
      a = tranform_to_viewport(x, y, surf->w, surf->h);
      color = cast_ray(a, *sdl);
      put_pixel(surf, x + surf->w / 2, y + surf->h / 2,
        pack_color(color.x,color.y,color.z));
    }
  }
  return ;
}
