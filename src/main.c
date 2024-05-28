/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:54:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 15:33:51 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.initialized = 0;
	if (ac == 2 || ac == 4)
	{
		mlx.name = av[1];
		if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
			mandelbrot(&mlx, 1);
		else if (ac == 4 && !ft_strcmp(av[1], "julia"))
			julia(&mlx, av[2], av[3], 1);
		else if (ac == 2 && !ft_strcmp(av[1], "newton"))
			newton(&mlx, 1);
		else if (ac == 2 && !ft_strcmp(av[1], "burningship"))
			burningship(&mlx, 1);
		else
			ft_printf("Invalid name, try:\n%s", USAGE);
		if (mlx.initialized == 1)
			mlx_loop(mlx.mlx);
	}
	else
		ft_printf("Invalid usage, try:\n%s", USAGE);
	return (0);
}
