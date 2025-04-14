/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:55:11 by rauizqui          #+#    #+#             */
/*   Updated: 2024/12/03 12:55:11 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*int main()
{
	const char str[] = "estoesuntest";
	char a = '4';
	char b = 'e';
	char c = 'l';
	char d = 'n';

	printf("%s\n", ft_strchr(str, a));
	printf("%s\n", ft_strchr(str, b));
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", ft_strchr(str, d));
}*/
