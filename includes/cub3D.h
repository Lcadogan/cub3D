/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadogan <lcadogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:00:44 by lcadogan          #+#    #+#             */
/*   Updated: 2021/04/23 20:34:19 by lcadogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>

# define STEP		0.08
# define M_PI_10	0.0314159265
# define VMOVE		30
# define FOV		0.66

typedef struct s_resol
{
	int		w;
	int		h;
	int		w_max;
	int		h_max;

}				t_resol;

typedef struct s_color
{
	int		R;
	int		G;
	int		B;

}				t_color;

typedef struct s_map
{
	char	**map;

}				t_map;

typedef struct s_key
{
	int		flag_up;
	int		flag_down;
	int		flag_left;
	int		flag_right;
	int		flag_ro_left;
	int		flag_ro_right;
	int		flag_exit;

}				t_key;

typedef struct s_pl
{
	int			flag_pl;
	float		pos_x;
	float		pos_y;
	float		dir_y;
	float		dir_x;
	float		pln_x;
	float		pln_y;

}				t_pl;

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pix;
	int		line_length;
	int		endian;

}				t_data;

typedef struct s_text
{
	float	wallX;
	int		texX;
	float	texY;
	void	**img;
	int		*img_w;
	int		*img_h;
	int		*pix;
	char	**ad_tex;
	int		*line_length;
	int		*endian;

}				t_text;

typedef struct s_sprit
{
	int		num;
	int		*Order;
	float	*Distance;
	float	*startX;
	float	*startY;
	float	X;
	float	Y;
	float	invDet;
	float	transformX;
	float	transformY;
	int		ScreenX;
	int		h;
	int		w;
	int		vMSc;
	int		drawStartY;
	int		drawStartX;
	int		drawEndX;
	int		drawEndY;
	int		spr;

}				t_sp;

typedef struct s_all
{
	t_resol		resol;
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
	char		*sp_t;
	int			num_char_x;
	int			num_char_y;
	float		cameraX;
	float		rayDirX;
	float		rayDirY;
	float		oldDirX;
	float		oldPlaneX;
	int			mapX;
	int			mapY;
	float		dDistX;
	float		dDistY;
	int			stepX;
	int			stepY;
	float		sDistX;
	float		sDistY;
	int			hit;
	int			side;
	float		perpWallDist;
	int			lineh;
	int			ceil_start;
	int			ceil_finish;
	int			wall_start;
	int			wall_end;
	int			floor_start;
	int			floor_end;
	float		coefficient;
	int			color_f;
	int			color_c;
	float		*ZBuffer;
	int			flag_save;
	int			size;
	int			flag;
	int			colf;
	int			sig;
	int			first_y;
	int			last_y;
	int			num_map;
	int			len;
	t_sp		sp;
	t_text		text;
	t_data		img;
	t_pl		pl;
	t_color		f_col;
	t_color		c_col;
	t_map		map;
	t_key		key;
}					t_all;

int		make_map_f(t_list **head, t_all *pall, int size);
int		check_valid_data(char **map_f, t_all *pall);
int		check_valid_data2(char **map_f, t_all *pall, int x, int y);
int		check_key(char **map_f, t_all *pall, int x, int y);
int		check_valid_rfc(char **map_f, char key, int x, int y);
void	init_pall(t_all *pall);
int		ft_pars_num(char *tmp);
int		parser_resol(char **map_f, t_all *pall, int x, int y);
void	parser_resol2(t_all *pall, int num);
int		parser_no_texture(char **map_f, t_all *pall, int x, int y);
int		parser_so_texture(char **map_f, t_all *pall, int x, int y);
int		parser_we_texture(char **map_f, t_all *pall, int x, int y);
int		parser_ea_texture(char **map_f, t_all *pall, int x, int y);
int		parser_sp_t(char **map_f, t_all *pall, int x, int y);
int		parser_f_col(char **map_f, t_all *pall, int x, int y);
int		parser_c_col(char **map_f, t_all *pall, int x, int y);
void	set_color(t_all *pall, int num, int i);
int		len_int(long int i);
int		check_pars_key(t_all *pall);
void	ft_errors(int val);
int		main(int argc, char **argv);
int		check_valid_map(t_all *pall);
int		check_valid_map2(t_all *pall, int y, int x);
int		check_no_valid_char(t_all *pall, int y, int x);
int		check_zero(t_all *pall, int y, int x);
int		raycasting_map(t_all *pall);
void	raycast2(t_all *pall, int x);
void	raycast3(t_all *pall);
void	raycast4(t_all *pall);
void	raycast5(t_all *pall);
void	raycast6(t_all *pall);
void	raycast7(t_all *pall, int x);
int		key_control(t_all *pall);
void	key_control_up_down(t_all *pall);
void	key_control_left_right(t_all *pall);
void	key_control_rotate_right(t_all *pall);
void	key_control_rotate_left(t_all *pall);
int		key_press(int key, t_all *pall);
int		key_release(int key, t_all *pall);
int		destroy_win(t_all *pall);
int		only_map(char **map_f, t_all *pall, int y);
int		render_map(t_all *pall);
void	set_texture(t_all *pall, int x, int y, int num_text);
void	al_mem_text(t_all *pall);
void	my_mlx_text_put(t_all *pall, int x, int y, int num_text);
void	my_mlx_pix_put(t_all *pall, int x, int y, int color);
void	make_color(t_all *pall);
int		main(int argc, char **argv);
int		open_map(t_all *pall, char *argv);
int		ft_check_name(const char *s1, const char *s2);
int		ft_check_save(const char *s1, const char *s2);
void	init_pall(t_all *pall);
void	init_pall2(t_all *pall);
void	check_first_last_line(t_all *pall, int x, int y);
void	check_around_zero(t_all *pall, int i, int j);
int		check_param_pl(t_all *pall, int x, int y);
void	check_param_pl2(t_all *pall, int x, int y);
int		render_next_frame(t_all *pall);
int		distance_sp(t_all *pall, int i);
void	raycast_sp(t_all *pall, int i);
void	raycast_sp2(t_all *pall);
void	sprite_draw(t_all *pall);
void	read_text(t_all *pall);
void	set_adr_text(t_all *pall);
void	sort_sps(t_all *pall);
void	check_param_sp(t_all *pall);
int		ft_bitmap(t_all *pall);
void	ft_bfile(t_all *pall, int fd);
void	ft_binfo(t_all *pall, int fd);
void	ft_bdata(t_all *pall, int fd);
int		check_full_str(t_all *pall);
void	bitmap_resol(t_all *pall, int num);
int		ft_pars_num_col(t_all *pall, char *tmp);

#endif
