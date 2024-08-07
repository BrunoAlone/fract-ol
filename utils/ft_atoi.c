/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:37:21 by brolivei          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:52 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	number_is_here2(const char *s)
{
	int	i;

	i = 0;
	while (!(s[i] >= '0' && s[i] <= '9') && s[i] != '+' && s[i] != '-')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;
	int	result;

	i = number_is_here2(nptr);
	sinal = 1;
	result = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sinal = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sinal);
}
