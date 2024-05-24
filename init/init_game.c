/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:10:23 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 21:18:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_mlx(t_cub3d *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error initializing mlx");
}

static void	init_window(t_cub3d *game)
{
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		error_exit("Error creating window");
}

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

void	init_game(t_cub3d *game)
{
	init_mlx(game);
	init_window(game);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		error_exit("Error creating image");
	game->img_data = (int *)mlx_get_data_addr(game->img, &game->bpp, \
					&game->size_line, &game->endian);
	if (!game->img)
		error_exit("Error getting image data");
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	init_player(game);
	init_text(game);
	init_colors(game);
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	ft_memset(&game->keys, 0, sizeof(t_keys));
}
