/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:46:59 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:28:15 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	j;
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char *)s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptrs[i] == j)
			return (&ptrs[i]);
		i++;
	}
	return (NULL);
}
