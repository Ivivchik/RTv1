/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_red_rubber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:42:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:44:41 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void      fill_mat_red_rub(t_mater *mat)
{
  mat->type_mat = ft_strdup(MAT_RED_RUBBER);
  mat->albedo = vec_new(0.9, 0.1, 0.0);
  mat->diff_col = vec_new(0.3, 0.1, 0.1);
  mat->spec_exp = 10.0;
  return ;
}
