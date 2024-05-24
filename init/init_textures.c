/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:31:20 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 21:37:43 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_textures(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (game->textures[i].img == NULL)
			error_exit(game, "Texture not loaded");
		game->textures[i].data = (int *)mlx_get_data_addr(game->\
						textures[i].img, \
						&game->textures[i].bpp, &game->textures[i].size_line, \
						&game->textures[i].endian);
		if (!game->textures[i].data)
			error_exit(game, "Failed to get texture data");
		i++;
	}
}
