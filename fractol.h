/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:16:40 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 21:25:22 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#  define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

/*Maximo de iteracoes para pontos no Mandelbrot*/
# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 150
# endif

/*Maximo de iteracoes para pontos no Julia Set*/
# ifndef MAX_ITERATIONS_JULIA
#  define MAX_ITERATIONS_JULIA 300
# endif

typedef struct t_julia
{
	double	c_re;
	double	c_im;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom;
	double	movex;
	double	movey;
	int		width;
	int		heigth;
	int		y;
	int		x;
	int		n;
}				t_julia;

typedef struct t_mandelbrot
{
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	factorre;
	double	factorim;
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_re2;
	double	z_im;
	double	z_im2;
	double	zoom;
	int		n;
	int		x;
	int		y;
	int		width;
	int		heigth;
	int		isinside;
}				t_mandelbrot;

typedef struct t_imagem
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imagem;

typedef struct t_args
{
	char	*fractal;
	int		width;
	int		height;
	double	j_c_r;
	double	j_c_i;
}				t_args;

typedef struct t_data
{
	void			*mlx;
	void			*mlx_win;
	int				img_width;
	int				img_height;
	t_mandelbrot	*man;
	t_julia			*julia;
	t_imagem		img;
	t_imagem		aux;
	int				add;
}				t_data;

/*Main*/
void	print_instruction(void);
void	check_input(int argc, char **argv);
void	collect_args(int argc, char **argv, t_args *args, char *str);

/*Mandelbrot*/
t_mandelbrot	*mandelbrot_set_values(t_args *args);
void			lets_make_madelbrot(t_args *args);
void			lets_make_madelbrot_zoom(t_data *window);
void			draw_mandelbrot(t_data *man, t_imagem *img);
void			change_mandelbrot(t_data *man, double zoom);
void			lets_colorize_this_mandel(t_data *man, t_imagem *img);

/*Julia*/
void	lets_make_julia(t_args *args);
t_julia	*julia_set_values(t_args *args);
void	draw_julia(t_data *ju, t_imagem *img);
void	lets_colorize_this_julia(t_data *ju, t_imagem *img);
void	change_julia(t_data *window, double zoom);
void	lets_make_julia_zoom(t_data *window);

/*MLX*/
void	init_mlx(t_data *window, t_args *args);
void	ft_events_endeling(t_data *window);
int		mouse_manipulation(int mousecode, int x, int y, t_data *window);

/*Utils*/
size_t	ft_strlen(const char *s);
double	ft_atod(char *s);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *nptr);

void	ft_strcpy(char *src, char *new);
void	my_mlx_pixel_put(t_imagem *imagem, int x, int y, int color);
//void	manage_events(t_data *imagem);

#endif
