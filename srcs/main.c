/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:23:36 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:50:41 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.moves = 0;
	init_structure(&data);
	if (argc == 2)
	{
		check_file_extension(argv[1]);
		data.map = create_map_tab(argv[1], &data);
		if (data.map == NULL)
			return (1);
		parse_map(&data);
		display_image(&data);
	}
	else
	{
		printf("Error\n");
		printf("Argument Error\n");
		return (1);
	}
	destroy_image(&data);
	ft_free_tab(data.map);
	exit(0);
	return (0);
}
