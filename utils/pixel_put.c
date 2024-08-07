/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:28:02 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/12 15:10:37 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_imagem *imagem, int x, int y, int color)
{
	char	*dst;

	dst = imagem->addr + (y * imagem->line_length + x * (imagem->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
