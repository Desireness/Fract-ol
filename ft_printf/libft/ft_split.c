/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:56:13 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:47 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	free_split(char **split, int i)
{
	while (i >= 0)
		free (split[i--]);
	free (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	split = malloc((n + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < n)
	{
		while (*s && *s == c)
			s++;
		split[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
		if (!split[i])
		{
			free_split (split, i - 1);
			return (NULL);
		}
		s += ft_strlen (split[i++]);
	}
	split[n] = NULL;
	return (split);
}
