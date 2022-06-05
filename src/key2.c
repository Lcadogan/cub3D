/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:42:52 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 19:43:43 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_release(int key, t_all *pall)
{
	if (key == 13)
		pall->key.flag_up = 0;
	if (key == 1)
		pall->key.flag_down = 0;
	if (key == 0)
		pall->key.flag_left = 0;
	if (key == 2)
		pall->key.flag_right = 0;
	if (key == 123)
		pall->key.flag_ro_left = 0;
	if (key == 124)
		pall->key.flag_ro_right = 0;
	if (key == 53)
		pall->key.flag_exit = 0;
	return (0);
}

int	key_press(int key, t_all *pall)
{
	if (key == 13)
		pall->key.flag_up = 1;
	if (key == 1)
		pall->key.flag_down = 1;
	if (key == 0)
		pall->key.flag_left = 1;
	if (key == 2)
		pall->key.flag_right = 1;
	if (key == 123)
		pall->key.flag_ro_left = 1;
	if (key == 124)
		pall->key.flag_ro_right = 1;
	if (key == 53)
		pall->key.flag_exit = 1;
	return (0);
}
