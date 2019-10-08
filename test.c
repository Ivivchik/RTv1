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

double		dot_product(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		len_vector(t_coord a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

double		sum_coord(t_coord a)
{
	return (a.x + a.y + a.z);
}

t_coord		mult(t_coord a, double k)
{
	t_coord c;
	c.x = a.x * k;
	c.y = a.y * k;
	c.z = a.z * k;
	return (c);
}
double		computer_lighting(t_coord p, t_coord n, t_coord v, int s)
{
	t_light l[5];
	t_coord li;
	t_coord r;
	double i = 0;
	double n_dot_l;
	double r_dot_v;

	l[0].intensity = 0.2;
	l[0].position = init_coord(0, 0, 0);
	l[1].intensity = 0.3;
	l[1].position = init_coord(2, 1, 0);
	l[2].intensity = 0.3;
	l[2].position = init_coord(1, 4, 4);
	int j = 0;
	while (j < 3)
	{
		li = init_coord(l[j].position.x - p.x, l[j].position.y - p.y, l[j].position.z - p.z);
		n_dot_l = dot_product(li, n);
		if (n_dot_l > 0)
			i += l[j].intensity * n_dot_l / (len_vector(n) * len_vector(li));
		if (s != -1)
		{
			r = init_coord(2 * n.x * dot_product(n, li) - li.x, 2 * n.y * dot_product(n, li) - li.y, 2 * n.z * dot_product(n, li) - li.z);
			r_dot_v = dot_product(r, v);
			if (r_dot_v > 0)
				i += l[j].intensity * pow(r_dot_v / (len_vector(r) * len_vector(v)), s);
		}

		j++;
	}
	return (i);
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

t_coord		dot_color(t_coord a, t_coord b)
{
	double		close_t;
	t_coord		close_sph;
	t_coord p;
	t_coord n;

	t_sphere s[4];
	double	*t;
	int i = 0;
	s[0].center = init_coord(0, -1, 3);
	s[0].radius = 1;
	s[0].color = init_coord(255, 0, 0);
	s[0].blesk = 500;
	s[1].center = init_coord(2, 0, 4);
	s[1].radius = 1;
	s[1].color = init_coord(0, 0, 255);
	s[1].blesk = 500;
	s[2].center = init_coord(-2, 0, 4);
	s[2].radius = 1;
	s[2].color = init_coord(0, 255, 0);
	s[2].blesk = 10;
	s[3].center = init_coord(0, -5001, 0);
	s[3].radius = 5000;
	s[3].color = init_coord(255, 255, 0);
	s[3].blesk = 1000;
	close_t = TMAX;
	int comp;
	// init_coord(-1 * b.x, -1 * b.y, -1 * b.z), s[i].blesk
	while (i < 4)
	{
		t = intersection_ray_sphere(a, b, s[i]);
		if (t[0] >= TMIN && t[0] <= TMAX && t[0] < close_t)
		{
			close_t = t[0];
			p = init_coord(a.x + close_t * b.x, a.y + close_t * b.y, a.z + close_t * b.z);
			n = init_coord(p.x - s[i].center.x, p.y - s[i].center.y, p.z - s[i].center.z);
			n = init_coord(n.x / len_vector(n), n.y / len_vector(n), n.z / len_vector(n));
			close_sph = mult(s[i].color, computer_lighting(p, n, mult(b, -1), s[i].blesk));
		}
		if (t[1] >= TMIN && t[1] <= TMAX && t[1] < close_t)
		{
			close_t = t[1];
			p = init_coord(a.x + close_t * b.x, a.y + close_t * b.y, a.z + close_t * b.z);
			n = init_coord(p.x - s[i].center.x, p.y - s[i].center.y, p.z - s[i].center.z);
			n = init_coord(n.x / len_vector(n), n.y / len_vector(n), n.z / len_vector(n));
			close_sph = mult(s[i].color, computer_lighting(p, n, mult(b, -1), s[i].blesk));
		}
		i++;
	}
	return (close_sph);
}

int main(void)
{
	t_coord		color;
	t_coord		a;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	t_coord		camera;
	int rgb;

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
			rgb = (((int)color.x << 16) | ((int)color.y<<8) | ((int)color.z));
			mlx_pixel_put(mlx, win, x + WIDTH / 2, y + HEIGHT / 2, rgb);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
