/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:43:41 by jnougaro          #+#    #+#             */
/*   Updated: 2021/07/29 10:55:23 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_exist(int fd)
{
	if (fd == -1)
	{
		printf("Error\n");
		printf("File doesn't exit\n");
		exit(0);
	}
}

void	check_if_directory(void)
{
	if (errno == EISDIR)
	{
		printf("Error\n");
		printf(".ber is a directory\n");
		exit(0);
	}
}

int	check_if_empty(void)
{
	printf("Error\n");
	printf("File is empty\n");
	exit(0);
	return (-1);
}	
