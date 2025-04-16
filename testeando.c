/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeando.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:16 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/16 16:48:34 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int *)dst = color;
//}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, int size)
{
	char	*dst;
	int	i;
	int	j;

	i = 0;
	while(i < size)
	{
		j = 0;
		while(j < size)
		{
			dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fract-ol");
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 1, 1, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 1, 2, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 2, 2, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 2, 1, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 3, 3, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 3, 4, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 4, 4, 0x00AF691A, 200);
	my_mlx_pixel_put(&img, 4, 3, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 9, 9, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 10, 10, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 11, 11, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 12, 12, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 13, 13, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 14, 14, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 15, 15, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 16, 16, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 17, 17, 0x00AF601A, 200);
	my_mlx_pixel_put(&img, 18, 18, 0x00AF601A, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_loop(mlx);
}
