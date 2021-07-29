/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:45:34 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:54:57 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_line(char *line)
{
	if (line)
		free(line);
	check_if_empty();
}

int	count_map_line(char *argv)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (-1);
	while (ret > 0 && i++)
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (i == 1)
		return (check_if_empty());
	return (i);
}

void	ft_free_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		y++;
	}
	free(tab[y]);
	free(tab);
}

char	**create_map_tab(char *argv, t_data *data)
{
	char	**tab;
	char	*buffer;
	int		len;
	int		fd;
	int		ret;

	data->height = 1;
	buffer = NULL;
	fd = open(argv, O_RDONLY);
	check_file_exist(fd);
	if ((read(fd, buffer, 0)) == -1)
		check_if_directory();
	len = count_map_line(argv);
	if (len == -1)
		return (NULL);
	tab = malloc(sizeof(char *) * (len + 1));
	if (tab == NULL)
		return (NULL);
	ret = get_next_line(fd, &tab[0]);
	data->width = ft_strlen(tab[0]);
	while (ret > 0)
		ret = get_next_line(fd, &tab[data->height++]);
	tab[data->height] = NULL;
	close(fd);
	return (tab);
}
