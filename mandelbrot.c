/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:41:59 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/17 15:44:30 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//z = z^2 + c

void	complex_coords(int x, int y, double *cr, double *ci)
{
	*cr = LEFT + x * ((RIGHT - LEFT) / WIDTH);
	*ci = TOP - y *((TOP - BOTTOM) / HEIGHT);
}
void mandelbrot_coords(t_data *img)
{
    int     x;
    int     y;
    double  cr;
    double  ci;
    t_complex_data data;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Calculamos las coordenadas complejas para cada píxel
            complex_coords(x, y, &cr, &ci);

            // Llamamos a la función mandelbrot_iterations para obtener el número de iteraciones
            data.iter = mandelbrot_iterations(&data, cr, ci, MAX_ITER);
            int color;
            if (data.iter == MAX_ITER)
                color = 0x00000000;
            else
                color = 0x00ff8000;
            
            my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}

int	mandelbrot_iterations(t_complex_data *data,double cr,  double ci, int max_iter)
{
	data->zr = START;
	data->zi = START;
	data->iter = 0;
	
	while (data->zr * data->zr + data->zi * data->zi <= 4 && data->iter < max_iter)
	{
		data->tmp = data->zr * data->zr - data->zi * data->zi + cr;
		data->zi = 2 * data->zr * data->zi + ci;
		data->zr = data->tmp;
		data->iter++;
	}
	return data->iter;
}

int main()
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot set");

    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    mandelbrot_coords(&img);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // Dibujamos la imagen
    mlx_loop(mlx);
}

