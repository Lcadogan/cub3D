/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:13:51 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:27:19 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;

	ptrd = (char *)dst;
	ptrs = (char *)src;
	if (ptrd == 0 && ptrs == 0)
		return (NULL);
	while (n--)
		*ptrd++ = *ptrs++;
	return (dst);
}
