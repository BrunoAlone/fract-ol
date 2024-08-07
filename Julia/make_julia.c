/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:35:40 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/24 09:32:34 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	lets_make_julia(t_args *args)
{
	t_data	window;

	init_mlx(&window, args);
	window.img.img = mlx_new_image(window.mlx, args->width, args->height);
	window.img.addr = mlx_get_data_addr(window.img.img, &window.img.bits_per_pixel, &window.img.line_length, &window.img.endian);
	window.julia = julia_set_values(args);
	window.man = NULL;
	free(args->fractal);
	window.img_height = args->height;
	window.img_width = args->width;
	draw_julia(&window, &window.img);
	mlx_put_image_to_window(window.mlx, window.mlx_win, window.img.img, 0, 0);
	ft_events_endeling(&window);
	mlx_loop(window.mlx);
}

void	lets_make_julia_zoom(t_data *window)
{
	window->aux.img = mlx_new_image(window->mlx, window->img_width, window->img_height);
	window->aux.addr = mlx_get_data_addr(window->aux.img, &window->aux.bits_per_pixel, &window->aux.line_length, &window->aux.endian);
	draw_julia(window, &window->aux);
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->aux.img, 0, 0);
}
