/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:17:04 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:50:14 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_s(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{	
		if (data->map[data->player_y + 1][data->player_x] != 'E')
		{
			if (data->map[data->player_y + 1][data->player_x] == 'C')
				handle_collectible_d(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->img.img_ground, data->player_x * 64, data->player_y * 64);
			data->map[data->player_y][data->player_x] = '0';
			data->player_y += 1;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->img.img_player, data->player_x * 64, data->player_y * 64);
			data->map[data->player_y][data->player_x] = 'P';
			display_moves(data);
		}
		else if (data->map[data->player_y + 1][data->player_x] == 'E'
				&& data->collectible == 0)
			handle_s_2(data);
	}
}

void	handle_collectible_s(t_data *data)
{
	data->collectible -= 1;
	data->map[data->player_y + 1][data->player_x] = '0';
}

void	handle_s_2(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.img_ground, data->player_x * 64, data->player_y * 64);
	data->player_y += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.img_player, data->player_x * 64, data->player_y * 64);
	display_moves(data);
}
