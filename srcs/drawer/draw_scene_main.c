/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:13:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/19 02:57:35 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_scene_main(SDL_Surface *surf, t_sdl **sdl)
{
	int		x;
	int		y;
	t_vec3	color;
	t_ray	ray;

	x = -1;
	while (++x < surf->w)
	{
		y = -1;
		while (++y < surf->h)
		{
			ray = get_camera_ray(*sdl, surf, x, y);
			color = cast_ray(ray, *sdl);
			put_pixel(surf, x, y,
					pack_color(color.x, color.y, color.z));
		}
	}
	return ;
}
