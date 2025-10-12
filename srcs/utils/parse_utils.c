/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:55:27 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:44:33 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != WALL)
			return (0);
		if (map->grid[map->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != WALL)
			return (0);
		if (map->grid[i][map->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_map *map)
{
	if (map->player_count != 1)
		return (0);
	if (map->exit_count != 1)
		return (0);
	if (map->collectible_count < 1)
		return (0);
	return (1);
}

int	check_characters(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] != WALL && map->grid[y][x] != EMPTY &&
				map->grid[y][x] != PLAYER && map->grid[y][x] != COLLECTIBLE &&
				map->grid[y][x] != EXIT)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_file_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	check_file_access(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
