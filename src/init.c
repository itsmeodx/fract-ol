/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:56:50 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 19:35:10 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_init(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->colors = NULL;
	mlx->roots = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_mlx_error(mlx, "mlx initialization failed\n");
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, mlx->name);
	if (!mlx->win)
		ft_mlx_error(mlx, "window initialization failed\n");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		ft_mlx_error(mlx, "image initialization failed\n");
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		ft_mlx_error(mlx, "image address initialization failed\n");
	mlx->initialized = 1;
	events_init(mlx);
	data_init(mlx);
}

void	events_init(t_mlx *mlx)
{
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, key_press, mlx);
	mlx_hook(mlx->win, DestroyNotify, StructureNotifyMask, close_mlx, mlx);
	mlx_mouse_hook(mlx->win, mouse_press, mlx);
}

void	ft_newton_init(t_mlx *mlx)
{
	if (!mlx->colors)
		mlx->colors = malloc(sizeof(int) * 3);
	if (!mlx->colors)
	{
		free_mlx(mlx);
		ft_printf("Error: malloc colors failed\n");
		exit(1);
	}
	mlx->colors[0] = RED;
	mlx->colors[1] = GREEN;
	mlx->colors[2] = BLUE;
	mlx->tolerance = 0.000001;
	if (!mlx->roots)
		mlx->roots = malloc(sizeof(t_complex) * 3);
	if (!mlx->roots)
	{
		free_mlx(mlx);
		ft_printf("Error: malloc roots failed\n");
		exit(1);
	}
	mlx->roots[0] = (t_complex){1.0, 0.0};
	mlx->roots[1] = (t_complex){-0.5, sqrt(3) / 2};
	mlx->roots[2] = (t_complex){-0.5, -(sqrt(3) / 2)};
	mlx->roots_lenght = 3;
}

void	data_init(t_mlx *mlx)
{
	mlx->max_iter = 100;
	mlx->zoom = 1.0;
	mlx->escape_value = 4.0;
	mlx->color = BLACK;
	mlx->alt_color = 1;
	ft_newton_init(mlx);
	mlx->shift_x = 0.0;
	mlx->shift_y = 0.0;
	mlx->offset_x = 0.0;
	mlx->offset_y = 0.0;
	mlx->old_mouse_x = 0.0;
	mlx->old_mouse_y = 0.0;
	mlx->mouse_x = 0.0;
	mlx->mouse_y = 0.0;
}
