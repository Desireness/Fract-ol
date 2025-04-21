/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rauizqui@student42.madrid.com <rauizqu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:10:44 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/21 13:58:25 by  rauizqui@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include "fract-ol.h"

int color_gradient(int iter, int max_iter)
{
    double t = (double)iter / max_iter;

    t = t * 9;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (r << 16 | g << 8 | b);
}

/*int color_gradient(int iter, int max_iter)
{
    // Si está dentro del conjunto, negro
    if (iter == max_iter)
        return (0x000000);
    
    double t = (double)iter / max_iter;
    
    // Ajustamos t para crear más variación de color
    t = t * 8.5; // 3.5 ciclos completos de color
    
    // Generamos valores base para RGB con desplazamiento de fase
    double base_r = sin(t * 3.14159);
    double base_g = sin(t * 3.14159 + 2.1);
    double base_b = sin(t * 3.14159 + 4.2);
    
    // Transformamos los valores de -1,1 a 0,1 y luego escalamos a 50-230
    // Esto evita colores demasiado oscuros o demasiado brillantes
    int r = (int)(50 + 180 * (base_r * 0.5 + 0.5));
    int g = (int)(50 + 180 * (base_g * 0.5 + 0.5));
    int b = (int)(50 + 200 * (base_b * 0.5 + 0.5));
    
    return (r << 16 | g << 8 | b);
}*/