/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:17:58 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:50:30 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_structure(t_data *data)
{
	data->win_ptr = NULL;
	data->img.img_wall = NULL;
	data->img.img_collect = NULL;
	data->img.img_exit = NULL;
	data->img.img_ground = NULL;
	data->img.img_player = NULL;
	data->mlx_ptr = NULL;
	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
}
