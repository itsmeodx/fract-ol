/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:15:44 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 23:04:51 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape || keysym == XK_Up || keysym == XK_Down
		|| keysym == XK_Left || keysym == XK_Right || keysym == XK_w
		|| keysym == XK_s || keysym == XK_a || keysym == XK_d
		|| keysym == XK_i || keysym == XK_r || keysym == XK_p || keysym == XK_m
		|| keysym == XK_PLUS || keysym == XK_MINUS || keysym == XK_space
		|| keysym == XK_1 || keysym == XK_2 || keysym == XK_3 || keysym == XK_4)
	{
		handel_keypress(keysym, mlx);
		if (keysym == XK_i)
			ft_printf("Max iterations: %d\n", mlx->max_iter);
		else if (keysym == XK_r)
			mlx->alt_color *= -1;
		if (keysym != XK_1 && keysym != XK_2
			&& keysym != XK_3 && keysym != XK_4)
			handel_render(mlx);
	}
	return (0);
}

void	handel_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		close_mlx(mlx);
	else if (keysym == XK_Up || keysym == XK_w)
		mlx->shift_y -= (0.5 * mlx->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		mlx->shift_y += (0.5 * mlx->zoom);
	else if (keysym == XK_Left || keysym == XK_a)
		mlx->shift_x -= (0.5 * mlx->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		mlx->shift_x += (0.5 * mlx->zoom);
	else if (keysym == XK_PLUS || keysym == XK_p)
		mlx->max_iter += 10;
	else if ((keysym == XK_MINUS || keysym == XK_m) && mlx->max_iter > 10)
		mlx->max_iter -= 10;
	else if (keysym == XK_1)
		mandelbrot(mlx, 0);
	else if (keysym == XK_2)
		refresh_julia(mlx, mlx->mouse_x, mlx->mouse_y);
	else if (keysym == XK_3)
		burningship(mlx, 0);
	else if (keysym == XK_4)
		newton(mlx, 0);
	else if (keysym == XK_space)
		data_init(mlx);
}

inline static void	update_zoom(int keysym, int x, int y, t_mlx *mlx)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = scale(x, mlx->zoom, mlx->shift_x);
	mouse_y = scale(y, mlx->zoom, mlx->shift_y);
	if (keysym == Button5)
	{
		mlx->zoom *= 1.05;
		mlx->max_iter = fmax(mlx->max_iter * 0.95, 20);
	}
	else if (keysym == Button4)
	{
		mlx->zoom /= 1.05;
		mlx->max_iter /= 0.95;
	}
	mlx->shift_x += mouse_x - scale(x, mlx->zoom, mlx->shift_x);
	mlx->shift_y += mouse_y - scale(y, mlx->zoom, mlx->shift_y);
}

int	mouse_press(int keysym, int x, int y, t_mlx *mlx)
{
	if (keysym == Button1 || keysym == Button4 || keysym == Button5)
	{
		if (keysym == Button1)
		{
			if (mlx->is_julia == 1)
				refresh_julia(mlx, x, y);
			return (0);
		}
		if (keysym == Button4 || keysym == Button5)
			update_zoom(keysym, x, y, mlx);
		handel_render(mlx);
	}
	return (0);
}

int	close_mlx(t_mlx *mlx)
{
	free_mlx(mlx);
	ft_printf("Exiting %s...\n", mlx->name);
	exit(0);
}
