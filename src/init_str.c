/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:15:25 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/19 15:16:00 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_pall2(t_all *pall)
{
	pall->pl.flag_pl = 0;
	pall->pl.pos_x = 0;
	pall->pl.pos_y = 0;
	pall->pl.dir_x = 0;
	pall->pl.dir_y = 0;
	pall->pl.pln_x = 0;
	pall->pl.pln_y = 0;
	pall->map.map = NULL;
	pall->key.flag_up = 0;
	pall->key.flag_down = 0;
	pall->key.flag_left = 0;
	pall->key.flag_right = 0;
	pall->key.flag_ro_left = 0;
	pall->key.flag_ro_right = 0;
	pall->key.flag_exit = 0;
	pall->flag_save = 0;
}

void	init_pall(t_all *pall)
{
	pall->resol.h = -1;
	pall->resol.w = -1;
	pall->no_t = NULL;
	pall->so_t = NULL;
	pall->we_t = NULL;
	pall->ea_t = NULL;
	pall->sp_t = NULL;
	pall->f_col.R = -1;
	pall->f_col.G = -1;
	pall->f_col.B = -1;
	pall->c_col.R = -1;
	pall->c_col.G = -1;
	pall->c_col.B = -1;
	pall->num_char_x = -1;
	pall->num_char_y = -1;
	pall->sp.num = 0;
	pall->sig = 0;
	init_pall2(pall);
}
