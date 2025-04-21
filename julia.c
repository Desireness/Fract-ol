/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:46:56 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 23:02:37 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void julia_complex_coords(int x, int y, t_complex_data *data, t_bounds *bounds)
{
    data->zr = bounds->left + ((double)x / WIDTH) * (bounds->right - bounds->left);
	data->zi = bounds->top - ((double)y / HEIGHT) * (bounds->top - bounds->bottom);
}

int julia_iterations(double zr, double zi, double cr, double ci)
{
    int iter;
    double tmp;

	iter = 0;
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
    int iter;
    int color;
    
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            julia_complex_coords(x, y, &data, bounds);
            iter = julia_iterations(data.zr, data.zi, julia->cr, julia->ci);
            if (iter == MAX_ITER)
                color = 0x000000; // Negro para puntos dentro del conjunto
            else
                color = color_gradient(iter, MAX_ITER);
            my_mlx_pixel_put(img, x, y, color);

            x++;
        }
        y++;
    }
}

/*int	main(int ac, char **av)
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

    //printf("Julia params: cr=%f, ci=%f\n", julia.cr, julia.ci);

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
}*/


/*int main(int ac, char **av)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_bounds bounds;
    t_complex_data julia;
    t_events *events;

    if (ac != 3)
    {
        write(2, "Usage: ./fract-ol <cr> <ci>\n", 29);
        return (1);
    }
    bounds.left = -1.5;
    bounds.right = 1.5;
    bounds.top = 1.5;
    bounds.bottom = -1.5;
    julia.cr = atof(av[1]);
    julia.ci = atof(av[2]);

    events = malloc(sizeof(t_events));
    if (!events)
        return (1);

    mlx = mlx_init();
    if (!mlx)
    {
        free(events);
        write(2, "Error initializing MLX\n", 23);
        return (1);
    }
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Julia Set");
    if (!mlx_win)
    {
        free(events);
        write(2, "Error creating window\n", 23);
        return (1);
    }
    
    // Inicializar events
    events->mlx = mlx;
    events->win = mlx_win;
    events->bounds = &bounds;
    events->img = &img;
    events->julia = julia;
    
    img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img.img)
    {
        free(events);
        write(2, "Error creating image\n", 22);
        return (1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    julia_coords(&img, &bounds, &julia);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    
    // Registrar eventos
    mlx_hook(mlx_win, 2, 1L<<0, handle_keypress, NULL);
    mlx_hook(mlx_win, 17, 0, handle_close, NULL);
    mlx_mouse_hook(mlx_win, handle_mouse_julia, events);
    
    mlx_loop(mlx);
    free(events);
    return (0);
}*/