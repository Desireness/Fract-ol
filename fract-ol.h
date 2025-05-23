/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:22 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 23:14:13 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H



#define WIDTH 800
#define HEIGHT 800

#define LEFT -2.0
#define RIGHT 1.0
#define TOP 1.2
#define BOTTOM -1.2
#define MAX_ITER 1001
#define START 0.0
#define COLOR 0x00FFA500
#define ESC_KEY 65307
//#define EKIS 17
#define ZOOM_IN 4
#define ZOOM_OUT 5
#define ZOOM_FACTOR 0.9

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct  s_data
{
    void    *img;
    char    *addr;
   // void    *mlx;
   // void    *win;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}       t_data;

typedef struct s_complex_data
{
    double zr;
    double zi;
    double ci;
    double cr;
    double tmp;
    int iter;
    int x;
    int y;
}   t_complex_data;

typedef struct s_bounds
{
	double	left;
	double	right;
	double	top;
	double	bottom;
    int     *bounds;
}	t_bounds;

typedef struct s_events
{
    void    *mlx;
    void    *win;
    t_bounds *bounds;
    t_data   *img;
    t_complex_data julia;
    char     *title;
}   t_events;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int size);
void    draw_filled_square(t_data *img, int x_start, int y_start, int size, int color);


void    complex_coords(int x, int y, t_complex_data *data, t_bounds *b);
void mandelbrot_coords(t_data *img, t_bounds *bounds);
int     mandelbrot_iterations(t_complex_data *data, int max_iter);

int julia_iterations(double zr, double zi, double cr, double ci);
void	julia_coords(t_data *img, t_bounds *bounds, t_complex_data *julia);

int color_gradient(int iter, int max_iter);
int closeit(int keycode, t_events *events);
//int handle_keypress(int keycode, t_events *events);
int handle_keypress(int keycode, void *param);
int handle_close(void *param);
void zoom_at_point(t_bounds *bounds, int x, int y, double zoom_factor);
int handle_mouse(int button, int x, int y, void *param);
int handle_mouse_julia(int button, int x, int y, void *param);

int		check_args(int ac, char **av, t_complex_data *julia);
void	exit_with_error(char *message, t_events *events);
void	init_bounds(t_bounds *bounds, int fractal_type);
void	init_mlx_resources(t_events *events, char *title);
void	setup_hooks(t_events *events, int fractal_type);
char    *get_title(int fractal_type);

#endif
