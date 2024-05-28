/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:49:56 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 19:23:51 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_pixel_newton(t_mlx *mlx, int x, int y)
{
	t_complex	z;
	t_complex	fun;
	int			i;
	int			iter;

	z.real = ((((2 - -2) *(x - 0) / ((double)WIDTH - 0) + -2) * mlx->zoom)
			+ mlx->shift_x);
	z.imaginary = ((((2 - -2) *(y - 0) / ((double)HEIGHT - 0) + -2) * mlx->zoom)
			+ mlx->shift_y);
	iter = -1;
	while (++iter < mlx->max_iter)
	{
		fun = sub_complex(cube_complex(z), (t_complex){1, 0});
		z = sub_complex(z, divide_complex(fun, derivative(z)));
		i = -1;
		while (++i < mlx->roots_lenght)
		{
			if (fabs(z.real - mlx->roots[i].real) < mlx->tolerance
				&& fabs(z.imaginary - mlx->roots[i].imaginary) < mlx->tolerance)
				return (my_mlx_pixel_put(mlx, x, y, mlx->colors[i]));
		}
	}
	my_mlx_pixel_put(mlx, x, y, BLACK);
}

void	render_newton(t_mlx *mlx)
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
			check_pixel_newton(mlx, x, y);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	newton(t_mlx *mlx, int flag)
{
	mlx->is_julia = 0;
	mlx->is_burningship = 0;
	mlx->is_newton = 1;
	if (flag == 1)
		ft_mlx_init(mlx);
	render_newton(mlx);
}
