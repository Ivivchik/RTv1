/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_find_params_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:07:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 05:42:47 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			try_find_params_4(char *block1, char *block4)
{
	(void)(block1);
	if (!check_str_to_double(block4))
		return (FALSE);
	return (TRUE);
}
