/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:36:23 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 19:38:43 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	sprite_draw(t_all *pall)
{
	int	y;

	while (pall->sp.spr < pall->sp.drawEndX)
	{
		pall->text.texX = (int)((pall->sp.spr - (-pall->sp.w / 2
						+ pall->sp.ScreenX)) * pall->text.img_w[4]
				/ pall->sp.w);
		y = pall->sp.drawStartY;
		if (pall->sp.transformY > 0 && pall->sp.spr >= 0
			&& pall->sp.spr < pall->resol.w
			&& pall->sp.transformY < pall->ZBuffer[pall->sp.spr])
		{
			while (y < pall->sp.drawEndY)
			{
				pall->lineh = pall->sp.drawEndY - pall->sp.drawStartY;
				set_texture(pall, pall->sp.spr, y, 4);
				y++;
			}
		}
		pall->sp.spr ++;
	}
}

void	raycast_sp2(t_all *pall)
{
	pall->sp.drawStartY = -pall->sp.h / 2 + pall->resol.h / 2
		+ pall->sp.vMSc;
	pall->sp.drawEndY = pall->sp.h / 2 + pall->resol.h / 2
		+ pall->sp.vMSc;
	pall->sp.w = abs((int)(pall->resol.h / (pall->sp.transformY)));
	pall->sp.drawStartX = -pall->sp.w / 2 + pall->sp.ScreenX;
	pall->sp.drawEndX = pall->sp.w / 2 + pall->sp.ScreenX;
	pall->sp.spr = pall->sp.drawStartX;
}

void	raycast_sp(t_all *pall, int i)
{
	int	j;

	j = 0;
	while (j < pall->sp.num)
	{
		i = pall->sp.Order[j];
		pall->sp.X = pall->sp.startX[i] - pall->pl.pos_x;
		pall->sp.Y = pall->sp.startY[i] - pall->pl.pos_y;
		pall->sp.invDet = 1.0 / (pall->pl.pln_x * pall->pl.dir_y
				- pall->pl.dir_x * pall->pl.pln_y);
		pall->sp.transformX = pall->sp.invDet * (pall->pl.dir_y
				* pall->sp.X - pall->pl.dir_x * pall->sp.Y);
		pall->sp.transformY = pall->sp.invDet * (-pall->pl.pln_y
				* pall->sp.X + pall->pl.pln_x * pall->sp.Y);
		pall->sp.ScreenX = (int)((pall->resol.w / 2)
				* (1 + pall->sp.transformX / pall->sp.transformY));
		pall->sp.h = abs((int)(pall->resol.h / pall->sp.transformY));
		pall->sp.vMSc = (int)(VMOVE / pall->sp.transformY);
		raycast_sp2(pall);
		sprite_draw(pall);
		j++;
	}
}

int	distance_sp(t_all *pall, int i)
{
	i = 0;
	while (i < pall->sp.num)
	{
		pall->sp.Order[i] = i;
		pall->sp.Distance[i] = ((pall->pl.pos_x - pall->sp.startX[i])
				* (pall->pl.pos_x - pall->sp.startX[i])
				+ (pall->pl.pos_y - pall->sp.startY[i])
				* (pall->pl.pos_y - pall->sp.startY[i]));
		i++;
	}
	return (i);
}
