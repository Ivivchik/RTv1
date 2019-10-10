/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:05:17 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/10 19:27:22 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_coord		tranform_to_viewport(double x, double y)
{
	t_coord	view_port;

	view_port.x = (x * 10 / WIDTH);
	view_port.y = (y * -10 / HEIGHT);
	view_port.z = 1;
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

double		dot_prod(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		len_v(t_coord a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_coord		vector(t_coord a, t_coord b)
{
	t_coord v;

	v = init_coord(b.x - a.x, b.y - a.y, b.z - a.z);
	return (v);
}

t_coord		mult(t_coord a, double k)
{
	t_coord	c;

	c.x = a.x * k;
	c.y = a.y * k;
	c.z = a.z * k;
	return (c);
}

t_coord		cross(t_coord m0, t_coord m1, t_coord m2)
{
	t_coord n;
	t_coord m0_m1;
	t_coord m0_m2;

	m0_m1 = vector(m1, m0);
	m0_m2 = vector(m2, m0);

	n = init_coord(m0_m1.y * m0_m2.z - m0_m1.z * m0_m2.y,
	m0_m1.z * m0_m2.x - m0_m1.x * m0_m2.z,
	m0_m1.x * m0_m2.y - m0_m1.y * m0_m2.x);
	return (n);
}

double		computer_lighting(t_coord p, t_coord n, t_coord v, int s, t_rt *rt)
{
	t_light l[5];
	t_coord li;
	t_coord r;
	t_coord shadow_orig;
	t_coord shadow_pt;
	t_coord shadow_n;
	int		j;

	rt->intens = 0;
	l[0].inten = 0.2;
	l[0].pos = init_coord(0, 0, 0);
	l[1].inten = 0.3;
	l[1].pos = init_coord(2, 1, 0);
	l[2].inten = 0.3;
	l[2].pos = init_coord(1, 4, 4);
	j = 0;
	while (j < 3)
	{
		li = init_coord(l[j].pos.x - p.x, l[j].pos.y - p.y, l[j].pos.z - p.z);
		rt->n_dot_l = dot_prod(li, n);
		if (rt->n_dot_l > 0)
			rt->intens += l[j].inten * rt->n_dot_l / (len_v(n) * len_v(li));
		if (s != -1)
		{
			r = init_coord(2 * n.x * dot_prod(n, li) - li.x,
			2 * n.y * dot_prod(n, li) - li.y,
			2 * n.z * dot_prod(n, li) - li.z);
			rt->r_dot_v = dot_prod(r, v);
			if (rt->r_dot_v > 0)
				rt->intens += l[j].inten * pow(rt->r_dot_v /
				(len_v(r) * len_v(v)), s);
		}
		j++;
	}
	return (rt->intens);
}

double		intersection_ray_plane(t_coord a, t_coord b, t_plane s)
{
	double	t;
	t_coord	n;
	t_coord	v;

	n = cross(s.m0, s.m1, s.m2);
	//n = init_coord(n.x / len_v(n), n.y / len_v(n), n.z / len_v(n));
	v = init_coord(a.x - b.x, a.y - b.y, a.z - b.z);
	t = dot_prod(init_coord(s.m0.x - v.x, s.m0.y - v.y, s.m0.z - v.y), n)/
	(dot_prod(v, n));
	return (t);
}

t_coord		dot_color(t_coord a, t_coord b)
{
	double t;
	double close_t;
	t_coord close_pl;
	t_plane s;

	close_t = TMAX;
	s.m0 = init_coord(1, 0, 1);
	s.m1 = init_coord(0, 1, 0);
	s.m2 = init_coord(4, 5, 4);
	s.color = init_coord(255, 0, 0);
	t = intersection_ray_plane(a, b, s);
	if (t >= TMIN && t <= TMAX && t < close_t)
	{
		close_t = t;
		close_pl = s.color;
	}
	return (close_pl);
}

int			main(void)
{
	t_coord		color;
	t_coord		a;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_coord		camera;
	int			rgb;
	t_rt		*rt;

	rt = (t_rt *)malloc(sizeof(t_rt));
	camera = init_coord(0, 0, 0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "RTv1");
	x = -WIDTH / 2 + 1;
	while (x > -WIDTH / 2 && x < WIDTH / 2)
	{
		y = -HEIGHT / 2 + 1;
		while (y > -HEIGHT / 2 && y < HEIGHT / 2)
		{
			a = tranform_to_viewport(x, y);
			color = dot_color(camera, a);
			rgb = (((int)color.x << 16) | ((int)color.y << 8) | ((int)color.z));
			mlx_pixel_put(mlx, win, x + WIDTH / 2, y + HEIGHT / 2, rgb);
			y++;
		}
		x++;
	}
	mlx_hook(win, 2, 3, key, rt);
	mlx_loop(mlx);
	return (0);
}