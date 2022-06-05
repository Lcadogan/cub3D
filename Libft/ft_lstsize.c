/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:38:44 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:28:52 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*a;
	int		i;

	if (lst)
	{
		a = lst;
		i = 0;
		while (a != NULL)
		{
			a = a->next;
			i++;
		}
		return (i);
	}
	return (0);
}
