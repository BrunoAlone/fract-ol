/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:06 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/25 14:34:12 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input(int argc, char **argv)
{
	char	*str;
	t_args	args;

	str = malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
	ft_strcpy(argv[1], str);
	if (ft_strcmp(str, "Mandelbrot") != 0 && ft_strcmp(str, "Julia") != 0)
	{
		free(str);
		print_instruction();
	}
	else
		collect_args(argc, argv, &args, str);
	if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		free(str);
		lets_make_madelbrot(&args);
	}
	if (ft_strcmp(str, "Julia") == 0)
	{
		free(str);
		lets_make_julia(&args);
	}
}

void	print_instruction(void)
{
	ft_printf("To run the program you have to do as follow:\n");
	ft_printf("\n    --./fractol <name of the fractal>\n");
	ft_printf("\nThe options are:\n\n");
	ft_printf("    1º Mandelbrot\n");
	ft_printf("    2º Julia\n\n");
	ft_printf("You can change the size of the\
				sreen/image by doing like this: \n");
	ft_printf("    ./fractal Mandelbrot w<value>\
				(Value of width) h<value>(Value of heigth)\n");
	ft_printf("For the Julia set you have the\
				option of setting the initial ");
	ft_printf("value of C. For that you can do like this:\n");
	ft_printf("    ./fractal Julia ci<value>\
				(Imaginary part of c) cr<value> (Real part)\n");
	ft_printf("    Also you can add the size of image that\
			you want in the same way explained above.\n");
	exit(0);
}
