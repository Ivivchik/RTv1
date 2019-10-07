#include "rt.h"
#include <stdio.h>

t_coord		tranform_to_viewport(double x, double y)
{
	t_coord	view_port;

	view_port.x = (x * 1 / WIDTH);
	view_port.y = (y * 1 / HEIGHT);
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

double		dot_product(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		*intersection_ray_sphere(t_coord a, t_coord b, t_sphere s)
{
	double	*t ;
	double k1;
	double k3;
	double k2;
	t_coord	c;
	t_coord v;
	int		r;
	double	dis;
	if (!(t = (double *)malloc(sizeof(double *) * 3)))
	{
		return (0);
	}
	c = s.center;
	r = s.radius;
	v = init_coord(a.x - c.x, a.y - c.y, a.z - c.z);
	k1 = dot_product(b, b);
	k2 = 2 * dot_product(v, b);
	k3 = dot_product(v, v) - r * r;
	dis = k2 * k2 - 4 * k1 * k3;
	if (dis < 0)
	{
		t[0] = TMAX;
		t[1] = TMAX;
		t[2] = '\0';
		return(t);
	}
	t[0] = (-k2 + sqrt(dis)) / (2 * k1);
	t[1] = (-k2 - sqrt(dis)) / (2 * k1);
	t[2] = '\0';
	return (t);
}

double		dot_color(t_coord a, t_coord b)
{
	int		close_t;
	int		close_sph;
	t_sphere s[3];
	double	*t;
	int i = 0;
	s[0].center = init_coord(0, 0, 10);
	s[0].radius = 1;
	s[0].color = init_coord(255, 0, 0);
	s[1].center = init_coord(1, 0, 4);
	s[1].radius = 1;
	s[1].color = init_coord(7889, 0, 0);
	s[2].center = init_coord(-2, 0, 4);
	s[2].radius = 1;
	s[2].color = init_coord(45646546, 0, 0);

	close_sph = 0;
	close_t = TMAX;
	while (i < 3)
	{
		t = intersection_ray_sphere(a, b, s[i]);
		if (t[0] >= TMIN && t[0] <= TMAX && t[0] < close_t)
		{
			close_t = t[0];
			close_sph = s[i].color.x;
		}
		if (t[1] >= TMIN && t[1] <= TMAX && t[1] < close_t)
		{
			close_t = t[1];
			close_sph = s[i].color.x;
		}
		i++;
	}
	if (close_sph == 0)
			return (0);
	return (close_sph);
}

int main(void)
{
	double color;
	t_coord a;
	void *mlx;
	void *win;
	int x;
	int y;
	t_coord camera = init_coord(0, 0, 0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "RTv1");
	// a = tranform_to_viewport(500, 500);
	// printf("%f\n", a.x);
	// printf("%f\n", a.y);
	// printf("%f\n", a.z);
	// t = intersection_ray_sphere(camera, a, s);
	// int i = 0;
	// while (t[i])
	// 	printf("%f ", t[i++]);
	// printf("\n");
	// color = dot_color(camera, a);
	// printf("%f\n", color);
	x = -WIDTH / 2 + 1;
	while (x > -WIDTH / 2 && x < WIDTH / 2)
	{
		y = -HEIGHT / 2 + 1;
		while (y > -HEIGHT / 2 && y < HEIGHT / 2)
		{
			a = tranform_to_viewport(x, y);
			color = dot_color(camera, a);
			mlx_pixel_put(mlx, win, x + WIDTH / 2, y + HEIGHT / 2, color);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
