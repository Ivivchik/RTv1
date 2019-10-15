/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ivory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:42:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/10/12 01:47:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void      fill_mat_ivory(t_mater *mat)
{
  mat->type_mat = ft_strdup(MAT_IVORY);
  mat->albedo = vec_new(0.6, 0.3, 0.1);
  mat->diff_col = vec_new(0.4, 0.4, 0.3);
  mat->spec_exp = 50.0;
  return ;
}
