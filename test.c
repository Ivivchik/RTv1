/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:42:27 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/12 02:09:01 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_coord		tranform_to_viewport(double x, double y)
{
	t_coord	view_port;

	view_port.x = (x * 1.5 / WIDTH);
	view_port.y = (y * -1.5 / HEIGHT);
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

double		sum_coord(t_coord a)
{
	return (a.x + a.y + a.z);
}

t_coord		mult(t_coord a, double k)
{
	t_coord	c;

	c.x = a.x * k;
	c.y = a.y * k;
	c.z = a.z * k;
	return (c);
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

double		*intersection_ray_sphere(t_coord a, t_coord b, t_sphere s, t_rt *rt)
{
	double	*t;
	t_coord	c;
	t_coord	v;
	int		r;

	if (!(t = (double *)malloc(sizeof(double *) * 3)))
		return (0);
	c = s.center;
	r = s.radius;
	v = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	rt->k1 = dot_prod(b, b);
	rt->k2 = 2 * dot_prod(v, b);
	rt->k3 = dot_prod(v, v) - r * r;
	rt->dis = rt->k2 * rt->k2 - 4 * rt->k1 * rt->k3;
	if (rt->dis < 0)
	{
		t[0] = TMAX;
		t[1] = TMAX;
		t[2] = '\0';
		return (t);
	}
	t[0] = (-rt->k2 + sqrt(rt->dis)) / (2 * rt->k1);
	t[1] = (-rt->k2 - sqrt(rt->dis)) / (2 * rt->k1);
	t[2] = '\0';
	return (t);
}

int		dot_color(t_coord a, t_coord b, t_rt *rt)
{
	double		close_t;
	t_coord		p;
	t_coord		n;
	t_sphere	s[3];
	t_plane		pl;
	double		*t;
	int			i;
	int rgb;

	i = 0;
	close_t = TMAX;
	s[0].center = init_coord(0, -1, 3);
	s[0].radius = 1;
	s[0].color = init_coord(255, 0, 0);
	s[0].blesk = 250;
	s[1].center = init_coord(2, 0, 4);
	s[1].radius = 1;
	s[1].color = init_coord(0, 0, 255);
	s[1].blesk = 500;
	s[2].center = init_coord(-2, 0, 4);
	s[2].radius = 1;
	s[2].color = init_coord(0, 255, 0);
	s[2].blesk = 10;
	t_coord color_plane = init_coord(0, 0, 0);
	t_coord c;
	pl.point = init_coord(0, 0, 1);
	pl.normal = init_coord(0, 1, 5);
	pl.blesk = 1000;
	//p.normal = init_coord(p.normal.x - p.point.x, p.normal.y - p.point.y, p.normal.z - p.point.z);
	pl.normal = init_coord(pl.normal.x / len_v(pl.normal), pl.normal.y / len_v(pl.normal), pl.normal.z / len_v(pl.normal));
	pl.color = init_coord(255, 100, 0);
	double ip;
	ip = intersection_ray_plane(a, b, pl);
	while (i < 3)
	{	
		t = intersection_ray_sphere(a, b, s[i], rt);
		if (t[0] >= TMIN && t[0] <= TMAX && t[0] < close_t)
		{
			close_t = t[0];
			p = init_coord(a.x + close_t * b.x, a.y + close_t * b.y,
			a.z + close_t * b.z);
			n = init_coord(p.x - s[i].center.x, p.y - s[i].center.y,
			p.z - s[i].center.z);
			n = init_coord(n.x / len_v(n), n.y / len_v(n),
			n.z / len_v(n));
			color_plane = mult(s[i].color,
			computer_lighting(p, n, mult(b, -1), s[i].blesk, rt));
		}
		if (t[1] >= TMIN && t[1] <= TMAX && t[1] < close_t)
		{
			close_t = t[1];
			p = init_coord(a.x + close_t * b.x, a.y + close_t * b.y,
			a.z + close_t * b.z);
			n = init_coord(p.x - s[i].center.x, p.y - s[i].center.y,
			p.z - s[i].center.z);
			n = init_coord(n.x / len_v(n), n.y / len_v(n), n.z / len_v(n));
			color_plane = mult(s[i].color,
			computer_lighting(p, n, mult(b, -1), s[i].blesk, rt));
		}
		i++;
	}
	if (ip >= TMIN && ip <= TMAX && ip < rt->close_t)
	{
		rt->close_t = ip;
		c = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
		a.z + rt->close_t * b.z);
		color_plane = mult(pl.color, computer_lighting(c, pl.normal, mult(b , -1), pl.blesk, rt));
	}
	rgb = (((int)color_plane.x << 16) | ((int)color_plane.y << 8) | ((int)color_plane.z));
	return (rgb);
}

int			main(void)
{
	int		color;
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
			mlx_pixel_put(mlx, win, x + WIDTH / 2, y + HEIGHT / 2, color);
			y++;
		}
		x++;
	}
	mlx_hook(win, 2, 3, key, rt);
	mlx_loop(mlx);
	return (0);
}
