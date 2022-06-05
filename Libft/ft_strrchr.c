/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:39:33 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:17:24 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptrs;
	char	ch;
	int		i;

	ptrs = (char *)s;
	ch = (char)c;
	i = 0;
	while (ptrs[i])
		i++;
	while (ptrs[i] != ch && i != 0)
		i--;
	if (ptrs[i] == ch)
		return (&ptrs[i]);
	return (NULL);
}
