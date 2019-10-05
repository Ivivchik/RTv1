/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:02:57 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/05 15:41:39 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_coord		tranform_to_viewport(double x, double y, t_rt *rt)
{
	t_coord	view_port;

	view_port.x = WIDTH / 2 + x * rt->vw / WIDTH;
	view_port.y = HEIGHT / 2 + y * rt->vh / HEIGHT;
	view_port.z = rt->vz;
	return (view_port);
}

t_coord		init_coord(double x, double y, double z)
{
	t_coord	coor;

	coor.x = x;
	coor.y = y;
	coor.z = z;
	return (coor);
}

void		init_for_rt(t_rt *rt)
{
	rt->camera = init_coord(0, 0, 0);
	rt->vw = 1;
	rt->vz = 1;
	rt->vh = 1;
	rt->vector = init_coord();
}

void		dot_product(t_rt *rt)
{

}

void		raytracing(t_rt *rt)
{
	int		x;
	int		y;
	t_coord	coord;

	init_for_rt(rt);
	x = -WIDTH / 2 + 1;
	while (x > -WIDTH / 2 && x < WIDTH / 2)
	{
		y = -HEIGHT / 2 + 1;
		while (y > -HEIGHT / 2 && y < HEIGHT / 2)
		{
			coord = tranform_to_viewport(x, y, rt);
			y++;
		}
		x++;
	}
}
