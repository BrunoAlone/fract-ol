/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:24:06 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/18 13:33:05 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	interpolar_cor(int cor1, int cor2, double t)
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;
	int	color;

	r1 = (cor1 >> 16) & 0xFF;
	g1 = (cor1 >> 8) & 0xFF;
	b1 = cor1 & 0xFF;
	r2 = (cor2 >> 16) & 0xFF;
	g2 = (cor2 >> 8) & 0xFF;
	b2 = cor2 & 0xFF;
	r = (int)(r1 + (r2 - r1) * t);
	g = (int)(g1 + (g2 - g1) * t);
	b = (int)(b1 + (b2 - b1) * t);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	lets_colorize_this_mandel(t_data *man, t_imagem *img)
{
	double	intensidade;
	int		color;

	intensidade = (double)man->man->n / MAX_ITERATIONS;
	color = interpolar_cor(0x000000, 0x10D6DC, intensidade);
		my_mlx_pixel_put(img, man->man->x, man->man->y, color);
}
