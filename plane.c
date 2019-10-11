/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:05:17 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/12 01:47:12 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_coord		tranform_to_viewport(double x, double y)
{
	t_coord	view_port;

	view_port.x = (x * 5 / WIDTH);
	view_port.y = (y * -5 / HEIGHT);
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

t_coord		sum_vect(t_coord a, t_coord b)
{
	t_coord c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_coord		mult(t_coord a, double k)
{
	t_coord	c;

	c.x = a.x * k;
	c.y = a.y * k;
	c.z = a.z * k;
	return (c);
}

int			proverka(t_coord a, t_coord b, t_coord c)
{
	if ((a.x < b.x && a.x > c.x) &&
		(a.y < b.y && a.y > c.y) &&
		(a.z < b.z && a.z > c.z))
		return (1);
	return (0);
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
	l[0].pos = init_coord(0, 0, 1);
	l[1].inten = 0.3;
	l[1].pos = init_coord(2, 1, 0);
	l[2].inten = 0.3;
	l[2].pos = init_coord(4, 4, 4);
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
	t_coord	c;
	t_coord	v;
	t_coord x;
	double		k;

	c = s.point;
	v = s.normal;
	x = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	if (dot_prod(b, v) == 0)
		return (0);
	t = - dot_prod(x, v) / dot_prod(b, v);
	return (t);
}

t_coord		dot_color(t_coord a, t_coord b, t_rt *rt)
{
	rt->close_t = TMAX;
	t_coord color_plane = init_coord(0, 0, 0);
	t_plane p;
	t_coord c;
	p.point = init_coord(0, 0, 1);
	p.normal = init_coord(0, 1, 5);
	p.blesk = 1000;
	//p.normal = init_coord(p.normal.x - p.point.x, p.normal.y - p.point.y, p.normal.z - p.point.z);
	p.normal = init_coord(p.normal.x / len_v(p.normal), p.normal.y / len_v(p.normal), p.normal.z / len_v(p.normal));
	p.color = init_coord(255, 100, 0);
	double t;
	t = intersection_ray_plane(a, b, p);
	if (t >= TMIN && t <= TMAX && t < rt->close_t)
	{
		rt->close_t = t;
		c = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
		a.z + rt->close_t * b.z);
		color_plane = mult(p.color, computer_lighting(c, p.normal, mult(b , -1), p.blesk, rt));
	}
	return(color_plane);
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
			color = dot_color(camera, a, rt);
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