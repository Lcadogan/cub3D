/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:26:09 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/20 16:56:32 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_param_pl2(t_all *pall, int x, int y)
{
	if (pall->map.map[y][x] == 'W')
	{
		pall->pl.pln_x = 0;
		pall->pl.pln_y = -FOV;
		pall->pl.dir_x = -1;
		pall->pl.dir_y = 0;
	}
	if (pall->map.map[y][x] == 'E')
	{
		pall->pl.pln_x = 0;
		pall->pl.pln_y = FOV;
		pall->pl.dir_x = 1;
		pall->pl.dir_y = 0;
	}
}

int	check_param_pl(t_all *pall, int x, int y)
{
	pall->pl.pos_x = x + 0.5;
	pall->pl.pos_y = y + 0.5;
	if (pall->map.map[y][x] == 'N')
	{
		pall->pl.pln_x = FOV;
		pall->pl.pln_y = 0;
		pall->pl.dir_x = 0;
		pall->pl.dir_y = -1;
	}
	if (pall->map.map[y][x] == 'S')
	{
		pall->pl.pln_x = -FOV;
		pall->pl.pln_y = 0;
		pall->pl.dir_x = 0;
		pall->pl.dir_y = 1;
	}
	check_param_pl2(pall, x, y);
	return (0);
}

int	check_no_valid_char(t_all *pall, int y, int x)
{
	x = 0;
	while (pall->map.map[y][x])
	{
		if (pall->map.map[y][x] != ' ' && pall->map.map[y][x] != 'N'
			&& pall->map.map[y][x] != 'S' && pall->map.map[y][x] != 'W'
			&& pall->map.map[y][x] != 'E' && pall->map.map[y][x] != '2'
			&& pall->map.map[y][x] != '1' && pall->map.map[y][x] != '0')
			ft_errors(113);
		if (pall->map.map[y][x] == '2')
			pall->sp.num += 1;
		if (pall->map.map[y][x] == 'N' || pall->map.map[y][x] == 'S'
			|| pall->map.map[y][x] == 'W' || pall->map.map[y][x] == 'E')
		{
			if (pall->pl.flag_pl == 0)
			{
				pall->pl.flag_pl = 1;
				check_param_pl(pall, x, y);
			}
			else
				ft_errors(113);
		}
		x++;
	}
	return (0);
}

void	check_around_zero(t_all *pall, int i, int j)
{
	if (pall->last_y > i)
	{
		if (pall->map.map[++j][i] == ' ' || pall->map.map[j][i] == '\0')
			ft_errors(113);
	}
	else
		ft_errors(113);
	if (pall->map.map[j][--i] == ' ')
		ft_errors(113);
	if (pall->map.map[j][--i] == ' ')
		ft_errors(113);
}
