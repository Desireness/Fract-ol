/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:36:30 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/10 12:51:15 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args)
{
	unsigned char	c;

	c = (char)va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	return (ft_putstr(str));
}

int	handle_pointer(va_list args)
{
	void	*ptr;
	int		len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	len = ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (len + 2);
}

int	handle_decimal(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num);
	return (ft_num_len(num));
}

int	handle_hexadecimal(unsigned int num, char specifier)
{
	int		count;
	char	*base;

	base = NULL;
	count = 0;
	if (specifier == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (specifier == 'X')
	{
		base = "0123456789ABCDEF";
	}
	count += ft_putnbr_base(num, base);
	return (count);
}
