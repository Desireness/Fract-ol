/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 00:23:40 by rauizqui          #+#    #+#             */
/*   Updated: 2025/03/09 17:35:23 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += handle_char(args);
	else if (specifier == 's')
		count += handle_string(args);
	else if (specifier == 'p')
		count += handle_pointer(args);
	else if (specifier == 'd' || specifier == 'i')
		count += handle_decimal(args);
	else if (specifier == 'u')
		count += handle_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += handle_hexadecimal(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_process_format(*format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
