/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:51:35 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:21:08 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptrs;
	char	ch;

	ptrs = (char *)s;
	ch = (char)c;
	while (*ptrs != ch && *ptrs)
		ptrs++;
	if (*ptrs == ch)
		return (ptrs);
	return (NULL);
}
