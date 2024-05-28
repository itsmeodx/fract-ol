/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:32:11 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/28 02:06:46 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_old(double x, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) *(x - 0) / (old_max - 0) + new_min);
}

void	refresh_julia(t_mlx *mlx, double x, double y)
{
	mlx->is_newton = 0;
	mlx->is_burningship = 0;
	mlx->is_julia = 1;
	mlx->julia_real = scale_old(x, -2, 2, WIDTH);
	mlx->julia_imaginary = scale_old(y, -2, 2, HEIGHT);
	render(mlx);
}

void	julia(t_mlx *mlx, char *real, char *imaginary, int flag)
{
	mlx->is_newton = 0;
	mlx->is_burningship = 0;
	mlx->is_julia = 1;
	mlx->julia_real = ft_atod(real);
	mlx->julia_imaginary = ft_atod(imaginary);
	if (flag == 1)
		ft_mlx_init(mlx);
	render(mlx);
}
