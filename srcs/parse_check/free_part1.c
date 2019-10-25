/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:17:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/25 03:01:30 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			free_split_double_true(char ***str, char **bzero)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free((*str));
	free(*bzero);
	return (TRUE);
}

int			free_split_double_false(char ***str, char **bzero)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free((*str));
	free(*bzero);
	return (FALSE);
}

int			free_split_vec3_true(char ***str)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free((*str));
	return (TRUE);
}

int			false_free_close(char **tmp, int *fd)
{
	free(*tmp);
	close(*fd);
	return (FALSE);
}

int			false_free_close_split(char **tmp, int *fd, char ***str)
{
	int		i;

	i = -1;
	while ((*str)[++i])
		free((*str)[i]);
	free((*str));
	free(*tmp);
	close(*fd);
	return (FALSE);
}
