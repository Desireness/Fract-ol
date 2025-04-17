/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:41:59 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/17 22:16:58 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//z = z^2 + c

void	complex_coords(int x, int y, t_complex_data *data, t_bounds *b)
{
	data->cr = b->left + x * ((b->right - b->left) / WIDTH);
	data->ci = b->top - y *((b->top - b->bottom)/ HEIGHT);
}
void mandelbrot_coords(t_data *img, t_bounds *bounds)
{
    int     x;
    int     y;
   // double  cr;
   // double  ci;
    t_complex_data data;
   // t_bounds bounds;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Calculamos las coordenadas complejas para cada píxel
            complex_coords(x, y, &data, bounds);

            // Llamamos a la función mandelbrot_iterations para obtener el número de iteraciones
            data.iter = mandelbrot_iterations(&data, MAX_ITER);
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

int	mandelbrot_iterations(t_complex_data *data, int max_iter)
{
	data->zr = START;
	data->zi = START;
	data->iter = 0;
	
	while (data->zr * data->zr + data->zi * data->zi <= 4 && data->iter < max_iter)
	{
		data->tmp = data->zr * data->zr - data->zi * data->zi + data->cr;
		data->zi = 2 * data->zr * data->zi + data->ci;
		data->zr = data->tmp;
		data->iter++;
	}
	return data->iter;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_bounds bounds;

	if (ac != 5)
	{
		write(2, "Usage: ./mandelbrot LEFT RIGHT TOP BOTTOM\n", 43);
		return (1);
	}
	bounds.left = ft_atof(av[1]);
	bounds.right = ft_atof(av[2]);
	bounds.top = ft_atof(av[3]);
	bounds.bottom = ft_atof(av[4]);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot set");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);

	mandelbrot_coords(&img, &bounds);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

