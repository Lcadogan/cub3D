/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:15:44 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 19:12:54 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_pars_num_col(t_all *pall, char *tmp)
{
	char	*res;
	int		j;
	int		i;
	int		num;

	num = 0;
	i = 0;
	pall->len = 0;
	j = 0;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		if (j < 3)
		{
			num = num * 10 + (tmp[i] - 48);
			i++;
			pall->len++;
		}
		else
			ft_errors(110);
		res = ft_itoa(num);
		j = ft_strlen(res);
		free(res);
	}
	return (num);
}

void	set_color(t_all *pall, int num, int i)
{
	if (pall->colf == 0)
	{
		if (i == 0)
			pall->c_col.R = num;
		else if (i == 1)
			pall->c_col.G = num;
		else if (i == 2)
			pall->c_col.B = num;
	}
	else
	{
		if (i == 0)
			pall->f_col.R = num;
		else if (i == 1)
			pall->f_col.G = num;
		else if (i == 2)
			pall->f_col.B = num;
	}
}

int	parser_c_col(char **map_f, t_all *pall, int x, int y)
{
	int	i;
	int	num;
	int	tmp;

	i = 0;
	pall->colf = 0;
	check_valid_rfc(map_f, 'C', x, y);
	while (map_f[y][x++])
	{
		if ((ft_isdigit(map_f[y][x])) == 1 && pall->c_col.B == -1)
		{
			tmp = 0;
			num = ft_pars_num_col(pall, &map_f[y][x]);
			if (num <= 255)
			{
				set_color(pall, num, i++);
				x += pall->len;
			}
			else
				ft_errors(110);
		}
		else if ((ft_isdigit(map_f[y][x])) == 1)
			ft_errors(110);
	}
	return (0);
}

int	parser_f_col(char **map_f, t_all *pall, int x, int y)
{
	int	i;
	int	num;
	int	tmp;

	i = 0;
	pall->colf = 1;
	check_valid_rfc(map_f, 'F', x, y);
	while (map_f[y][x++])
	{
		if ((ft_isdigit(map_f[y][x])) == 1 && pall->f_col.B == -1)
		{
			tmp = 0;
			num = ft_pars_num_col(pall, &map_f[y][x]);
			if (num <= 255)
			{
				set_color(pall, num, i++);
				x += pall->len;
			}
			else
				ft_errors(110);
		}
		else if ((ft_isdigit(map_f[y][x])) == 1)
			ft_errors(110);
	}
	return (0);
}
