/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:15:48 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 17:29:14 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_file(t_cub3d *game, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'N' && line [1] == 'O')
			parse_texture(game, line);
		else if (line[0] == 'S' && line[1] == 'O')
			parse_texture(game, line);
		else if (line[0] == 'W' && line[1] == 'E')
			parse_texture(game, line);
		else if (line[0] == 'E' && line[1] == 'A')
			parse_texture(game, line);
		else if (line[0] == 'F')
			parse_color(&game->floor_color, line);
		else if (line[0] == 'C')
			parse_color(&game->ceiling_color, line);
		else
			parse_map(game, line);
		free(line);
	}
	close(fd);
}
