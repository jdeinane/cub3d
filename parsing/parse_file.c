/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:15:48 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/27 17:58:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_file(t_cub3d *game, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Error: Error opening file");
	while (get_next_line(fd, &line) > 0)
	{
		if ((line[0] == 'N' && line[1] == 'O') \
		|| (line[0] == 'S' && line[1] == 'O') \
		|| (line[0] == 'W' && line[1] == 'E') \
		|| (line[0] == 'E' && line[1] == 'A'))
			parse_textures(game, line);
		else if (line[0] == 'F')
			parse_color(&game->floor_color, line);
		else if (line[0] == 'C')
			parse_color(&game->ceiling_color, line);
		else if (is_map_line(line))
			parse_map(game, line);
		else
			error_exit(game, "Error: Unexpected line format");
		free(line);
	}
	close(fd);
}
