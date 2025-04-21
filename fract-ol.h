/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:47:22 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 13:58:39 by  rauizqui@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H



#define WIDTH 1092
#define HEIGHT 1080

#define LEFT -2.0
#define RIGHT 1.0
#define TOP 1.2
#define BOTTOM -1.2
#define MAX_ITER 100
#define START 0.0
#define COLOR 0x00FFA500

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
}	t_bounds;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int size);
void    draw_filled_square(t_data *img, int x_start, int y_start, int size, int color);


void    complex_coords(int x, int y, t_complex_data *data, t_bounds *b);
void mandelbrot_coords(t_data *img, t_bounds *bounds);
int     mandelbrot_iterations(t_complex_data *data, int max_iter);

int julia_iterations(double zr, double zi, double cr, double ci);
void	julia_coords(t_data *img, t_bounds *bounds, t_complex_data *julia);

int color_gradient(int iter, int max_iter);

#endif
