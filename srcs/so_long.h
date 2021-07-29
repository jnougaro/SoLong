/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:02:55 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:53:49 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <sys/errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include <fcntl.h>

typedef struct s_img
{
	void	*img_wall;
	void	*img_ground;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit;
	int		player;
	int		collectible;
	char	**map;
	int		moves;
	t_img	img;
}	t_data;

void	ft_free_tab(char **tab);
void	init_structure(t_data *data);
void	init_struct_put_texture(t_data *data);
int		put_texture_window_resized(t_data *data);
void	put_texture_2(t_data *data, int y, int x, int resized);
void	put_texture_player(t_data *data, int y, int x, int resized);
void	put_texture_collectible(t_data *data, int y, int x, int resized);
void	put_texture_exit(t_data *data, int y, int x, int resized);
int		parse_map(t_data *data);
void	check_file_exist(int fd);
void	check_if_directory(void);
int		check_if_empty(void);
int		check_rectangle(t_data *data, int y, int len);
int		check_wall(t_data *data, int y, int x);
int		check_min_required(t_data *data);
int		check_characters(t_data *data, int y, int x);
int		check_file_extension(char *argv);
int		display_image(t_data *data);
void	ft_free_line(char *line);
int		count_map_line(char *argv);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	**create_map_tab(char *argv, t_data *data);
int		handle_cross(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	print_map(char **tab);
int		ft_put_texture(t_data *data);
void	init_img(t_data *data);
void	display_moves(t_data *data);
void	handle_player(int keysym, t_data *data);
void	handle_d(t_data *data);
void	handle_d_2(t_data *data);
void	handle_collectible_d(t_data *data);
void	handle_a(t_data *data);
void	handle_a_2(t_data *data);
void	handle_collectible_a(t_data *data);
void	handle_s(t_data *data);
void	handle_s_2(t_data *data);
void	handle_collectible_s(t_data *data);
void	handle_w(t_data *data);
void	handle_w_2(t_data *data);
void	handle_collectible_w(t_data *data);
void	handle_exit(t_data *data);
void	destroy_image(t_data *data);

#endif
