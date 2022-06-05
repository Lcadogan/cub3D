/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:50:23 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 19:59:31 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_param_sp(t_all *pall)
{
	int	x;
	int	y;

	pall->ZBuffer = (float *)ft_calloc(pall->resol.w, sizeof(float));
	pall->sp.startX = (float *)ft_calloc(pall->sp.num, sizeof(float));
	pall->sp.startY = (float *)ft_calloc(pall->sp.num, sizeof(float));
	pall->sp.Order = (int *)ft_calloc(pall->sp.num, sizeof(int));
	pall->sp.Distance = (float *)ft_calloc(pall->sp.num, sizeof(float));
	pall->sp.num = 0;
	y = 0;
	while (pall->map.map[y])
	{
		x = 0;
		while (pall->map.map[y][x])
		{
			if (pall->map.map[y][x] == '2')
			{
				pall->sp.startX[pall->sp.num] = (float)x + 0.5;
				pall->sp.startY[pall->sp.num] = (float)y + 0.5;
				pall->sp.num +=1;
			}
			x++;
		}
		y++;
	}
}

void	sort_sps(t_all *pall)
{
	int		i;
	int		j;
	int		tmp_a;
	float	tmp_b;

	i = -1;
	tmp_a = 0;
	tmp_b = 0;
	while (++i < pall->sp.num)
	{
		j = 0;
		while (j < pall->sp.num - i - 1)
		{
			if (pall->sp.Distance[j] < pall->sp.Distance[j + 1])
			{
				tmp_a = pall->sp.Order[j + 1];
				pall->sp.Order[j + 1] = pall->sp.Order[j];
				pall->sp.Order[j] = tmp_a;
				tmp_b = pall->sp.Distance[j + 1];
				pall->sp.Distance[j + 1] = pall->sp.Distance[j];
				pall->sp.Distance[j] = tmp_b;
			}
			j++;
		}
	}
}

void	set_adr_text(t_all *pall)
{
	pall->text.ad_tex[0] = mlx_get_data_addr(pall->text.img[0],
			&pall->text.pix[0], &pall->text.line_length[0],
			&pall->text.endian[0]);
	pall->text.ad_tex[1] = mlx_get_data_addr(pall->text.img[1],
			&pall->text.pix[1], &pall->text.line_length[1],
			&pall->text.endian[1]);
	pall->text.ad_tex[2] = mlx_get_data_addr(pall->text.img[2],
			&pall->text.pix[2], &pall->text.line_length[2],
			&pall->text.endian[2]);
	pall->text.ad_tex[3] = mlx_get_data_addr(pall->text.img[3],
			&pall->text.pix[3], &pall->text.line_length[3],
			&pall->text.endian[3]);
	pall->text.ad_tex[4] = mlx_get_data_addr(pall->text.img[4],
			&pall->text.pix[4], &pall->text.line_length[4],
			&pall->text.endian[4]);
}
