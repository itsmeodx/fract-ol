/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:33:41 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 15:33:58 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_mlx *mlx, int flag)
{
	mlx->is_newton = 0;
	mlx->is_julia = 0;
	mlx->is_burningship = 0;
	if (flag == 1)
		ft_mlx_init(mlx);
	render(mlx);
}
