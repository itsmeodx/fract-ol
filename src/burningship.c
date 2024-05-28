/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:14:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 19:27:52 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_pixel_burningship(t_mlx *mlx, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.real = ((((2 - -2) *(x - 0) / ((double)WIDTH - 0) + -2) * mlx->zoom)
			+ mlx->shift_x);
	z.imaginary = ((((2 - -2) *(y - 0) / ((double)HEIGHT - 0) + -2) * mlx->zoom)
			+ mlx->shift_y);
	c = z;
	i = 0;
	while (i < mlx->max_iter)
	{
		if (z.real < 0)
			z.real = -z.real;
		if (z.imaginary < 0)
			z.imaginary = -z.imaginary;
		z = (t_complex){((z.real * z.real) - (z.imaginary * z.imaginary))
			+ c.real, (2 * z.real * z.imaginary) + c.imaginary};
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > mlx->escape_value)
			return (my_mlx_pixel_put(mlx, x, y, colorize(mlx, i)));
		i++;
	}
}

void	render_burningship(t_mlx *mlx)
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
			check_pixel_burningship(mlx, x, y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	burningship(t_mlx *mlx, int flag)
{
	mlx->is_newton = 0;
	mlx->is_julia = 0;
	mlx->is_burningship = 1;
	if (flag == 1)
		ft_mlx_init(mlx);
	render_burningship(mlx);
}
