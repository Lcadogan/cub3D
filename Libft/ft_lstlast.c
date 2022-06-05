/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:33:05 by lcadogan          #+#    #+#             */
/*   Updated: 2021/02/07 19:14:08 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*a;

	if (lst == NULL)
		return (NULL);
	a = lst;
	while (a->next != NULL)
		a = a->next;
	return (a);
}
