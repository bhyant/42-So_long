/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:34:51 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:37:00 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	exit_error(char *message)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	validate_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		exit_error("Usage: ./so_long <map.ber>");
		return (0);
	}
	if (!check_file_extension(argv[1]))
	{
		exit_error("Invalid file extension");
		return (0);
	}
	if (!check_file_access(argv[1]))
	{
		exit_error("File not accessible");
		return (0);
	}
	return (1);
}

t_map	*parse_and_validate(char *filename)
{
	t_map	*map;

	map = parse_map(filename);
	if (!map)
	{
		exit_error("Failed to parse map");
		return (NULL);
	}
	if (!validate_map(map))
	{
		cleanup_map(map);
		exit_error("Invalid map");
		return (NULL);
	}
	return (map);
}

t_game	*initialize_game(t_map *map)
{
	t_game	*game;

	game = init_game(map);
	if (!game)
	{
		cleanup_map(map);
		exit_error("Failed to initialize game");
		return (NULL);
	}
	if (!init_mlx(game))
	{
		cleanup_game(game);
		exit_error("Failed to initialize MLX");
		return (NULL);
	}
	return (game);
}
