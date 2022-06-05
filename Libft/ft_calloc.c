/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:53:46 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:42:42 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	n;
	void			*ptr;

	n = (count * size);
	ptr = (void *)malloc(n);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, n);
	return (ptr);
}
