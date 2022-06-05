/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:29:01 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:17:46 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		len_h;
	size_t		len_n;
	char		*phay;

	i = 0;
	phay = (char *)haystack;
	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	if (len_n == 0)
		return (phay);
	if (len_n == 0 && len_h == 0)
		return (NULL);
	if (len_n > len_h || len_n > len)
		return (NULL);
	while (i <= (len_h - len_n) && i <= (len - len_n))
	{
		if (phay[i] == needle[0])
			if (ft_memcmp(&phay[i], needle, len_n) == 0)
				return (&phay[i]);
		i++;
	}
	return (NULL);
}
