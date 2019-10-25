/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_find_params_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/24 22:01:36 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			try_find_params_3(char *block1, char *block3)
{
	if ((ft_strcmp(STR_LIGHT, block1) == 0) ||
		(ft_strcmp(STR_SPHERE, block1) == 0))
	{
		if (!check_str_to_double(block3))
			return (FALSE);
	}
	else
	{
		if (!check_str_to_vec3(block3))
			return (FALSE);
	}
	return (TRUE);
}
