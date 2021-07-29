/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:51:24 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:51:29 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture_2(t_data *data, int y, int x, int resized)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->img.img_wall, x * 64, y * 64);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->img.img_ground, x * 64, y * 64);
	else if (data->map[y][x] == 'C')
		put_texture_collectible(data, y, x, resized);
	else if (data->map[y][x] == 'E')
		put_texture_exit(data, y, x, resized);
	else if (data->map[y][x] == 'P')
		put_texture_player(data, y, x, resized);
}

void	put_texture_player(t_data *data, int y, int x, int resized)
{
	if (resized == 0)
		data->player += 1;
	data->player_x = x;
	data->player_y = y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.img_player, x * 64, y * 64);
}

void	put_texture_exit(t_data *data, int y, int x, int resized)
{	
	if (resized == 0)
		data->exit += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.img_exit, x * 64, y * 64);
}

void	put_texture_collectible(t_data *data, int y, int x, int resized)
{	
	if (resized == 0)
		data->collectible += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->img.img_collect, x * 64, y * 64);
}
