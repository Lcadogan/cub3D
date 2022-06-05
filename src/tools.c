/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:19:07 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/22 17:51:26 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_full_str(t_all *pall)
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
		ft_errors(113);
	return (0);
}

void	make_color(t_all *pall)
{
	pall->color_c = pall->c_col.R << 16 | pall->c_col.G << 8
		| pall->c_col.B;
	pall->color_f = pall->f_col.R << 16 | pall->f_col.G << 8
		| pall->f_col.B;
}

void	ft_errors(int val)
{
	if (val == -1)
		perror("Error\nout");
	if (val == 12)
		printf("Error\n"__FILE__":%d -- %s\n", __LINE__, strerror(val));
	if (val == 107)
		printf("Error\nout:Bad map, no valid key.\n");
	if (val == 108)
		printf("Error\nout:Bad map, no valid resol.\n");
	if (val == 110)
		printf("Error\nout:Bad map, no valid color.\n");
	if (val == 111)
		printf("Error\nout:Bad map, out of data.\n");
	if (val == 112)
		printf("Error\nout: No file map.cub\n");
	if (val == 113)
		printf("Error\nout: No valid map\n");
	if (val == 114)
		printf("Error\nout: Invalid argument\n");
	if (val == 115)
		printf("Error\nout: Invalid texture file\n");
	if (val == 116)
		printf("Error\nout: File bitmap max resolution 5000 X 5000\n");
	exit(-1);
}

int	len_int(long int i)
{
	long int	tmp;

	tmp = 0;
	if (i == 0)
		tmp = 1;
	while (i != 0)
	{
		i = i / 10;
		tmp++;
	}
	return (tmp);
}

int	len_digit_color(char **map_f, int y, int x, int tmp)
{
	while (ft_isdigit(map_f[y][x]))
	{
		x++;
		if (tmp++ >= 3)
			ft_errors(109);
	}
	return (x);
}
