/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:59:14 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/12 22:58:37 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define VISITED 'X'

# define MAX_WIDTH 40
# define MAX_HEIGHT 21
# define MIN_SIZE 3
# define TILE_SIZE 64

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	t_position	player_pos;
	t_position	exit_pos;
}				t_map;

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectible;
	void		*exit;
}				t_textures;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*window;
	t_textures	textures;
	int			moves;
	int			collected;
}				t_game;

int				check_file_extension(char *filename);
int				check_file_access(char *filename);
t_map			*parse_map(char *filename);
char			**read_file_lines(char *filename);
t_map			*create_map(char **lines);
void			count_elements(t_map *map);
void			find_positions(t_map *map);
int				validate_map(t_map *map);
int				check_format(t_map *map);
int				check_walls(t_map *map);
int				check_elements(t_map *map);
int				check_characters(t_map *map);
int				validate_path(t_map *map);
char			**copy_grid(t_map *map);
void			flood_fill(char **grid, int x, int y, int *count);
int				check_accessibility(t_map *map);
t_game			*init_game(t_map *map);
int				init_mlx(t_game *game);
int				load_textures(t_game *game);
void			setup_hooks(t_game *game);
int				handle_keypress(int key, t_game *game);
int				handle_close(t_game *game);
int				handle_expose(t_game *game);
void			move_player(t_game *game, int dx, int dy);
int				is_valid_move(t_game *game, int x, int y);
void			collect_item(t_game *game, int x, int y);
int				check_win(t_game *game);
void			render_game(t_game *game);
void			render_tile(t_game *game, int x, int y);
void			put_tile(t_game *game, void *img, int x, int y);
void			print_moves(t_game *game);
void			exit_error(char *message);
void			cleanup_game(t_game *game);
void			cleanup_map(t_map *map);
void			cleanup_textures(t_game *game);
void			free_grid(char **grid, int height);
void			cleanup_and_exit(t_game *game, char *message, int exit_code);
t_game			*initialize_game(t_map *map);
int				validate_arguments(int argc, char **argv);
t_map			*parse_and_validate(char *filename);
void			start_game(t_game *game);

#endif