/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:04:37 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:48:15 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_image(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 64,
			data->height * 64, "My ACNH SoLong :)");
	if (data->win_ptr == NULL)
	{
		destroy_image(data);
		free(data->mlx_ptr);
		return (1);
	}
	init_img(data);
	ft_put_texture(data);
	if (check_min_required(data) == -1)
	{
		destroy_image(data);
		ft_free_tab(data->map);
		exit(0);
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &handle_cross, data);
	mlx_hook(data->win_ptr, 12, 1L << 15, &put_texture_window_resized, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
