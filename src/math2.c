/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:57:00 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/02 09:54:36 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.real = z.real * z.real - z.imaginary * z.imaginary;
	res.imaginary = 2 * z.real * z.imaginary;
	return (res);
}

t_complex	cube_complex(t_complex z)
{
	t_complex	res;

	res = (t_complex){z.real * z.real * z.real
		- 3 * z.real * z.imaginary * z.imaginary,
		3 * z.real * z.real * z.imaginary
		- z.imaginary * z.imaginary * z.imaginary};
	return (res);
}

t_complex	derivative(t_complex z)
{
	t_complex	res;

	res = square_complex(z);
	res = (t_complex){res.real * 3, res.imaginary * 3};
	return (res);
}

t_complex	sub_complex(t_complex a, t_complex b)
{
	return ((t_complex){a.real - b.real, a.imaginary - b.imaginary});
}

t_complex	divide_complex(t_complex a, t_complex b)
{
	t_complex	res;
	double		denom;

	if (b.real == 0 && b.imaginary == 0)
		return ((t_complex){0, 0});
	denom = b.real * b.real + b.imaginary * b.imaginary;
	res.real = (a.real * b.real + a.imaginary * b.imaginary) / denom;
	res.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denom;
	return (res);
}
