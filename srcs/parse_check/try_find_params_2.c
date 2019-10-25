/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_find_params_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:58:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			try_find_params_2(char *block1, char *block2)
{
	if (ft_strcmp(STR_AMBIENT, block1) == 0)
	{
		if (!check_str_to_double(block2))
			return (FALSE);
	}
	else
	{
		if (!check_str_to_vec3(block2))
			return (FALSE);
	}
	return (TRUE);
}
