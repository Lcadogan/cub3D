/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:00:09 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/20 13:05:44 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_bdata(t_all *pall, int fd)
{
	int		i;
	char	*img;

	i = pall->resol.h;
	img = pall->img.addr;
	while (--i)
		img += pall->img.line_length;
	while (i < pall->resol.h)
	{
		write(fd, img, pall->resol.w * 4);
		img -= pall->img.line_length;
		i++;
	}
}

void	ft_binfo(t_all *pall, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = pall->resol.w;
	header[4] = (unsigned char)(n);
	header[5] = (unsigned char)(n >> 8);
	header[6] = (unsigned char)(n >> 16);
	header[7] = (unsigned char)(n >> 24);
	n = pall->resol.h;
	header[8] = (unsigned char)(n);
	header[9] = (unsigned char)(n >> 8);
	header[10] = (unsigned char)(n >> 16);
	header[11] = (unsigned char)(n >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(t_all *pall, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = pall->resol.w * pall->resol.h * 4 + 54;
	header[2] = (unsigned char)(n);
	header[3] = (unsigned char)(n >> 8);
	header[4] = (unsigned char)(n >> 16);
	header[5] = (unsigned char)(n >> 24);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int	ft_bitmap(t_all *pall)
{
	int	fd;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(pall, fd);
	ft_binfo(pall, fd);
	ft_bdata(pall, fd);
	close(fd);
	exit(0);
}
