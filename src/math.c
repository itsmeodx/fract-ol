/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:26:13 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 16:54:16 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline double	scale(double x, double zoom, double shift)
{
	return ((x - WIDTH / 2) * (4.0 / WIDTH * zoom) + shift);
}

inline static double	ft_atod_fractional(char *str, double result, int i)
{
	double	len;
	double	decimal;

	len = 1;
	decimal = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		len *= 10;
		decimal = decimal * 10 + (str[i] - '0');
		i++;
	}
	result += decimal / len;
	return (result);
}

inline double	ft_atod(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		result = ft_atod_fractional(str, result, i);
	}
	return (result * sign);
}

double	dabs(double z)
{
	if (z < 0)
		return (-z);
	return (z);
}
