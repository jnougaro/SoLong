/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:16:12 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:49:23 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{	
		printf("%s\n", map[y]);
		y++;
	}
}

int	handle_cross(t_data *data)
{
	destroy_image(data);
	ft_free_tab(data->map);
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		destroy_image(data);
		ft_free_tab(data->map);
		exit(0);
	}
	handle_player(keysym, data);
	return (0);
}
