/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:23:56 by  rauizqui@s       #+#    #+#             */
/*   Updated: 2025/04/21 17:14:49 by  rauizqui@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//eventos mlx->zoom
//eventos mlx->teclado
int handle_keypress(int keycode, void *param)
{
    (void)param; // Evitar advertencias si no usamos el parámetro
    if (keycode == ESC_KEY)
        exit(0);
	//else if (keycode == EKIS)
//		exit (0);
    return (0);
}

/*int closeit(int keycode, t_events *events)
{
	//events = malloc(sizeof(t_events));
	//if (!events)
	//	return (1);
	void (keycode);
	handle_keypress(65307, events->win);
	mlx_destroy_window(events->mlx, events->win);
	return (0);
}*/

int handle_close(void *param)
{
    (void)param; // No necesitamos usar el parámetro
    printf("Cerrando ventana con X\n"); // Para depuración
    exit(0);
    return (0);
}
void zoom_at_point(t_bounds *bounds, int x, int y, double zoom_factor)
{
    t_complex_data data;
    double new_width, new_height;
    
    // Usar la función existente para convertir coordenadas de píxeles a complejas
    complex_coords(x, y, &data, bounds);
    
    // Calcular nuevos anchos basados en el factor de zoom
    new_width = (bounds->right - bounds->left) * zoom_factor;
    new_height = (bounds->top - bounds->bottom) * zoom_factor;
    
    // Actualizar límites centrados en el punto (data.cr, data.ci)
    bounds->left = data.cr - new_width / 2;
    bounds->right = data.cr + new_width / 2;
    bounds->top = data.ci + new_height / 2;
    bounds->bottom = data.ci - new_height / 2;
}

int handle_mouse(int button, int x, int y, void *param)
{
    t_events *events = (t_events *)param;
    t_bounds *bounds = events->bounds; // Añadiremos bounds a la estructura events
    t_data *img = events->img;         // Añadiremos img a la estructura events
    
    // Zoom in (rueda hacia arriba o botón 4)
    if (button == ZOOM_IN)
    {
        zoom_at_point(bounds, x, y, ZOOM_FACTOR);
        mandelbrot_coords(img, bounds);
        mlx_put_image_to_window(events->mlx, events->win, img->img, 0, 0);
    }
    
    // Zoom out (rueda hacia abajo o botón 5)
    if (button == ZOOM_OUT)
    {
        zoom_at_point(bounds, x, y, 1.0/ZOOM_FACTOR); // Inverso para zoom out
        mandelbrot_coords(img, bounds);
        mlx_put_image_to_window(events->mlx, events->win, img->img, 0, 0);
    }
    
    return (0);
}

int handle_mouse_julia(int button, int x, int y, void *param)
{
    t_events *events = (t_events *)param;
    t_bounds *bounds = events->bounds;
    t_data *img = events->img;
    t_complex_data *julia = &((t_events *)param)->julia; // Accede a los parámetros de Julia
    
    // Zoom in (rueda hacia arriba o botón 4)
    if (button == ZOOM_IN)
    {
        zoom_at_point(bounds, x, y, ZOOM_FACTOR);
        julia_coords(img, bounds, julia); // Ahora pasamos los 3 parámetros
        mlx_put_image_to_window(events->mlx, events->win, img->img, 0, 0);
    }
    
    // Zoom out (rueda hacia abajo o botón 5)
    if (button == ZOOM_OUT)
    {
        zoom_at_point(bounds, x, y, 1.0/ZOOM_FACTOR);
        julia_coords(img, bounds, julia); // Ahora pasamos los 3 parámetros
        mlx_put_image_to_window(events->mlx, events->win, img->img, 0, 0);
    }
    return (0);
}
