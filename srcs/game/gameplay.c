/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:42:44 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 23:03:08 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->grid[y][x] == WALL)
		return (0);
	return (1);
}

void	collect_item(t_game *game, int x, int y)
{
	game->map->grid[y][x] = EMPTY;
	game->collected++;
}

int	check_win(t_game *game)
{
	return (game->collected == game->map->collectible_count);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map->player_pos.x + dx;
	new_y = game->map->player_pos.y + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		if (game->map->grid[new_y][new_x] == COLLECTIBLE)
			collect_item(game, new_x, new_y);
		game->map->player_pos.x = new_x;
		game->map->player_pos.y = new_y;
		game->moves++;
		print_moves(game);
		render_game(game);
		if (game->map->grid[new_y][new_x] == EXIT && check_win(game))
		{
			ft_printf("Congratulations! You won in %d moves!\n", game->moves);
			cleanup_and_exit(game, "Game completed successfully", 0);
		}
	}
}
