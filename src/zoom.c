/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:18:06 by oouaadic          #+#    #+#             */
/*   Updated: 2024/04/23 19:26:34 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_zoom(int keysym, int x, int y, t_mlx *mlx)
{
	if (keysym == Button5)
	{
		mlx->old_mouse_x = scale(x, mlx->zoom, mlx->shift_x);
		mlx->old_mouse_y = scale(y, mlx->zoom, mlx->shift_y);
		mlx->zoom *= 1.15;
		mlx->max_iter *= 0.95;
	}
	else if (keysym == Button4)
	{
		mlx->old_mouse_x = scale(x, mlx->zoom, mlx->shift_x);
		mlx->old_mouse_y = scale(y, mlx->zoom, mlx->shift_y);
		mlx->zoom *= 0.85;
		mlx->max_iter /= 0.95;
	}
}
