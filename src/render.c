/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:02:33 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 19:24:32 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_pixel(t_mlx *mlx, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.real = ((((2 - -2) *(x - 0) / ((double)WIDTH - 0) + -2) * mlx->zoom)
			+ mlx->shift_x);
	z.imaginary = ((((2 - -2) *(y - 0) / ((double)HEIGHT - 0) + -2) * mlx->zoom)
			+ mlx->shift_y);
	if (mlx->is_julia == 1)
		c = (t_complex){mlx->julia_real, mlx->julia_imaginary};
	else
		c = z;
	i = -1;
	while (++i < mlx->max_iter)
	{
		z = (t_complex){((z.real * z.real) - (z.imaginary * z.imaginary))
			+ c.real, (2 * z.real * z.imaginary) + c.imaginary};
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > mlx->escape_value)
			return (my_mlx_pixel_put(mlx, x, y, colorize(mlx, i)));
	}
}

void	handel_render(t_mlx *mlx)
{
	if (mlx->is_newton == 1)
		render_newton(mlx);
	else if (mlx->is_burningship == 1)
		render_burningship(mlx);
	else
		render(mlx);
}

void	render(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			check_pixel(mlx, x, y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
