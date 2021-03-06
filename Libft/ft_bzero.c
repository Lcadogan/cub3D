/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:04:53 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/20 12:15:28 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	int				c;

	c = 0;
	ptr = s;
	while (n)
	{
		*ptr = c;
		ptr++;
		n--;
	}
}
