/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:29:49 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 21:26:50 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_values_of_julia_c(int argc, char **argv, t_args *args)
{
	if ((argv[2][0] == 'c' && argv[2][1] == 'r')
		&& (argv[3][0] == 'c' && argv[3][1] == 'i'))
	{
		args->j_c_r = ft_atod(argv[2]);
		args->j_c_i = ft_atod(argv[3]);
	}
	else if ((argv[2][0] == 'c' && argv[2][1] == 'i')
			&& (argv[3][0] == 'c' && argv[3][1] == 'r'))
	{
		args->j_c_i = ft_atod(argv[2]);
		args->j_c_r = ft_atod(argv[3]);
	}
	else
		print_instruction();
	if (argc == 6)
	{
		if ((argv[4][0] == 'w') && (argv[5][0] == 'h'))
		{
			args->width = ft_atoi(argv[4]);
			args->height = ft_atoi(argv[5]);
		}
		else if ((argv[4][0] == 'h') && (argv[5][0] == 'w'))
		{
			args->height = ft_atoi(argv[4]);
			args->width = ft_atoi(argv[5]);
		}
	}
}

void	set_values_of_image(int argc, char **argv, t_args *args)
{
	if ((argv[2][0] == 'w') && (argv[3][0] == 'h'))
	{
		args->width = ft_atoi(argv[2]);
		args->height = ft_atoi(argv[3]);
	}
	else if ((argv[2][0] == 'h') && (argv[3][0] == 'w'))
	{
		args->height = ft_atoi(argv[2]);
		args->width = ft_atoi(argv[3]);
	}
	else
		print_instruction();
	if (argc == 6)
	{
		if ((argv[4][0] == 'c' && argv[4][1] == 'r')
			&& (argv[5][0] == 'c' && argv[5][1] == 'i'))
		{
			args->j_c_r = ft_atod(argv[4]);
			args->j_c_i = ft_atod(argv[5]);
		}
		if ((argv[4][0] == 'c' && argv[4][1] == 'i')
			&& (argv[5][0] == 'c' && argv[5][1] == 'r'))
		{
			args->j_c_i = ft_atod(argv[4]);
			args->j_c_r = ft_atod(argv[5]);
		}
	}
}

void	set_automatic_values(t_args *args)
{
	args->width = 700;
	args->height = 700;
	args->j_c_i = 0.27015;
	args->j_c_r = -0.7;
}

void	verify_w_and_h(t_args *args, char *str)
{
	if (args->width > 1980 || args->width < 0)
	{
		free(args->fractal);
		free(str);
		print_instruction();
	}
	if (args->height > 1080 || args->height < 0)
	{
		free(args->fractal);
		free(str);
		print_instruction();
	}
}

void	collect_args(int argc, char **argv, t_args *args, char *str)
{
	if (argv[1][0] == 'M')
		args->fractal = malloc(11 * sizeof(char));
	if (argv[1][0] == 'J')
		args->fractal = malloc(6 * sizeof(char));
	ft_strcpy(argv[1], args->fractal);
	if (argc == 4 || argc == 6)
	{
		if (argv[2][0] == 'c')
			set_values_of_julia_c(argc, argv, args);
		else if (argv[2][0] == 'w' || argv[2][0] == 'h')
			set_values_of_image(argc, argv, args);
	}
	if (argc == 4 && argv[2][0] == 'c')
	{
		args->width = 760;
		args->height = 760;
	}
	else if (argc == 4 && (argv[2][0] == 'w' || argv[2][0] == 'h'))
	{
		args->j_c_i = 0.27015;
		args->j_c_r = -0.7;
	}
	else if (argc == 2)
		set_automatic_values(args);
	verify_w_and_h(args, str);
}
