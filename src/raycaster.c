/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:33:49 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 19:44:44 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	destroy_win(t_all *pall)
{
	pall->key.flag_exit = 1;
	return (0);
}

void	raycast7(t_all *pall, int x)
{
	int	y;

	y = 0;
	while (y < pall->resol.h)
	{
		if (y >= pall->ceil_start && y < pall->ceil_finish)
			my_mlx_pix_put(pall, x, y, pall->color_c);
		if (y >= pall->wall_start && y < pall->wall_end)
		{
			if (pall->side == 1 && pall->mapY < pall->pl.pos_y)
				set_texture(pall, x, y, 0);
			if (pall->side == 1 && pall->mapY > pall->pl.pos_y)
				set_texture(pall, x, y, 1);
			if (pall->side == 0 && pall->mapX < pall->pl.pos_x)
				set_texture(pall, x, y, 2);
			if (pall->side == 0 && pall->mapX > pall->pl.pos_x)
				set_texture(pall, x, y, 3);
		}
		if (y >= pall->floor_start && y < pall->floor_end)
			my_mlx_pix_put(pall, x, y, pall->color_f);
		y++;
	}
}

void	raycast6(t_all *pall)
{
	if (pall->side == 0 && pall->mapX < pall->pl.pos_x)
		pall->text.texX = (pall->text.texX * pall->text.img_h[0]) / 100;
	if (pall->side == 0 && pall->mapX > pall->pl.pos_x)
		pall->text.texX = (pall->text.texX * pall->text.img_h[1]) / 100;
	if (pall->side == 1 && pall->mapY < pall->pl.pos_y)
		pall->text.texX = (pall->text.texX * pall->text.img_h[2]) / 100;
	if (pall->side == 1 && pall->mapY > pall->pl.pos_y)
		pall->text.texX = (pall->text.texX * pall->text.img_h[3]) / 100;
}

void	raycast5(t_all *pall)
{
	if (pall->side == 0)
		pall->perpWallDist = (pall->mapX - pall->pl.pos_x
				+ (1 - pall->stepX) / 2) / pall->rayDirX;
	else
		pall->perpWallDist = (pall->mapY - pall->pl.pos_y
				+ (1 - pall->stepY) / 2) / pall->rayDirY;
	if (pall->side == 0)
		pall->text.wallX = pall->pl.pos_y + pall->perpWallDist * pall->rayDirY;
	else
		pall->text.wallX = pall->pl.pos_x + pall->perpWallDist * pall->rayDirX;
	pall->text.texX = (pall->text.wallX * 100);
	pall->text.texX = pall->text.texX % 100;
	pall->lineh = (int)(pall->resol.h / pall->perpWallDist);
	pall->wall_start = -pall->lineh / 2 + pall->resol.h / 2;
	pall->wall_end = pall->lineh / 2 + pall->resol.h / 2;
	pall->ceil_start = 0;
	pall->ceil_finish = pall->wall_start;
	pall->floor_start = pall->wall_end;
	pall->floor_end = pall->resol.h;
}

void	raycast4(t_all *pall)
{
	while (pall->hit == 0)
	{
		if (pall->sDistX < pall->sDistY)
		{
			pall->sDistX += pall->dDistX;
			pall->mapX += pall->stepX;
			pall->side = 0;
		}
		else
		{
			pall->sDistY += pall->dDistY;
			pall->mapY += pall->stepY;
			pall->side = 1;
		}
		if (pall->map.map[pall->mapY][pall->mapX] == '1')
		{
			pall->hit = 1;
		}
	}
}
