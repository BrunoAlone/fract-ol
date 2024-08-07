/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:21:18 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/10 15:47:16 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandelbrot(t_data *man, t_imagem *img)
{
	while(man->man->y++ < man->img_height)
	{
		man->man->c_im = man->man->maxim - man->man->y * man->man->factorim;
		man->man->x = 0;
		while (man->man->x++ < man->img_width)
		{
			man->man->c_re = man->man->minre + man->man->x * man->man->factorre;
			man->man->z_re = man->man->c_re;
			man->man->z_im = man->man->c_im;
			man->man->n = 0;
			while (man->man->n++ < MAX_ITERATIONS)
			{
				man->man->z_re2 = man->man->z_re * man->man->z_re;
				man->man->z_im2 = man->man->z_im * man->man->z_im;
				if (man->man->z_im2 + man->man->z_re2 > 4)
				{
					lets_colorize_this_mandel(man, img);
					break;
				}
				man->man->z_im = 2 * man->man->z_re * man->man->z_im + man->man->c_im;
				man->man->z_re = man->man->z_re2 - man->man->z_im2 + man->man->c_re;
			}
			//lets_colorize_this_mandel(man, img);
		}
	}
}
