/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:44:42 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/19 11:54:05 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->moves = 0;
	game->collected = 0;
	return (game);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->window = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (!game->window)
		return (0);
	if (!load_textures(game))
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &width, &height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &width, &height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"./assets/collectible.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&width, &height);
	if (!game->textures.wall || !game->textures.floor || !game->textures.player
		|| !game->textures.collectible || !game->textures.exit)
		return (0);
	return (1);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->window, 17, 1L << 17, handle_close, game);
	mlx_hook(game->window, 12, 1L << 15, handle_expose, game);
}

void	start_game(t_game *game)
{
	setup_hooks(game);
	render_game(game);
	mlx_loop(game->mlx);
}
