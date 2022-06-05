/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:05:46 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 17:28:06 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_pars_key(t_all *pall)
{
	if (pall->resol.h != -1 && pall->resol.w != -1
		&& pall->no_t != NULL && pall->so_t != NULL
		&& pall->we_t != NULL && pall->ea_t != NULL
		&& pall->sp_t != NULL && pall->f_col.R != -1
		&& pall->f_col.G != -1 && pall->f_col.B != -1
		&& pall->c_col.R != -1 && pall->c_col.G != -1
		&& pall->c_col.B != -1)
	{
		return (0);
	}
	else
		return (-1);
}

int	check_key(char **map_f, t_all *pall, int x, int y)
{
	if (map_f[y][x] == 'R' && pall->resol.w == -1)
		parser_resol(map_f, pall, x++, y);
	else if (map_f[y][x] == 'N' && map_f[y][++x] == 'O' && pall->no_t == NULL)
		parser_no_texture(map_f, pall, ++x, y);
	else if (map_f[y][x] == 'S')
	{
		if (map_f[y][++x] == 'O' && pall->so_t == NULL)
			parser_so_texture(map_f, pall, ++x, y);
		else if (map_f[y][x] == ' ' && pall->sp_t == NULL)
			parser_sp_t(map_f, pall, ++x, y);
		else
			ft_errors(107);
	}
	else if (map_f[y][x] == 'W' && map_f[y][++x] == 'E' && pall->we_t == NULL)
		parser_we_texture(map_f, pall, ++x, y);
	else if (map_f[y][x] == 'E' && map_f[y][++x] == 'A' && pall->ea_t == NULL)
		parser_ea_texture(map_f, pall, ++x, y);
	else if (map_f[y][x] == 'F' && map_f[y][++x] == ' ' && pall->f_col.R == -1)
		parser_f_col(map_f, pall, x, y);
	else if (map_f[y][x] == 'C' && map_f[y][++x] == ' ' && pall->c_col.R == -1)
		parser_c_col(map_f, pall, x, y);
	else
		ft_errors(107);
	return (0);
}

int	check_valid_data2(char **map_f, t_all *pall, int x, int y)
{
	if (pall->flag == 0)
	{
		if ((check_key(map_f, pall, x, y)) != -1 && pall->flag == 0)
		{
			if (check_pars_key(pall) == 0)
				pall->flag = 1;
			return (0);
		}
	}
	if (pall->flag == 1)
	{
		make_color(pall);
		only_map(map_f, pall, y);
		check_valid_map(pall);
		pall->sig = 1;
	}
	else
		return (-1);
	return (0);
}

int	check_valid_data(char **map_f, t_all *pall)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	pall->flag = 0;
	while (map_f[y][x] && pall->sig == 0)
	{
		x = 0;
		while (map_f[y][x] && pall->sig == 0)
		{
			if (pall->flag == 0 && (map_f[y][x] == ' ' || map_f[y][x] == '\n'))
				x++;
			else
			{
				check_valid_data2(map_f, pall, x, y);
				break ;
			}
		}
		y++;
		while (map_f[y][x] == '\0' && pall->size - 1 > y)
			y++;
	}
	return (0);
}
