/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:21:54 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/20 13:04:35 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len_s1;
	size_t		len_s2;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == 0 && s2 != 0)
	{
		res = ft_strdup(s2);
		return (res);
	}
	if (s2 == 0 && s1 != 0)
	{
		res = ft_strdup(s1);
		return (res);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcat(res, s2, len_s1 + len_s2 + 1);
	return (res);
}
