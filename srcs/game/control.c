/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:27:12 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/19 11:53:59 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int key, t_game *game)
{
	if (key == XK_Escape || key == XK_q)
	{
		cleanup_and_exit(game, "Game closed by user", 0);
	}
	if (key == XK_w || key == XK_Up)
		move_player(game, 0, -1);
	else if (key == XK_s || key == XK_Down)
		move_player(game, 0, 1);
	else if (key == XK_a || key == XK_Left)
		move_player(game, -1, 0);
	else if (key == XK_d || key == XK_Right)
		move_player(game, 1, 0);
	return (0);
}

void	print_moves(t_game *game)
{
	ft_printf("Moves: %d\n", game->moves);
}
