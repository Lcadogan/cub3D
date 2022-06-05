/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:39:31 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 14:42:34 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	key_control_rotate_left(t_all *pall)
{
	if (pall->key.flag_ro_left == 1)
	{
		pall->oldDirX = pall->pl.dir_x;
		pall->pl.dir_x = pall->pl.dir_x * cos(-M_PI_10) - pall->pl.dir_y
			* sin(-M_PI_10);
		pall->pl.dir_y = pall->oldDirX * sin(-M_PI_10) + pall->pl.dir_y
			* cos(-M_PI_10);
		pall->oldPlaneX = pall->pl.pln_x;
		pall->pl.pln_x = pall->pl.pln_x * cos(-M_PI_10) - pall->pl.pln_y
			* sin(-M_PI_10);
		pall->pl.pln_y = pall->oldPlaneX * sin(-M_PI_10) + pall->pl.pln_y
			* cos(-M_PI_10);
	}
}

void	key_control_rotate_right(t_all *pall)
{
	if (pall->key.flag_ro_right == 1)
	{
		pall->oldDirX = pall->pl.dir_x;
		pall->pl.dir_x = pall->pl.dir_x * cos(M_PI_10) - pall->pl.dir_y
			* sin(M_PI_10);
		pall->pl.dir_y = pall->oldDirX * sin(M_PI_10) + pall->pl.dir_y
			*cos(M_PI_10);
		pall->oldPlaneX = pall->pl.pln_x;
		pall->pl.pln_x = pall->pl.pln_x * cos(M_PI_10) - pall->pl.pln_y
			* sin(M_PI_10);
		pall->pl.pln_y = pall->oldPlaneX * sin(M_PI_10) + pall->pl.pln_y
			* cos(M_PI_10);
	}
}

void	key_control_left_right(t_all *pall)
{
	if (pall->key.flag_left == 1)
	{
		if ((pall->map.map[(int)(pall->pl.pos_y)][(int)
			(pall->pl.pos_x - pall->pl.pln_x * STEP * 2)]) != '1')
			pall->pl.pos_x -= pall->pl.pln_x * STEP;
		if ((pall->map.map[(int)(pall->pl.pos_y - pall->pl.pln_y
					 * STEP * 2)][(int)(pall->pl.pos_x)]) != '1')
			pall->pl.pos_y -= pall->pl.pln_y * STEP;
	}
	if (pall->key.flag_right == 1)
	{
		if ((pall->map.map[(int)(pall->pl.pos_y)][(int)
			(pall->pl.pos_x + pall->pl.pln_x * STEP * 2)]) != '1')
			pall->pl.pos_x += pall->pl.pln_x * STEP;
		if ((pall->map.map[(int)(pall->pl.pos_y + pall->pl.pln_y
					* STEP * 2)][(int)(pall->pl.pos_x)]) != '1')
			pall->pl.pos_y += pall->pl.pln_y * STEP;
	}
}

void	key_control_up_down(t_all *pall)
{
	if (pall->key.flag_up == 1)
	{
		if ((pall->map.map[(int)(pall->pl.pos_y)][(int)
			(pall->pl.pos_x + pall->pl.dir_x * STEP * 2)]) != '1')
			pall->pl.pos_x += pall->pl.dir_x * STEP;
		if ((pall->map.map[(int)(pall->pl.pos_y + pall->pl.dir_y
					* STEP * 2)][(int) pall->pl.pos_x]) != '1')
			pall->pl.pos_y += pall->pl.dir_y * STEP;
	}
	if (pall->key.flag_down == 1)
	{
		if ((pall->map.map[(int)(pall->pl.pos_y)][(int)
			(pall->pl.pos_x - pall->pl.dir_x * STEP * 2)]) != '1')
			pall->pl.pos_x -= pall->pl.dir_x * STEP;
		if ((pall->map.map[(int)(pall->pl.pos_y - pall->pl.dir_y
					* STEP * 2)][(int) pall->pl.pos_x]) != '1')
			pall->pl.pos_y -= pall->pl.dir_y * STEP;
	}
}

int	key_control(t_all *pall)
{
	if (pall->key.flag_exit == 1)
		exit(0);
	key_control_up_down(pall);
	key_control_left_right(pall);
	key_control_rotate_right(pall);
	key_control_rotate_left(pall);
	return (0);
}
