/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:21:25 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:45:28 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map->grid[y][x];
	put_tile(game, game->textures.floor, x, y);
	if (tile == WALL)
		put_tile(game, game->textures.wall, x, y);
	else if (tile == COLLECTIBLE)
		put_tile(game, game->textures.collectible, x, y);
	else if (tile == EXIT)
		put_tile(game, game->textures.exit, x, y);
	if (x == game->map->player_pos.x && y == game->map->player_pos.y)
		put_tile(game, game->textures.player, x, y);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

int	handle_close(t_game *game)
{
	cleanup_and_exit(game, "Game closed", 0);
	return (0);
}

int	handle_expose(t_game *game)
{
	render_game(game);
	return (0);
}
