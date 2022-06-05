/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:06:23 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:19:48 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	len;

	len = ft_strlen(src);
	d = 0;
	s = 0;
	while (dst[d] && d < dstsize)
		d++;
	while (src[s] && (d + s + 1) < dstsize)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d < dstsize)
		dst[d + s] = '\0';
	return (d + len);
}
