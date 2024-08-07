/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:42:24 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 21:23:49 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	change_julia(t_data *window, double zoom)
{
	window->julia->zoom = zoom;
	window->julia->movex = 0;
	window->julia->movey = 0;
	//window->julia->r_Re = args->j_c_R;
	//window->julia->i_Im = args->j_c_I;
	window->julia->y = 0;
	window->julia->x = 0;
	window->julia->n = 0;
}

t_julia	*julia_set_values(t_args *args)
{
	t_julia	*ju;

	ju = malloc(sizeof(t_julia));
	ju->zoom = 1;
	ju->movex = 0;
	ju->movey = 0;
	ju->c_re = args->j_c_r;
	ju->c_im = args->j_c_i;
	ju->y = 0;
	ju->x = 0;
	ju->n = 0;
	return (ju);
}
