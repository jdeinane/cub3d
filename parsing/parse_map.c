/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:04:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 21:38:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_map(t_cub3d *game, char *line)
{
	static char	**map_lines;
	static int	map_height;
	int			old_height;

	map_lines = NULL;
	map_height = 0;
	old_height = map_height;
	map_height++;
	map_lines = ft_realloc(map_lines, sizeof(char *) * old_height, \
					sizeof(char *) * (map_height + 1));
	if (!map_lines)
		error_exit(game, "Failed to allocate memory for map");
	map_lines[map_height - 1] = ft_strdup(line);
	if (!map_lines[map_height - 1])
	{
		free(map_lines);
		error_exit(game, "Failed to allocate memory for map line");
	}
	map_lines[map_height] = NULL;
	game->map = map_lines;
	game->map_height = map_height;
}
