/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:50:16 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/28 02:06:17 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Window size
# define WIDTH 600
# define HEIGHT 600

// Colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define ALT_RED 0x7D0A0A
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define CYAN 0x00FFFF
# define YELLOW 0xFFD23F
# define PINK 0xEE4266
# define ORANGE 0xF94C10
# define PURPLE 0x5E1675

// Usage
# define USAGE "\t./fract-ol [mandelbrot/julia <real> <imaginary>\
/burningship/newton]\n"

// Keys
# define XK_PLUS 65451
# define XK_MINUS 65453

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_mlx
{
	char		*name;
	int			initialized;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			max_iter;
	double		zoom;
	double		escape_value;
	int			alt_color;
	int			color;
	int			*colors;
	double		tolerance;
	t_complex	*roots;
	int			roots_lenght;
	int			is_julia;
	int			is_newton;
	int			is_burningship;
	double		julia_real;
	double		julia_imaginary;
	double		shift_x;
	double		shift_y;
	double		mouse_x;
	double		mouse_y;
}			t_mlx;

// mandelbrot.c
void		mandelbrot(t_mlx *mlx, int flag);

// julia.c
double		scale_old(double x, double new_min, double new_max, double old_max);
void		julia(t_mlx *mlx, char *real, char *imaginary, int flag);
void		refresh_julia(t_mlx *mlx, double x, double y);

// burningship.c
void		check_pixel_burningship(t_mlx *mlx, int x, int y);
void		render_burningship(t_mlx *mlx);
void		burningship(t_mlx *mlx, int flag);

// newton.c
void		check_pixel_newton(t_mlx *mlx, int x, int y);
void		render_newton(t_mlx *mlx);
void		newton(t_mlx *mlx, int flag);

// free.c
void		free_mlx(t_mlx *mlx);
void		ft_mlx_error(t_mlx *mlx, char *msg);

// init.c
void		ft_mlx_init(t_mlx *mlx);
void		events_init(t_mlx *mlx);
void		ft_newton_init(t_mlx *mlx);
void		data_init(t_mlx *mlx);

// math.c
double		scale(double x, double zoom, double shift);
double		ft_atod(char *str);
double		dabs(double z);

// math2.c
t_complex	square_complex(t_complex z);
t_complex	cube_complex(t_complex z);
t_complex	derivative(t_complex z);
t_complex	sub_complex(t_complex a, t_complex b);
t_complex	divide_complex(t_complex a, t_complex b);

// render.c
void		check_pixel(t_mlx *mlx, int x, int y);
void		render(t_mlx *mlx);
void		handel_render(t_mlx *mlx);

// colorize.c
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int			colorize(t_mlx *mlx, int i);

// hook.c
int			key_press(int keycode, t_mlx *mlx);
void		handel_keypress(int keysym, t_mlx *mlx);
int			mouse_press(int button, int x, int y, t_mlx *mlx);
int			close_mlx(t_mlx *mlx);

#endif // FRACTOL_H
