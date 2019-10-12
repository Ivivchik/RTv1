/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:05:17 by hkuhic            #+#    #+#             */
/*   Updated: 2019/10/12 03:51:27 by hkuhic           ###   ########.fr       */
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

double		computer_lighting(t_coord p, t_coord n, t_rt *rt)//, t_coord v, int s, t_rt *rt)
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
	l[0].pos = init_coord(-1, -1, 1);
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
	t_coord color_plane = init_coord(255, 255, 255);
	t_plane p[3];
	t_coord c;
	p[0].point = init_coord(0, 5, 5);
	p[0].normal = init_coord(0, 0, -1);
	p[0].blesk = 1000;
	p[0].color = init_coord(0, 0, 205);
	p[1].point = init_coord(0, 0, 1);
	p[1].normal = init_coord(0, 1, 3);
	p[1].blesk = 1000;
	p[1].color = init_coord(169, 169, 169);
	p[2].point = init_coord(0, 0, 0.7);
	p[2].normal = init_coord(0, -1, 3);
	p[2].blesk = 1000;
	p[2].color = init_coord(47, 79, 79);
	double t;
	int i = 0;
	while (i < 3)
	{
		t = intersection_ray_plane(a, b, p[i]);
		if (t >= TMIN && t <= TMAX && t < rt->close_t)
		{
			rt->close_t = t;
			p[i].normal = init_coord(p[i].normal.x / len_v(p[i].normal),
			p[i].normal.y / len_v(p[i].normal), p[i].normal.z / len_v(p[i].normal));
			c = init_coord(a.x + rt->close_t * b.x, a.y + rt->close_t * b.y,
			a.z + rt->close_t * b.z);
			color_plane = mult(p[i].color, computer_lighting(c, p[i].normal, rt));//, mult(b , -1), p[i].blesk, rt));
		}
		i++;
	}
	return(color_plane);
}

void	draw(t_rt *rt)
{
	t_coord		color;
	t_coord		a;
	t_coord camera;
	int rgb;
	int x;
	int y;
	camera = init_coord(0, 0, 0);
	x = -WIDTH / 2 + 1;
	while (x > -WIDTH / 2 && x < WIDTH / 2)
	{
		y = -HEIGHT / 2 + 1;
		while (y > -HEIGHT / 2 && y < HEIGHT / 2)
		{
			a = tranform_to_viewport(x, y);
			color = dot_color(camera, a, rt);
			rgb = (((int)color.x << 16) | ((int)color.y << 8) | ((int)color.z));
			mlx_pixel_put(rt->mlx, rt->win, x + WIDTH / 2, y + HEIGHT / 2, rgb);
			y++;
		}
		x++;
	}
}

int			main(void)
{
	t_rt		*rt;

	rt = (t_rt *)malloc(sizeof(t_rt));
	rt->mlx = mlx_init();
	rt->win = mlx_new_window(rt->mlx, WIDTH, HEIGHT, "RTv1");
	draw(rt);
	mlx_hook(rt->win, 2, 3, key, rt);
	mlx_loop(rt->mlx);
	return (0);
}