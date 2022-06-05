/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:02:57 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 11:01:38 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	make_map_f(t_list **head, t_all *pall, int size)
{
	char	**map_f;
	t_list	*tmp;
	int		i;

	pall->size = size;
	map_f = ft_calloc(size + 1, sizeof(char *));
	if (!map_f)
		ft_errors(12);
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map_f[++i] = tmp->content;
		tmp = tmp->next;
	}
	check_valid_data(map_f, pall);
	return (0);
}

int	open_map(t_all *pall, char *argv)
{
	int		res;
	int		fd;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_errors(-1);
	res = get_next_line(fd, &line);
	if (res == -1)
		ft_errors(113);
	ft_lstadd_back(&head, ft_lstnew(line));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map_f(&head, pall, ft_lstsize(head));
	check_full_str(pall);
	render_map(pall);
	return (0);
}

int	ft_check_name(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	while (i >= 0)
	{
		if (s1[i--] == s2[j--])
			;
		else
			return (-1);
	}
	return (0);
}

int	ft_check_save(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (i == j)
	{
		while (i >= 0)
		{
			if (s1[i--] == s2[j--])
				;
			else
				return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_pall(&all);
	if (argc == 3 && ft_check_name(".cub", argv[1]) == 0
		&& ft_check_save("--save", argv[2]) == 0)
	{
		all.flag_save = 1;
		open_map(&all, argv[1]);
	}
	if (argc == 2 && ft_check_name("cub3D", argv[0]) == 0
		&& ft_check_name(".cub", argv[1]) == 0)
		open_map(&all, argv[1]);
	else
		ft_errors(114);
	return (0);
}
