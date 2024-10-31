/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:28 by oouaadic          #+#    #+#             */
/*   Updated: 2024/11/01 00:04:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

inline int	colorize(t_mlx *mlx, int i)
{
	if (mlx->alt_color == 1)
	{
		if (i <= (mlx->max_iter / 3) && i > 0)
			mlx->color = BLACK + (i << 21);
		else if (i <= ((mlx->max_iter / 3) * 2) && i >= (mlx->max_iter / 3))
			mlx->color = ALT_RED - (i / 1000 << 14);
		else if (i <= mlx->max_iter && i >= ((mlx->max_iter / 3) * 2))
			mlx->color = ORANGE + (i / 10 << 7);
		else
			mlx->color = BLACK;
	}
	else if (mlx->alt_color == -1)
		return ((WHITE - BLACK) *(i - 0) / (mlx->max_iter - 0) + BLACK);
	return (mlx->color);
}
