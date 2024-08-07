/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:28:07 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:28 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	number_is_here(char *s)
{
	int	i;

	i = 0;
	while (!(s[i] >= '0' && s[i] <= '9') && s[i] != '+' && s[i] != '-')
		i++;
	return (i);
}

double	ft_atod(char *s)
{
	double	number;
	int		signal;
	int		i;
	double	n;

	signal = 1;
	number = 0;
	n = 1;
	i = number_is_here(s);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			signal = -1;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
		number = number * 10 + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
	{
		number = number + (s[i++] - '0') * 0.1 * n;
		n /= 10;
	}
	return ((number) * signal);
}
