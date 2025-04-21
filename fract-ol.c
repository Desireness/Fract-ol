/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:58:42 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 23:25:03 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_bounds(t_bounds *bounds, int fractal_type)
{
	if (fractal_type == 1)
	{
		bounds->left = -1.5;
		bounds->right = 1.5;
		bounds->top = 1.5;
		bounds->bottom = -1.5;
	}
	else
	{
		bounds->left = -2.0;
		bounds->right = 1.0;
		bounds->top = 1.2;
		bounds->bottom = -1.2;
	}
}

void	init_mlx_resources(t_events *events, char *title)
{
	events->mlx = mlx_init();
	if (!events->mlx)
		exit_with_error("Error initializing MLX", events);
	events->win = mlx_new_window(events->mlx, WIDTH, HEIGHT, title);
	if (!events->win)
		exit_with_error("Error creating window", events);
	events->img->img = mlx_new_image(events->mlx, WIDTH, HEIGHT);
	if (!events->img->img)
		exit_with_error("Error creating image", events);
	events->img->addr = mlx_get_data_addr(events->img->img,
			&events->img->bits_per_pixel, &events->img->line_length,
			&events->img->endian);
}

void	setup_hooks(t_events *events, int fractal_type)
{
	mlx_hook(events->win, 2, 1L << 0, handle_keypress, events);
	mlx_hook(events->win, 17, 0, handle_close, events);
	if (fractal_type == 1)
		mlx_mouse_hook(events->win, handle_mouse_julia, events);
	else
		mlx_mouse_hook(events->win, handle_mouse, events);
}

void	exit_with_error(char *message, t_events *events)
{
	if (events)
		free(events);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}

char	*get_title(int fractal_type)
{
	if (fractal_type == 1)
		return ("Julia Set");
	else
		return ("Mandelbrot Set");
}

int	main(int ac, char **av)
{
	t_data			img;
	t_bounds		bounds;
	t_complex_data	julia;
	t_events		*events;
	int				fractal_type;

	fractal_type = check_args(ac, av, &julia);
	events = malloc(sizeof(t_events));
	if (!events)
		return (1);
	events->img = &img;
	events->bounds = &bounds;
	init_bounds(&bounds, fractal_type);
	if (fractal_type == 1)
		events->julia = julia;
	init_mlx_resources(events, get_title(fractal_type));
	if (fractal_type == 1)
		julia_coords(&img, &bounds, &julia);
	else
		mandelbrot_coords(&img, &bounds);
	mlx_put_image_to_window(events->mlx, events->win, img.img, 0, 0);
	setup_hooks(events, fractal_type);
	mlx_loop(events->mlx);
	return (0);
}

int	check_args(int ac, char **av, t_complex_data *julia)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		return (0);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		julia->cr = atof(av[2]);
		julia->ci = atof(av[3]);
		return (1);
	}
	else
	{
		write(2, "Usage: ./fract-ol mandelbrot\n", 29);
		write(2, "   or: ./fract-ol julia <cr> <ci>\n", 34);
		exit(1);
	}
	return (0);
}
