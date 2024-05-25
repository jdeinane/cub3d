/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:05:24 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/25 22:18:10 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_text(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->textures[i].img = NULL;
		game->textures[i].data = NULL;
		i++;
	}
}

static void	init_colors(t_cub3d *game)
{
	game->floor_color = (t_color){0, 0, 0};
	game->ceiling_color = (t_color){255, 255, 255};
}

void	init_cub3d(t_cub3d *game)
{
	int	i;

	i = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_data = NULL;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	init_text(game);
	init_colors(game);
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	ft_memset(&game->keys, 0, sizeof(t_keys));
	
}
