/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:24:38 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:51:14 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_texture(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	while (y != data->height)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			put_texture_2(data, y, x, 0);
			x++;
		}
		y++;
	}
	return (0);
}

int	put_texture_window_resized(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	while (y != data->height)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			put_texture_2(data, y, x, 1);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_img(t_data *data)
{
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, \
			"textures/Wall_Zelda.xpm", &data->img.width, &data->img.height);
	data->img.img_ground = mlx_xpm_file_to_image(data->mlx_ptr, \
			"textures/Ground_Zelda.xpm", &data->img.width, &data->img.height);
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, \
			"textures/Collect_Zelda.xpm", &data->img.width, &data->img.height);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, \
			"textures/Exit_Zelda.xpm", &data->img.width, &data->img.height);
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, \
			"textures/Player_Zelda.xpm", &data->img.width, &data->img.height);
	if (data->img.img_wall == NULL || data->img.img_ground == NULL
		|| data->img.img_collect == NULL || data->img.img_exit == NULL
		|| data->img.img_player == NULL)
		printf("Image reading has failed");
}
