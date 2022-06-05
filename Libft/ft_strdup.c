/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:42:30 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:20:52 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	size_t	n;

	n = ft_strlen(s1) + 1;
	ps1 = (char *)malloc(sizeof(char) * n);
	if (ps1 == NULL)
		return (NULL);
	ft_strlcpy(ps1, s1, n);
	return (ps1);
}
