/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:03:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 19:07:23 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_mlx(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->colors)
		free(mlx->colors);
	if (mlx->roots)
		free(mlx->roots);
}

void	ft_mlx_error(t_mlx *mlx, char *msg)
{
	free_mlx(mlx);
	ft_printf("Error: %s\n", msg);
	exit(1);
}
