/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:00:08 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 18:22:44 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_words(char const *s, char c)
{
	size_t		i;
	size_t		w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static	char	**free_mem(char **res, size_t k)
{
	while (k >= 0)
	{
		free(res[k]);
		k--;
	}
	free(res);
	return (0);
}

static	char	**sub(char const *s, char c, char **res)
{
	size_t	j;
	size_t	start;
	size_t	len;
	size_t	k;

	k = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != c && s[j] != '\0')
		{
			start = j;
			len = 0;
			while (s[j] != c && s[j] != '\0' && ++len)
				j++;
			res[k++] = ft_substr(s, start, len);
			if (res[k++] == NULL)
				free_mem(res, k);
		}
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size_w;

	if (!s)
		return (NULL);
	size_w = size_words(s, c);
	res = malloc(sizeof(char *) * (size_w + 1));
	if (!res)
		return (NULL);
	sub(s, c, res);
	return (res);
}
