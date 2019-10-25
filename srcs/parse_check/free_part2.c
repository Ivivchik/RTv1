/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:17:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 02:21:55 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			free_tmp_free_split(char **tmp, char ***str)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free(*str);
	free(*tmp);
	return ;
}

int				wrong_param_false(void)
{
	ft_putstr("Error: wrong params in file\n");
	return (FALSE);
}
