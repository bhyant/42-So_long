/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:39:58 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/16 13:07:01 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_format(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return (0);
	if (map->height < MIN_SIZE || map->width < MIN_SIZE)
		return (0);
	if (map->height > MAX_HEIGHT || map->width > MAX_WIDTH)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!map->grid[i] || (int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!check_format(map))
		return (ft_putstr_fd("Error : Map are too big", 2), 0);
	if (!check_characters(map))
		return (ft_putstr_fd("Error : Not reconized char in the map", 2), 0);
	if (!check_walls(map))
		return (ft_putstr_fd("Error : Map are not closed by Wall", 2), 0);
	if (!check_elements(map))
		return (0);
	if (!validate_path(map))
		return (ft_putstr_fd("Error : Exit are not reachable", 2), 0);
	return (1);
}
