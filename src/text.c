/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:47:04 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/18 19:48:53 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	read_text(t_all *pall)
{
	pall->text.img[0] = mlx_xpm_file_to_image(pall->img.mlx, pall->no_t,
			&pall->text.img_w[0], &pall->text.img_h[0]);
	if (pall->text.img[0] == NULL)
		ft_errors(115);
	pall->text.img[1] = mlx_xpm_file_to_image(pall->img.mlx,
			pall->so_t, &pall->text.img_w[1], &pall->text.img_h[1]);
	if (pall->text.img[1] == NULL)
		ft_errors(115);
	pall->text.img[2] = mlx_xpm_file_to_image(pall->img.mlx,
			pall->we_t, &pall->text.img_w[2], &pall->text.img_h[2]);
	if (pall->text.img[2] == NULL)
		ft_errors(115);
	pall->text.img[3] = mlx_xpm_file_to_image(pall->img.mlx,
			pall->ea_t, &pall->text.img_w[3], &pall->text.img_h[3]);
	if (pall->text.img[3] == NULL)
		ft_errors(115);
	pall->text.img[4] = mlx_xpm_file_to_image(pall->img.mlx,
			pall->sp_t, &pall->text.img_w[4], &pall->text.img_h[4]);
	if (pall->text.img[4] == NULL)
		ft_errors(115);
}

void	al_mem_text(t_all *pall)
{
	pall->text.img = (void **)ft_calloc(6, sizeof(void *));
	pall->text.ad_tex = (char **)ft_calloc(6, sizeof(char *));
	pall->text.pix = ft_calloc(6, sizeof(int));
	pall->text.line_length = ft_calloc(6, sizeof(int));
	pall->text.endian = ft_calloc(6, sizeof(int));
	pall->text.img_w = ft_calloc(6, sizeof(int));
	pall->text.img_h = ft_calloc(6, sizeof(int));
	read_text(pall);
	set_adr_text(pall);
}

void	my_mlx_text_put(t_all *pall, int x, int y, int num_text)
{
	char	*dst;
	char	*ptr;

	if (x > pall->resol.w || y > pall->resol.h || y < 0 || x < 0)
		return ;
	dst = pall->img.addr + (y * pall->img.line_length + x
			* (pall->img.bits_per_pix / 8));
	ptr = pall->text.ad_tex[num_text] + ((int)pall->text.texY
			* pall->text.line_length[num_text] + pall->text.texX
			* (pall->text.pix[num_text] / 8));
	if (num_text == 4 && *(unsigned int *) ptr == 0x0000000)
		return ;
	*(unsigned int *) dst = *(unsigned int *) ptr;
}

void	my_mlx_pix_put(t_all *pall, int x, int y, int color)
{
	char	*dst;

	dst = pall->img.addr + (y * pall->img.line_length + x
			* (pall->img.bits_per_pix / 8));
	*(unsigned int *) dst = color;
}

void	set_texture(t_all *pall, int x, int y, int num_text)
{
	int	startY;

	if (num_text == 4)
		startY = pall->sp.drawStartY;
	else
		startY = pall->wall_start;
	pall->coefficient = (float)pall->lineh / (float)pall->text.img_h[num_text];
	pall->text.texY = (float)(y - startY);
	pall->text.texY = pall->text.texY / pall->coefficient;
	if (pall->text.texY > pall->text.img_h[num_text])
		pall->text.texY = pall->text.img_h[num_text] - 1;
	if (y >= 0 && y < pall->resol.h)
		my_mlx_text_put(pall, x, y, num_text);
}
