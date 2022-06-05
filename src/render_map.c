/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:30:09 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/20 20:14:36 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycast3(t_all *pall)
{
	if (pall->rayDirX < 0)
	{
		pall->stepX = -1;
		pall->sDistX = (pall->pl.pos_x - pall->mapX) * pall->dDistX;
	}
	else
	{
		pall->stepX = 1;
		pall->sDistX = (pall->mapX + 1.0 - pall->pl.pos_x) * pall->dDistX;
	}
	if (pall->rayDirY < 0)
	{
		pall->stepY = -1;
		pall->sDistY = (pall->pl.pos_y - pall->mapY) * pall->dDistY;
	}
	else
	{
		pall->stepY = 1;
		pall->sDistY = (pall->mapY + 1.0 - pall->pl.pos_y) * pall->dDistY;
	}
	pall->hit = 0;
}

void	raycast2(t_all *pall, int x)
{
	pall->cameraX = 2 * x / (float)pall->resol.w - 1;
	pall->rayDirX = pall->pl.dir_x + pall->pl.pln_x * pall->cameraX;
	pall->rayDirY = pall->pl.dir_y + pall->pl.pln_y * pall->cameraX;
	pall->mapX = (int)pall->pl.pos_x;
	pall->mapY = (int)pall->pl.pos_y;
	pall->dDistX = fabsf(1 / pall->rayDirX);
	pall->dDistY = fabsf(1 / pall->rayDirY);
}

int	raycasting_map(t_all *pall)
{
	int	x;
	int	i;

	x = 0;
	while (x < pall->resol.w)
	{
		raycast2(pall, x);
		raycast3(pall);
		raycast4(pall);
		raycast5(pall);
		raycast6(pall);
		raycast7(pall, x);
		pall->ZBuffer[x] = pall->perpWallDist;
		x++;
	}
	i = 0;
	i = distance_sp(pall, i);
	sort_sps(pall);
	raycast_sp(pall, i);
	return (0);
}

int	render_next_frame(t_all *pall)
{
	key_control(pall);
	pall->img.img = mlx_new_image(pall->img.mlx, pall->resol.w, pall->resol.h);
	pall->img.addr = mlx_get_data_addr(pall->img.img, &pall->img.bits_per_pix,
			&pall->img.line_length, &pall->img.endian);
	raycasting_map(pall);
	if (pall->flag_save == 0)
	{	
		mlx_put_image_to_window(pall->img.mlx, pall->img.mlx_win,
			pall->img.img, 0, 0);
		mlx_destroy_image(pall->img.mlx, pall->img.img);
	}
	else
		ft_bitmap(pall);
	return (0);
}

int	render_map(t_all *pall)
{
	pall->img.mlx = mlx_init();
	if (pall->flag_save == 0)
		pall->img.mlx_win = mlx_new_window(pall->img.mlx, pall->resol.w,
				pall->resol.h, "Cub3D");
	al_mem_text(pall);
	check_param_sp(pall);
	if (pall->flag_save == 1)
		render_next_frame(pall);
	mlx_hook(pall->img.mlx_win, 2, 1L << 0, key_press, pall);
	mlx_hook(pall->img.mlx_win, 3, 1L << 0, key_release, pall);
	mlx_hook(pall->img.mlx_win, 17, 1L << 0, destroy_win, pall);
	mlx_loop_hook(pall->img.mlx, render_next_frame, pall);
	mlx_loop(pall->img.mlx);
	return (0);
}
