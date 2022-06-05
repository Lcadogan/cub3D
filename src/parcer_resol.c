/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_resol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:11:52 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 20:25:06 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	bitmap_resol(t_all *pall, int num)
{
	if (pall->flag == 1)
	{
		pall->resol.w = num;
		pall->flag = 0;
	}
	else
		pall->resol.h = num;
}

int	check_valid_rfc(char **map_f, char key, int x, int y)
{
	x = -1;
	while (map_f[y][++x])
	{
		if (key == 'R')
		{
			if (map_f[y][x] != key && map_f[y][x] != ' ' &&
				(!(map_f[y][x] >= '0' && map_f[y][x] <= '9')))
				ft_errors(108);
		}
		else
			if (map_f[y][x] != key && map_f[y][x] != ',' &&
				map_f[y][x] != ' ' && (!(map_f[y][x] >= '0' &&
				map_f[y][x] <= '9')))
				ft_errors(110);
	}
	return (0);
}

int	ft_pars_num(char *tmp)
{
	char	*res;
	int		j;
	int		i;
	int		num;

	num = 0;
	i = 0;
	j = 0;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		if (j < 4)
		{
			num = num * 10 + (tmp[i] - 48);
			i++;
		}
		else
			return (num);
		res = ft_itoa(num);
		j = ft_strlen(res);
		free(res);
	}
	return (num);
}

void	parser_resol2(t_all *pall, int num)
{
	if (pall->flag_save == 1)
		bitmap_resol(pall, num);
	else
	{
		if (pall->flag == 1)
		{
			mlx_get_screen_size(&pall->resol.w_max, &pall->resol.h_max);
			if (num > pall->resol.w_max)
				pall->resol.w = pall->resol.w_max;
			else
				pall->resol.w = num;
			pall->flag = 0;
		}
		else
		{
			if (num > pall->resol.h_max)
				pall->resol.h = pall->resol.h_max;
			else
				pall->resol.h = num;
		}
	}
}

int	parser_resol(char **map_f, t_all *pall, int x, int y)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	pall->flag = 1;
	check_valid_rfc(map_f, 'R', x, y);
	while (map_f[y][x])
	{
		if (map_f[y][x] >= '0' && map_f[y][x] <= '9')
		{
			if ((ft_isdigit(map_f[y][x])) == 1 && pall->resol.h != -1)
				ft_errors(108);
			num = ft_pars_num(&map_f[y][x]);
			if (num == -1)
				return (-1);
			while (map_f[y][x] >= '0' && map_f[y][x] <= '9')
				x++;
			parser_resol2(pall, num);
			i++;
		}
		x++;
	}
	return (0);
}
