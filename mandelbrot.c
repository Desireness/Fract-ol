/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:41:59 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 14:12:55 by  rauizqui@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//z = z^2 + c-> conjunto de Mandelbrot
//Z = Z^m + C ->conjunto de Julia

void	complex_coords(int x, int y, t_complex_data *data, t_bounds *b)
{
	data->cr = b->left + x * ((b->right - b->left) / WIDTH);
	data->ci = b->top - y *((b->top - b->bottom)/ HEIGHT);
	///printf("Mapped zr: %f, zi: %f\n", data->zr, data->zi);
	
}

void mandelbrot_coords(t_data *img, t_bounds *bounds)
{
    int     x;
    int     y;
    t_complex_data data;
	//int iter;
	int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            complex_coords(x, y, &data, bounds);
            data.iter = mandelbrot_iterations(&data, MAX_ITER);
            if (data.iter == MAX_ITER)
                color = 0x00000000;
            else
                color = color_gradient(data.iter, MAX_ITER);
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

	if (ac <= 1 || ac < 5)
	{
		write(2, "Usage: ./fract-ol LEFT RIGHT TOP BOTTOM\n", 41);
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