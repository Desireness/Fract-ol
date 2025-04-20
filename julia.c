/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:46:56 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/20 18:11:08 by  rauizqui@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void julia_complex_coords(int x, int y, t_complex_data *data, t_bounds *bounds) {
    data->zr = bounds->left + ((double)x / WIDTH) * (bounds->right - bounds->left);
	data->zi = bounds->top - ((double)y / HEIGHT) * (bounds->top - bounds->bottom);
}

int julia_iterations(double zr, double zi, double cr, double ci) {
    int iter = 0;
    double tmp;

    while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
        tmp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = tmp;
        iter++;
    }

    return iter;
}

void julia_coords(t_data *img, t_bounds *bounds, t_complex_data *julia)
{
    t_complex_data data;
    int y = 0;

    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            // Calcular las coordenadas complejas
            julia_complex_coords(x, y, &data, bounds);

            // Calcular el número de iteraciones
            int iter = julia_iterations(data.zr, data.zi, julia->cr, julia->ci);

            // Determinar el color basado en las iteraciones
            int color;
			if (iter == MAX_ITER)
				color = 0x000000; // Negro para puntos dentro del conjunto
			else if (iter > MAX_ITER * 0.75)
				color = 0xFF0000; // Rojo para puntos cercanos al borde
			else if (iter > MAX_ITER * 0.5)
				color = 0x00FF00; // Verde para puntos más alejados
			else if (iter > MAX_ITER * 0.25)
				color = 0x0000FF; // Azul para puntos aún más alejados
			else
				color = 0xFFFFFF; // Blanco para puntos muy alejados
            my_mlx_pixel_put(img, x, y, color);

            x++;
        }
        y++;
    }
}

int	main(int ac, char **av)
{
    void	*mlx;
    void	*mlx_win;
    t_data	img;
    t_bounds bounds;
    t_complex_data julia;

    if (ac != 3)
    {
        write(2, "Usage: ./fract-ol <cr> <ci>\n", 29);
        return (1);
    }
    bounds.left = -2.0;
    bounds.right = 2.0;
    bounds.top = 2.0;
    bounds.bottom = -2.0;
    julia.cr = atof(av[1]);
    julia.ci = atof(av[2]);

    printf("Julia params: cr=%f, ci=%f\n", julia.cr, julia.ci);

    mlx = mlx_init();
    if (!mlx)
    {
        write(2, "Error initializing MLX\n", 23);
        return (1);
    }
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Julia Set");
    if (!mlx_win)
    {
        write(2, "Error creating window\n", 23);
        return (1);
    }
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img.img)
    {
        write(2, "Error creating image\n", 22);
        return (1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    julia_coords(&img, &bounds, &julia);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    return (0);
}