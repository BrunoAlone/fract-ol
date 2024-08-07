/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:06:11 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/12 15:18:43 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
/*
double	zoom_fractal(int mousecode, t_data *imagem, double zoom)
{
	if (mousecode == 4)
		zoom *= 0.9;
	else if (mousecode == 5)
		zoom *= 1.1;
	change_mandelbrot(imagem, zoom);
	if (imagem->addr >= 1)
		mlx_destroy_image(imagem->mlx, imagem->img);
}

void	manage_mouse(int mousecode, int x, int y, t_data *imagem)
{
	static double	zoom;

	(void)x;
	(void)y;
	if (zoom == 0)
		zoom = 1;
	if (mousecode == 4 || mousecode == 5)
	{
		zoom = zoom_fractal(mousecode, imagem, zoom);
		imagem->addr++;
	}
}

void	manage_events(t_data *imagem)
{
	mlx_mouse_hook(imagem->mlx_win, &manage_mouse, imagem);
}
*/
