/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:21:45 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 21:35:33 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	free_images(t_cub3d *game)
{
	int	i;

	i = 0;
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	while (i < NUM_TEXTURES)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
}

static void	free_window(t_cub3d *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

void	free_map(t_cub3d *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->map_height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	free_resources(t_cub3d *game)
{
	int	i;

	i = 0;
	free_images(game);
	free_window(game);
	free_map(game);
}
