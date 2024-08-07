/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:06:40 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/24 18:31:35 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	zoom_thing(int mousecode, t_data *window, double zoom)
{
	if (!(window->man))
	{
	if (mousecode == 5)
		zoom *= 0.9;
	else if (mousecode == 4)
		zoom *= 1.1;
	change_julia(window, zoom);
	if (window->add >= 1)
		mlx_destroy_image(window->mlx, window->aux.img);
	lets_make_julia_zoom(window);
	}
	else
	{
		if (mousecode == 4)
			zoom *= 0.9;
		else if (mousecode == 5)
			zoom *= 1.1;
		change_mandelbrot(window, zoom);
		if (window->add >= 1)
			mlx_destroy_image(window->mlx, window->aux.img);
		lets_make_madelbrot_zoom(window);
	}
	return (zoom);
}

int	mouse_manipulation(int mousecode, int x, int y, t_data *window)
{
	static double	zoom;

	(void)x;
	(void)y;
	if (zoom == 0)
		zoom = 1;
	if (mousecode == 4 || mousecode == 5)
	{
		zoom = zoom_thing(mousecode, window, zoom);
		window->add++;
	}
	return (0);
}

int	close_window(int keycode, t_data *window)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(window->mlx, window->img.img);
		mlx_destroy_window(window->mlx, window->mlx_win);
		if (window->add != 0)
			mlx_destroy_image(window->mlx, window->aux.img);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		if (!(window->man))
			free(window->julia);
		else
			free(window->man);
		exit(0);
	}
	return (0);
}

int	close_window2(t_data *window)
{
	mlx_destroy_image(window->mlx, window->img.img);
	mlx_destroy_window(window->mlx, window->mlx_win);
	if (window->add != 0)
		mlx_destroy_image(window->mlx, window->aux.img);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	if (!(window->man))
		free(window->julia);
	else
		free(window->man);
	exit(0);
	return (0);
}

void	ft_events_endeling(t_data *window)
{
	mlx_mouse_hook(window->mlx_win, &mouse_manipulation, window);
	mlx_key_hook(window->mlx_win, close_window, window);
	mlx_hook(window->mlx_win, 17, 0, close_window2, window);
}
