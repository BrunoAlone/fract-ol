/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:30:49 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 21:23:03 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_julia(t_data *ju, t_imagem *img)
{
	while (ju->julia->y < ju->img_height)
	{
		while (ju->julia->x < ju->img_width)
		{
			ju->julia->newre = 1.5 * (ju->julia->x - ju->img_width / 2) / (0.5 * ju->julia->zoom * ju->img_width);
			ju->julia->newim = (ju->julia->y - ju->img_height / 2) / (0.5 * ju->julia->zoom * ju->img_height);
			while (ju->julia->n < MAX_ITERATIONS_JULIA)
			{
				ju->julia->oldre = ju->julia->newre;
				ju->julia->oldim = ju->julia->newim;
				ju->julia->newre = ju->julia->oldre * ju->julia->oldre - ju->julia->oldim * ju->julia->oldim + ju->julia->c_re;
				ju->julia->newim = 2 * ju->julia->oldre * ju->julia->oldim + ju->julia->c_im;
				if ((ju->julia->newre * ju->julia->newre + ju->julia->newim * ju->julia->newim) > 4)
				{
					lets_colorize_this_julia(ju, img);
					break;
				}
				ju->julia->n++;
			}
			ju->julia->n = 0;
			ju->julia->x++;
		}
		ju->julia->x = 0;
		ju->julia->y++;
	}
}
