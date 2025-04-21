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
// Añade esto a events.c
int handle_close(void *param)
{
    (void)param; // No necesitamos usar el parámetro
    printf("Cerrando ventana con X\n"); // Para depuración
    exit(0);
    return (0);
}
