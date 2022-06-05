/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:18:17 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:26:39 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	if (ptrd == 0 && ptrs == 0)
		return (NULL);
	if (ptrs > ptrd)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			ptrd[len] = ptrs[len];
	return (dst);
}
