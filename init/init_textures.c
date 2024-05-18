/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:31:20 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/18 18:32:29 by jubaldo          ###   ########.fr       */
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
			error_exit("Texture not loaded");
	}
}
