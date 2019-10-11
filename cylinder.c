/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:25:40 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/12 00:31:07 by hkuhic           ###   ########.fr       */
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

double		*intersection_ray_cylinder(t_coord a, t_coord b, t_cylinder s, t_rt *rt)
{
	double	*t;
	t_coord	c;
	t_coord	v;
	t_coord x;
	double		r;

	if (!(t = (double *)malloc(sizeof(double *) * 3)))
		return (0);
	c = s.start;
	v = s.vector;
	r =	s.radius;
	x = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	rt->k1 = dot_prod(b, b) - dot_prod(b, v) * dot_prod(b, v);
	rt->k2 = 2 * (dot_prod(b, x) - dot_prod(b, v) * dot_prod(x, v));
	rt->k3 = dot_prod(x, x) - dot_prod(x, v) * dot_prod(x, v) - r * r;
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

t_coord		dot_color(t_coord a, t_coord b, t_rt *rt)
{
	int i = 0;
	rt->close_t = TMAX;
	t_coord color_cylinder;
	t_cylinder c[2];
	t_coord z1;
	t_coord z2;
	t_coord	p;
	t_coord n;
	t_coord x;
	double m;
	c[0].start = init_coord(0, 0, 3);
	c[0].vector = init_coord(5, -4, 3);
	c[0].vector = init_coord(c[0].vector.x - c[0].start.x, c[0].vector.y - c[0].start.y, c[0].vector.z - c[0].start.z);
	c[0].vector = init_coord(c[0].vector.x / len_v(c[0].vector), c[0].vector.y / len_v(c[0].vector), c[0].vector.z / len_v(c[0].vector));
	c[0].color = init_coord(255, 100, 0);
	c[0].radius = 1;
	c[0].blesk = 1000;
	c[1].start = init_coord(0, 0, 4);
	c[1].vector = init_coord(0, 0, 3);
	c[1].vector = init_coord(c[0].vector.x - c[0].start.x, c[0].vector.y - c[0].start.y, c[0].vector.z - c[0].start.z);
	c[1].vector = init_coord(c[0].vector.x / len_v(c[0].vector), c[0].vector.y / len_v(c[0].vector), c[0].vector.z / len_v(c[0].vector));
	c[1].color = init_coord(0, 100, 0);
	c[1].radius = 1;
	c[1].blesk = 100;
	c[0].max = sum_vect(c[0].start, mult(c[0].vector, 2));
	color_cylinder = init_coord(0, 0, 0);
	double *t;
	while (i < 2)
	{
		t = intersection_ray_cylinder(a, b, c[i], rt);
		z1 = sum_vect(a, mult(b, t[0]));
		z2 = sum_vect(a, mult(b, t[1]));
		x = init_coord(a.x - c[i].start.x, a.y - c[i].start.y, a.z - c[i].start.z);
		if (t[0] >= TMIN && t[0] <= TMAX && t[0] < rt->close_t)// && (z1.y <= c.max.y && z1.y >= c.start.y))
		{
			m = dot_prod(b, c[i].vector) * t[0] + dot_prod(x, c[i].vector);
			rt->close_t = t[0];
			p = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
			a.z + rt->close_t * b.z);
			n = init_coord(p.x - c[i].start.x, p.y - c[i].start.y,
			p.z - c[i].start.z);
			n = init_coord(n.x / len_v(n), n.y / len_v(n),
			n.z / len_v(n));
			//color_cylinder = c.color;
			color_cylinder = mult(c[i].color, computer_lighting(p, n, mult(b, -1), c[i].blesk,rt));
		}
		if (t[1] > TMIN && t[1] < TMAX && t[1] < rt->close_t) //&& (z2.y <= c.max.y && z2.y >= c.start.y))
		{
			m = dot_prod(b, c[i].vector) * t[1] + dot_prod(x, c[i].vector);
			rt->close_t = t[1];
			p = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
			a.z + rt->close_t * b.z);
			n = init_coord(p.x - c[i].start.x - c[i].vector.x * m, p.y - c[i].start.y - c[i].vector.y * m,
			p.z - c[i].start.z - c[i].vector.z * m);
			n = init_coord(n.x / len_v(n), n.y / len_v(n), n.z / len_v(n));
			//color_cylinder = c.color;
			color_cylinder = mult(c[i].color, computer_lighting(p, n, mult(b, -1), c[i].blesk,rt));
			//computer_lighting(p, n, mult(b, -1), s[i].blesk, rt));
		}
		i++;
	}
	return(color_cylinder);
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