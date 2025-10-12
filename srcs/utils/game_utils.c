/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:38:09 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:38:20 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_elements(t_map *map)
{
	int	x;
	int	y;

	map->player_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
				map->player_count++;
			else if (map->grid[y][x] == EXIT)
				map->exit_count++;
			else if (map->grid[y][x] == COLLECTIBLE)
				map->collectible_count++;
			x++;
		}
		y++;
	}
}

void	find_positions(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == PLAYER)
			{
				map->player_pos.x = x;
				map->player_pos.y = y;
				map->grid[y][x] = EMPTY;
			}
			else if (map->grid[y][x] == EXIT)
			{
				map->exit_pos.x = x;
				map->exit_pos.y = y;
			}
			x++;
		}
		y++;
	}
}
