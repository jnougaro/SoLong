/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:54:58 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:55:05 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(t_data *data, int y, int x)
{
	if (data->map[y][x] != '1'
			&& data->map[y][x] != '0' && data->map[y][x] != 'C'
			&& data->map[y][x] != 'P' && data->map[y][x] != 'E')
	{
		printf("Error\n");
		printf("Wrong character in map\n");
		destroy_image(data);
		ft_free_tab(data->map);
		exit(0);
	}
	return (0);
}

int	check_min_required(t_data *data)
{
	if (data->exit == 0 || data->collectible == 0 || data->player == 0)
	{
		printf("Error\n");
		printf("Map doesn't have at least 1E, 1C, or 1P\n");
		return (-1);
	}
	if (data->player > 1 || data->exit > 1)
	{
		printf("Error\n");
		printf("Map has more than 1P or 1E\n");
		return (-1);
	}
	return (0);
}

int	check_wall(t_data *data, int y, int x)
{
	if (y == 0 || x == 0 || y == data->height - 1 || x == data->width - 1)
	{
		if (data->map[y][x] != '1')
		{
			printf("Error\n");
			printf("Map doesn't have 4 walls\n");
			destroy_image(data);
			ft_free_tab(data->map);
			exit(0);
		}
	}
	return (0);
}

int	check_rectangle(t_data *data, int y, int len)
{
	if (ft_strlen(data->map[y]) != len)
	{
		printf("Error\n");
		printf("Map is not a rectangle\n");
		destroy_image(data);
		ft_free_tab(data->map);
		exit(0);
	}
	return (0);
}

int	check_file_extension(char *argv)
{
	if (ft_strcmp((argv + (ft_strlen(argv) - 4)), ".ber") != 0)
	{
		printf("Error\n");
		printf("Wrong file extension\n");
		return (-1);
	}
	return (0);
}
