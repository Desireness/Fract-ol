/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:10:59 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/08 11:27:00 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n == 0)
			return (1);
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_base_u(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbr_base_u(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}
