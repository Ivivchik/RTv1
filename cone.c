/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:33:08 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/12 00:59:56 by hkuhic           ###   ########.fr       */
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

double		computer_lighting(t_coord p, t_coord n, t_rt *rt)//t_coord v, int s, t_rt *rt)
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
		// if (s != -1)
		// {
		// 	r = init_coord(2 * n.x * dot_prod(n, li) - li.x,
		// 	2 * n.y * dot_prod(n, li) - li.y,
		// 	2 * n.z * dot_prod(n, li) - li.z);
		// 	rt->r_dot_v = dot_prod(r, v);
		// 	if (rt->r_dot_v > 0)
		// 		rt->intens += l[j].inten * pow(rt->r_dot_v /
		// 		(len_v(r) * len_v(v)), s);
		// }
		j++;
	}
	return (rt->intens);
}

double		*intersection_ray_cone(t_coord a, t_coord b, t_cone s, t_rt *rt)
{
	double	*t;
	t_coord	c;
	t_coord	v;
	t_coord x;
	double		k;

	if (!(t = (double *)malloc(sizeof(double *) * 3)))
		return (0);
	c = s.start;
	v = s.vector;
	k =	s.k;
	x = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	rt->k1 = dot_prod(b, b) - (1 + k * k) * dot_prod(b, v) * dot_prod(b, v);
	rt->k2 = 2 * (dot_prod(b, x) - (1 + k * k) * dot_prod(b, v) * dot_prod(x, v));
	rt->k3 = dot_prod(x, x) - (1 + k * k) * dot_prod(x, v) * dot_prod(x, v);
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
	rt->close_t = TMAX;
	t_cone c;
	t_coord x;
	t_coord p;
	t_coord n;
	double m;
	t_coord color_cone;
	c.start = init_coord(0, 0, 5);
	c.vector = init_coord(-5, 5, 5);
	c.vector = init_coord(c.vector.x - c.start.x, c.vector.y - c.start.y, c.vector.z - c.start.z);
	c.vector = init_coord(c.vector.x / len_v(c.vector), c.vector.y / len_v(c.vector), c.vector.z / len_v(c.vector));
	c.color = init_coord(255, 100, 1);
	c.k = 0.45;
	c.blesk = 100;
	double *t;
	t = intersection_ray_cone(a, b, c, rt);
	x = init_coord(a.x - c.start.x, a.y - c.start.y, a.z - c.start.z);
	if (t[0] >= TMIN && t[0] <= TMAX && t[0] < rt->close_t)// && (z1.y <= c.max.y && z1.y >= c.start.y))
	{
		m = dot_prod(b, c.vector) * t[0] + dot_prod(x, c.vector);
		rt->close_t = t[0];
		p = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
		a.z + rt->close_t * b.z);
		n = init_coord(p.x - c.start.x - (1 + c.k * c.k) * c.vector.x * m, p.y - c.start.y - (1 + c.k * c.k) * c.vector.y * m,
		p.z - c.start.z - (1 + c.k * c.k) * c.vector.z * m);
		n = init_coord(n.x / len_v(n), n.y / len_v(n),
		n.z / len_v(n));
		//color_cone = c.color;
		color_cone = mult(c.color, computer_lighting(p, n, rt));// mult(b, -1), c.blesk,rt));
	}
	if (t[1] > TMIN && t[1] < TMAX && t[1] < rt->close_t) //&& (z2.y <= c.max.y && z2.y >= c.start.y))
	{
		m = dot_prod(b, c.vector) * t[1] + dot_prod(x, c.vector);
		rt->close_t = t[1];
		p = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
		a.z + rt->close_t * b.z);
		n = init_coord(p.x - c.start.x - (1 + c.k * c.k) * c.vector.x * m, p.y - c.start.y - (1 + c.k * c.k) * c.vector.y * m,
		p.z - c.start.z - (1 + c.k * c.k) * c.vector.z * m);
		n = init_coord(n.x / len_v(n), n.y / len_v(n),
		n.z / len_v(n));
		//color_cone = c.color;
		color_cone = mult(c.color, computer_lighting(p, n, rt));// mult(b, -1), c.blesk,rt));
	}	
	return(color_cone);
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