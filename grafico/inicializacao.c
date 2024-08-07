/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializacao.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:16:39 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/18 16:39:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_data *window, t_args *args)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		exit(1);
	if (ft_strcmp("Mandelbrot", args->fractal) == 0)
	{
		window->mlx_win = mlx_new_window(window->mlx, args->width, args->height, "Mandelbrot");
		window->add = 0;
	}
	if (ft_strcmp("Julia", args->fractal) == 0)
	{
		window->mlx_win = mlx_new_window(window->mlx, args->width, args->height, "Julia");
		window->add = 0;
	}
	if (!window->mlx_win)
	{
		free(window);
		free(args);
		exit(2);
	}
}
