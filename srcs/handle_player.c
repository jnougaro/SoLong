/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:47:28 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:49:34 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_player(int keysym, t_data *data)
{
	if (keysym == 'd')
	{
		handle_d(data);
		handle_exit(data);
	}
	if (keysym == 'a')
	{
		handle_a(data);
		handle_exit(data);
	}
	if (keysym == 's')
	{
		handle_s(data);
		handle_exit(data);
	}
	if (keysym == 'w')
	{
		handle_w(data);
		handle_exit(data);
	}
}

void	handle_exit(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'E')
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		destroy_image(data);
		ft_free_tab(data->map);
		exit(0);
	}
}

void	display_moves(t_data *data)
{
	data->moves += 1;
	printf("[Moves : %d]\n", data->moves);
}	
