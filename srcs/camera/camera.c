/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkuhic <hkuhic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 03:19:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/15 23:31:55 by hkuhic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		tranform_to_viewport(int x, int y, int w, int h)
{
	t_vec3	view_port;

	view_port.x = (x * 10.0 / w);
	view_port.y = (y * -10.0 / h);
	view_port.z = 1.0;
	return (view_port);
}
