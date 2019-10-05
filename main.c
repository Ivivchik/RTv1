/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:02:57 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/05 17:52:29 by hkuhic           ###   ########.fr       */
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
	rt->vz = 1;
	rt->vh = 1;
}

double		dot_product(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		*intersection_ray_sphere(t_coord a, t_coord b, t_sphere s, t_rt *rt)
{
	double	t[2];
	t_coord	c;
	t_coord v;
	int		r;
	double	dis;

	c = s.center;
	r = s.radius;
	v = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	rt->k1 = dot_product(b, b);
	rt->k2 = 2 * dot_product(v, b);
	rt->k3 = dot_product(v, v) - r * r;
	dis = rt->k2 * rt->k2 - 4 * rt->k1 * rt->k3;
	if ()
	return (t);
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
