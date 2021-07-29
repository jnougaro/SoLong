/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:55:57 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:50:51 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_data *data)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(data->map[y]);
	while (y != data->height)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			check_rectangle(data, y, len);
			check_characters(data, y, x);
			check_wall(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
