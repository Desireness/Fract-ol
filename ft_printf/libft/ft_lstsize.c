/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:04:12 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/05 14:04:13 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = (*lst).next;
		count++;
	}
	return (count);
}
	//(*lst).next = next; next not defined, first used here
	//lst = lst->next;
	//(*lst).next = next; next not defined, first used here
	//lst = lst->next;
