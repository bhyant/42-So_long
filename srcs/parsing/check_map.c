/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:38:46 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/10/16 16:17:05 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**read_file_lines(char *filename)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = malloc(sizeof(char *) * (MAX_HEIGHT + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (i < MAX_HEIGHT)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		lines[i] = line;
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

static int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

static int	init_grid(t_map *map, char **lines)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->grid[i] = ft_strdup(lines[i]);
		if (map->grid[i] == NULL)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

t_map	*create_map(char **lines)
{
	t_map	*map;

	if (!lines || !lines[0])
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = count_lines(lines);
	map->width = ft_strlen(lines[0]);
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	if (init_grid(map, lines) == EXIT_FAILURE)
		return (free(map), NULL);
	count_elements(map);
	find_positions(map);
	return (map);
}

t_map	*parse_map(char *filename)
{
	char	**lines;
	t_map	*map;
	int		i;

	lines = read_file_lines(filename);
	if (!lines)
		return (NULL);
	map = create_map(lines);
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (map);
}
