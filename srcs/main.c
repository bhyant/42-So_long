/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:59:12 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:50:35 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (!validate_arguments(argc, argv))
		return (1);
	map = parse_and_validate(argv[1]);
	if (!map)
		return (1);
	game = initialize_game(map);
	if (!game)
		return (1);
	start_game(game);
	cleanup_game(game);
	return (0);
}
