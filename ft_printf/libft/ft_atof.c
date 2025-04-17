/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:01:11 by rauizqui          #+#    #+#             */
/*   Updated: 2025/04/17 21:12:14 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_get_decimal(const char *str, int *i)
{
	double	decimal;
	double	factor;

	decimal = 0.0;
	factor = 0.1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		decimal += (str[*i] - '0') * factor;
		factor *= 0.1;
		(*i)++;
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	n;

	i = 0;
	sign = 1;
	n = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		n += ft_get_decimal(str, &i);
	}
	return (sign * n);
}
