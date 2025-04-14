/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:49:03 by rauizqui          #+#    #+#             */
/*   Updated: 2025/01/22 19:16:03 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	if (!dst && !src)
		return (NULL);
	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	if (dst_cpy < src_cpy)
	{
		while (n--)
			*dst_cpy++ = *src_cpy++;
	}
	else
	{
		dst_cpy += n - 1;
		src_cpy += n - 1;
		while (n--)
			*dst_cpy-- = *src_cpy--;
	}
	return (dst);
}
