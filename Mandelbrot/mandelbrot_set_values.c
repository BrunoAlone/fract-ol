/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:55:35 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 21:25:15 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	change_mandelbrot(t_data *man, double zoom)
{
	man->man->minre = -2.0 * zoom;
	man->man->maxre = (1.0) * zoom;
	man->man->minim = (-1.5) * zoom;
	man->man->maxim = man->man->minim + (man->man->maxre - man->man->minre) * man->img_height/man->img_width;
	man->man->factorre = (man->man->maxre - man->man->minre) / (man->img_width - 1);
	man->man->factorim = (man->man->maxim - man->man->minim) / (man->img_height - 1);
	man->man->y = 0;
	man->man->x = 0;
	man->man->n = 0;
	man->man->isinside = 1;
}

t_mandelbrot	*mandelbrot_set_values(t_args *args)
{
	t_mandelbrot	*fractal;

	fractal = malloc(sizeof(t_mandelbrot));
	fractal->minre = -2.0;
	fractal->maxre = 1.0;
	fractal->minim = -1.2;
	fractal->maxim = fractal->minim + (fractal->maxre - fractal->minre) * args->height/args->width;
	fractal->factorre = (fractal->maxre - fractal->minre) / (args->width - 1);
	fractal->factorim = (fractal->maxim - fractal->minim) / (args->height - 1);
	fractal->y = 0;
	fractal->x = 0;
	fractal->n = 0;
	fractal->isinside = 1;
	return (fractal);
}
