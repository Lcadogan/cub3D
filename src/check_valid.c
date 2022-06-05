/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:22:12 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 20:24:35 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_zero(t_all *pall, int y, int x)
{
	int	i;
	int	j;

	i = x;
	j = y;
	pall->first_y = ft_strlen(pall->map.map[--y]);
	pall->last_y = ft_strlen(pall->map.map[2 + y]);
	if (pall->first_y > i)
	{
		if (pall->map.map[--j][++i] == ' ' || pall->map.map[j][i] == '\0')
			ft_errors(113);
	}
	else
		ft_errors(113);
	if (pall->map.map[j][--i] == ' ')
		ft_errors(113);
	if (pall->map.map[j][--i] == ' ')
		ft_errors(113);
	if (pall->map.map[++j][i] == ' ')
		ft_errors(113);
	i += 2;
	if (pall->map.map[j][i] == ' ' || pall->map.map[j][i] == '\0')
		ft_errors(113);
	check_around_zero(pall, i, j);
	return (0);
}

int	only_map(char **map_f, t_all *pall, int y)
{
	int	tmp;
	int	j;

	j = 0;
	tmp = 0;
	pall->num_map = 0;
	tmp = y;
	while (y < pall->size)
	{
		pall->num_map++;
		y++;
	}
	pall->map.map = ft_calloc(pall->num_map + 1, sizeof (char *));
	if (!(pall->map.map))
		ft_errors(12);
	y = tmp;
	while (y < pall->size)
	{
		pall->map.map[j] = ft_strdup(map_f[y]);
		j++;
		y++;
	}
	free (map_f);
	return (0);
}

void	check_first_last_line(t_all *pall, int x, int y)
{
	while (pall->map.map[y][x])
	{
		if (pall->map.map[y][x] != ' ' && pall->map.map[y][x] != '1')
			ft_errors(113);
		x++;
	}
}

int	check_valid_map2(t_all *pall, int y, int x)
{
	char	*psim;

	psim = "NSWE20";
	y = 0;
	while (pall->num_char_y - 1 > y)
	{
		x = 0;
		check_no_valid_char(pall, y, x);
		while (pall->map.map[y][x])
		{
			if (ft_strchr(psim, pall->map.map[y][x]))
			{
				check_zero(pall, y, x);
			}
			x++;
		}
		y++;
	}
	x = 0;
	check_first_last_line(pall, x, y);
	if (pall->pl.flag_pl == 0)
		ft_errors(113);
	return (0);
}

int	check_valid_map(t_all *pall)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	pall->num_char_x = ft_strlen(pall->map.map[y]);
	check_first_last_line(pall, x, y);
	x = 0;
	while (pall->num_map > y)
	{
		if (pall->map.map[y][x] != ' ' && pall->map.map[y][x] != '1')
			ft_errors(113);
		y++;
	}
	pall->num_char_y = y;
	check_valid_map2(pall, y, x);
	return (0);
}
