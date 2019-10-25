/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_find_params_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:43:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			try_find_params_5(char *block1, char *block5)
{
	if ((ft_strcmp(STR_CYLINDR, block1) == 0) ||
		(ft_strcmp(STR_CONE, block1) == 0))
	{
		if (!check_str_to_double(block5))
			return (FALSE);
	}
	else
	{
		if (!check_str_to_vec3(block5))
			return (FALSE);
	}
	return (TRUE);
}

int			try_find_params_6(char *block1, char *block6)
{
	(void)(block1);
	if (!check_str_to_vec3(block6))
		return (FALSE);
	return (TRUE);
}
