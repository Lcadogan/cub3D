/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:34:21 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:28:34 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	unsigned char	s;
	size_t			i;

	i = 0;
	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	s = c;
	while (n > i)
	{
		ptrd[i] = ptrs[i];
		if (ptrd[i] == s)
			return (&ptrd[i + 1]);
		i++;
	}
	return (NULL);
}
