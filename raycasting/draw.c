/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:20:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/24 20:22:04 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_cub3d *game, int x, t_ray *ray)
{
	int	color;
	int	y;

	if (ray->side == 0)
		color = 0xFF0000;
	else
		color = 0x00FF00;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		game->img_data[y * game->win_width + x] = color;
		y++;
	}
}
