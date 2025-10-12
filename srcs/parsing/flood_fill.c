/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:54:16 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 18:54:31 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**copy_grid(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	flood_fill(char **grid, int x, int y, int *count)
{
	if (x < 0 || y < 0 || !grid[y] || !grid[y][x])
		return ;
	if (grid[y][x] == WALL || grid[y][x] == VISITED)
		return ;
	if (grid[y][x] == COLLECTIBLE)
		(*count)++;
	grid[y][x] = VISITED;
	flood_fill(grid, x + 1, y, count);
	flood_fill(grid, x - 1, y, count);
	flood_fill(grid, x, y + 1, count);
	flood_fill(grid, x, y - 1, count);
}

static int	check_exit_reachable(char **grid, t_map *map)
{
	int	x;
	int	y;

	x = map->exit_pos.x;
	y = map->exit_pos.y;
	if (x >= 0 && y >= 0 && x < map->width && y < map->height)
	{
		if (grid[y][x] == VISITED)
			return (1);
	}
	return (0);
}

int	check_accessibility(t_map *map)
{
	char	**grid_copy;
	int		collectibles_found;
	int		exit_reachable;

	grid_copy = copy_grid(map);
	if (!grid_copy)
		return (0);
	collectibles_found = 0;
	flood_fill(grid_copy, map->player_pos.x, map->player_pos.y,
		&collectibles_found);
	exit_reachable = check_exit_reachable(grid_copy, map);
	free_grid(grid_copy, map->height);
	return (collectibles_found == map->collectible_count && exit_reachable);
}

int	validate_path(t_map *map)
{
	return (check_accessibility(map));
}
