/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:14:08 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 19:56:38 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parser_sp_t(char **map_f, t_all *pall, int x, int y)
{
	char	*str;

	str = NULL;
	while (map_f[y][x] == ' ' || map_f[y][x] == '\t' || map_f[y][x] == '\n')
	{
		if (map_f[y][x] == '\t')
			ft_errors(113);
		x++;
	}
	str = ft_strdup((const char *) &map_f[y][x]);
	pall->sp_t = ft_strtrim(str, " ");
	free (str);
	if ((open(pall->sp_t, O_RDONLY)) == -1)
		ft_errors(-1);
	return (0);
}

int	parser_ea_texture(char **map_f, t_all *pall, int x, int y)
{
	char	*str;

	str = NULL;
	while (map_f[y][x] == ' ' || map_f[y][x] == '\t' || map_f[y][x] == '\n')
	{
		if (map_f[y][x] == '\t')
			ft_errors(113);
		x++;
	}
	str = ft_strdup((const char *) &map_f[y][x]);
	pall->ea_t = ft_strtrim(str, " ");
	free (str);
	if ((open(pall->ea_t, O_RDONLY)) == -1)
		ft_errors(-1);
	return (0);
}

int	parser_we_texture(char **map_f, t_all *pall, int x, int y)
{
	char	*str;

	str = NULL;
	while (map_f[y][x] == ' ' || map_f[y][x] == '\t' || map_f[y][x] == '\n')
	{
		if (map_f[y][x] == '\t')
			ft_errors(113);
		x++;
	}
	str = ft_strdup((const char *) &map_f[y][x]);
	pall->we_t = ft_strtrim(str, " ");
	free (str);
	if ((open(pall->we_t, O_RDONLY)) == -1)
		ft_errors(-1);
	return (0);
}

int	parser_no_texture(char **map_f, t_all *pall, int x, int y)
{
	char	*str;

	str = NULL;
	while (map_f[y][x] == ' ' || map_f[y][x] == '\t' || map_f[y][x] == '\n')
	{
		if (map_f[y][x] == '\t')
			ft_errors(113);
		x++;
	}
	str = ft_strdup((const char *) &map_f[y][x]);
	pall->no_t = ft_strtrim(str, " ");
	free (str);
	if ((open(pall->no_t, O_RDONLY)) == -1)
		ft_errors(-1);
	return (0);
}

int	parser_so_texture(char **map_f, t_all *pall, int x, int y)
{
	char	*str;

	str = NULL;
	while (map_f[y][x] == ' ' || map_f[y][x] == '\t' || map_f[y][x] == '\n')
	{
		if (map_f[y][x] == '\t')
			ft_errors(113);
		x++;
	}
	str = ft_strdup((const char *) &map_f[y][x]);
	pall->so_t = ft_strtrim(str, " ");
	free (str);
	if ((open(pall->so_t, O_RDONLY)) == -1)
		ft_errors(-1);
	return (0);
}
