/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeando.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:16 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/16 22:39:19 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int size)
//{
//	char	*dst;
//	int	i;
//	int	j;
//
//	i = 0;
//	while(i < size)
//	{
//		j = 0;
//		while(j < size)
//		{
//			dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//			*(unsigned int *)dst = color;
//			j++;
//		}
//		i++;
//	}

void	draw_filled_square(t_data *img, int x_start, int y_start, int size, int color)
{
	int x;
	int y;

	y = 0;
	while(y < size)
	{
		x = 0;
		while(x < size)
		{
			my_mlx_pixel_put(img, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}

}

void	draw_filled_tr(t_data *img, int x_start, int y_start, int size, int color)
{
	int x;
	int y;
	int half_size;

	half_size = size / 2;
	y = 0;
	while (y < size)
	{
		// Calculamos el ancho de la línea en esta altura y
		// En un triángulo, el ancho en cada fila depende de qué tan abajo estamos
		int line_width = (size - y) * 2; // Decrece a medida que bajamos
		int start_x = half_size - (line_width / 2);
		
			x = 0;
			while (x < line_width)
			{
				my_mlx_pixel_put(img, x_start + start_x + x, y_start + y, color);
				x++;
			}
			y++;
		}
}
//zr-> parte real de Z
//zi-> parte imaginaria de Z
//tmp-> Variable temporal para guardar el valor de Z (zr)


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Fract-ol");
	img.img = mlx_new_image(mlx, 400, 400);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_filled_square(&img, 10, 10, 50, 0x00AF601A);
	draw_filled_tr(&img, 100, 100, 100, 0x00AF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_loop(mlx);
}
